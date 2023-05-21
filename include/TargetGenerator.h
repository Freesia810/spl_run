#include <llvm/IR/LLVMContext.h>
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
#include <fstream>

class TargetGenerator{
private:
    llvm::Module* _module{nullptr};
    std::string _target_triple{};
    std::string _cpu{"generic"};
    std::string _feature{""};
    const llvm::Target* _target{nullptr};
    llvm::TargetMachine* _target_machine{nullptr};
public:
    TargetGenerator(llvm::Module* module_pt): _module(module_pt), _target_triple(llvm::sys::getDefaultTargetTriple()){};
    TargetGenerator(llvm::Module* module_pt, std::string target_triple): _module(module_pt), _target_triple(target_triple){};
    TargetGenerator(llvm::Module* module_pt, std::string target_triple, std::string CPU, std::string feature): _module(module_pt), _target_triple(target_triple), _cpu(CPU), _feature(feature){};
    
    void Init();

    void GenerateIRFile(const char* output_file);

    void GenerateBitcodeFile(const char* output_file);

    void GenerateAssemblyFile(const char* output_file);

    void GenerateObjectFile(const char* output_file);
    
    ~TargetGenerator(){ 
        if(_target_machine != nullptr){
            delete _target_machine;
        }
    };
};