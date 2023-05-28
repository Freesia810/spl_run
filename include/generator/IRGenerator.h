#pragma once

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/PassManager.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/MC/MCContext.h>
#include <llvm/MC/MCStreamer.h>
#include <llvm/CodeGen/AsmPrinter.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/CodeGen/MachineModuleInfo.h>
#include <llvm/Support/raw_ostream.h>
#include <iostream>
#include <llvm/ADT/APFloat.h>
#include <fstream>
#include <deque>

enum Sys_Type{
    SYS_BOOLEAN,
    SYS_CHAR,
    SYS_INTEGER,
    SYS_REAL
};

enum Compound_Type{
    SPL_SINGLE,
    SPL_ARRAY,
    SPL_RECORD
};

struct CompoundContext{
    Compound_Type type;
    CompoundContext(Compound_Type t): type(type){};
};

struct SingleContext: public CompoundContext{
    Sys_Type single_type;
    SingleContext(): CompoundContext(Compound_Type::SPL_SINGLE){};
};

struct ArrayContext: public CompoundContext{
    std::pair<int64_t, int64_t> range;
    CompoundContext* element_context;
    ArrayContext(): CompoundContext(Compound_Type::SPL_ARRAY){};
};

struct RecordContext: public CompoundContext{
    std::unordered_map<std::string, uint64_t> field_map;
    std::unordered_map<std::string, CompoundContext*> context_map;
    RecordContext(): CompoundContext(Compound_Type::SPL_RECORD){};
};

struct CallContext {
    struct ParamInfo
    {
        std::string para_name;
        llvm::Type* para_llvm_type;
        CompoundContext* para_cxt;
        ParamInfo(std::string s, llvm::Type* t, CompoundContext* c): para_name(s), para_llvm_type(t), para_cxt(c){};
    };
    
    std::vector<ParamInfo*> params_context;
    std::pair<llvm::Type*, CompoundContext*> ret_context;
};


class IRGenerator{
private:
    llvm::LLVMContext* _context{nullptr};
    llvm::Module* _module{nullptr};
    
    std::deque<llvm::Function*> _func_stack;

    std::unordered_map<std::string, std::pair<llvm::Type*, CompoundContext*>> _global_type_map;
    std::deque<std::unordered_map<std::string, std::pair<llvm::Type*, CompoundContext*>>> _local_type_map;
    std::unordered_map<std::string, std::pair<llvm::Type*, CompoundContext*>> _global_var_map;
    std::deque<std::unordered_map<std::string, std::pair<llvm::Type*, CompoundContext*>>> _local_var_map;
    std::unordered_map<std::string, CallContext*> _call_map;
    std::unordered_map<std::string, llvm::BasicBlock*> _block_map;

    llvm::Function* print;
    llvm::Function* scan;
    llvm::IRBuilder<>* _builder;

    llvm::Function* makePrintf() {
        std::vector<llvm::Type*> arg_types;
        arg_types.push_back(GetBuilder().getInt8PtrTy());
        auto printf_type = llvm::FunctionType::get(GetBuilder().getInt32Ty(), llvm::makeArrayRef(arg_types), true);
        auto func = llvm::Function::Create(printf_type, llvm::Function::ExternalLinkage, llvm::Twine("printf"), GetModulePt());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }

    llvm::Function* makeScanf() {
        auto scanf_type = llvm::FunctionType::get(GetBuilder().getInt32Ty(), true);
        auto func = llvm::Function::Create(scanf_type, llvm::Function::ExternalLinkage, llvm::Twine("scanf"), GetModulePt());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }


public:
    void Init() { 
        _context = new llvm::LLVMContext(); 
        _builder = new llvm::IRBuilder<>(GetContext()); 
    };

    void AfterModule(){
        this->print = makePrintf(); 
        this->scan = makeScanf(); 
    }
    
    llvm::IRBuilder<>& GetBuilder() { return *_builder; }
    
    void PushFuncStack(llvm::Function* f) {
        _func_stack.push_back(f); 
        _local_type_map.push_back(std::unordered_map<std::string, std::pair<llvm::Type*, CompoundContext*>>()); 
        _local_var_map.push_back(std::unordered_map<std::string, std::pair<llvm::Type*, CompoundContext*>>());
    };
    
    void PopFuncStack() { _func_stack.pop_back(); _local_type_map.pop_back(); _local_var_map.pop_back(); };
    
    llvm::Function* GetCurrentFunction(){ return _func_stack.back(); }
    
    llvm::BasicBlock* FindLabel(std::string label) { 
        auto iter = _block_map.find(label); 
        if(iter == _block_map.end()) 
            return nullptr; 
        return iter->second; 
    };
    CallContext* FindCallContext(const char* call_name);
    std::pair<llvm::Type*, CompoundContext*> FindVarContext(const char* var_name);
    std::pair<llvm::Type*, CompoundContext*> FindTypeContext(const char* type_name);
    llvm::Value* FindSymbolValue(const char* symbol);
    
    void AddLabel(std::string label, llvm::BasicBlock* block) { _block_map.insert({label, block}); };
    void AddTypeDef(std::string type_name, llvm::Type* type, CompoundContext* cc, bool global);
    void AddVarDef(std::string var_name, llvm::Type* type, CompoundContext* cc, bool global);
    void AddCallDef(std::string call_name, CallContext* cc);
    
    llvm::LLVMContext& GetContext() { return *_context; };
    
    llvm::Module*& GetModulePt() { return _module; };
    
    llvm::Function* GetPrintf() {
        return this->print;
    }

    llvm::Function* GetScanf() {
        return this->scan;
    }

    llvm::Constant* GetDefaultValue(llvm::Type* this_type);
};