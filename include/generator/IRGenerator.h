#pragma once

#include <llvm/IR/LLVMContext.h>
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
#include <fstream>
#include "AbstractSyntaxTree.h"
#include <deque>


class IRGenerator{
private:
    llvm::LLVMContext* _context{nullptr};
    llvm::Module* _module{nullptr};
    std::deque<llvm::Function*> _func_stack;
    llvm::IRBuilder<>* _builder;
public:
    void Init() { _builder = new llvm::IRBuilder<>(GetContext());}
    llvm::IRBuilder<>& GetBuilder() { return *_builder; }
    void PushFuncStack(llvm::Function* f) {_func_stack.push_back(f);};
    void PopFuncStack() { _func_stack.pop_back(); };
    llvm::LLVMContext& GetContext() { return *_context; };
    llvm::Module*& GetModulePt() { return _module; };
};