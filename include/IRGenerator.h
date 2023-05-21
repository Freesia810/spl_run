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

class IRGenerator{
private:
    
};