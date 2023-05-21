#include "TargetGenerator.h"

void TargetGenerator::Init()
{
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string Error;
    _target = llvm::TargetRegistry::lookupTarget(_target_triple, Error);

    llvm::TargetOptions topt;
    _target_machine = _target->createTargetMachine(_target_triple, _cpu, _feature, topt, llvm::Optional<llvm::Reloc::Model>());
    
    _module->setDataLayout(_target_machine->createDataLayout());
    _module->setTargetTriple(_target_triple);
}

void TargetGenerator::GenerateIRFile(const char* output_file){
    //create ll file
    std::error_code ec;
    llvm::raw_fd_ostream output(output_file, ec, llvm::sys::fs::OF_None);

    if (ec) {
        std::cerr << "Could not open file: " << ec.message();
        return;
    }
    _module->print(output, nullptr);
}

void TargetGenerator::GenerateBitcodeFile(const char* output_file){
    std::error_code ec;
    llvm::raw_fd_ostream output(output_file, ec, llvm::sys::fs::OF_None);

    if (ec) {
        std::cerr << "Could not open file: " << ec.message();
        return;
    }

    llvm::WriteBitcodeToFile(*_module, output);
}

void TargetGenerator::GenerateAssemblyFile(const char* output_file){
    //create asm
    llvm::legacy::PassManager pass;
    llvm::CodeGenFileType type = llvm::CGFT_AssemblyFile;
    llvm::SmallVector<char, 0> buffer;
    llvm::raw_svector_ostream so(buffer);
    
    if (_target_machine->addPassesToEmitFile(pass, so, nullptr, type)) {
        return;
    }

    pass.run(*_module);
    std::ofstream os(output_file);
    for(auto& c: buffer){
        os << c;
    }

    os.close();
}

void TargetGenerator::GenerateObjectFile(const char* output_file){
    //create obj
    std::error_code ec;
    llvm::raw_fd_ostream output(output_file, ec, llvm::sys::fs::OF_None);

    if (ec) {
        std::cerr << "Could not open file: " << ec.message();
        return;
    }

    llvm::legacy::PassManager pass;
    llvm::CodeGenFileType type = llvm::CGFT_ObjectFile;

    if (_target_machine->addPassesToEmitFile(pass, output, nullptr, type)) {
        return;
    }

    pass.run(*_module);
    output.flush();
    output.close();
}
