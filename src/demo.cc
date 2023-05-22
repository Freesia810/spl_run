#include "generator/TargetGenerator.h"
#include "AbstractSyntaxTree.h"
#include <llvm/IRReader/IRReader.h>
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

extern FILE *yyin;
extern int yyparse();
extern Program* syntax_root;
extern void Visualization(Program* p, const char* file_name);


int main(int argc,char *argv[]){

    yyin = fopen("test.spl","r");
    yyparse();

    Visualization(syntax_root, "test.json");



    // llvm::SMDiagnostic error;
    // llvm::LLVMContext context;
    // std::unique_ptr<llvm::Module> m = llvm::parseIRFile("../test.ll", error, context);

    // TargetGenerator generator(m.get(), "x86_64-linux-gnu", "generic-rv64", "");
    // generator.Init();

    // generator.GenerateBitcodeFile("a.bc");

    // generator.GenerateObjectFile("a");

    // generator.GenerateAssemblyFile("a.s");
    
    return 0;
}