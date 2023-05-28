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

    IRGenerator generator;
    generator.Init();
    syntax_root->generateIR(&generator);

    auto m = generator.GetModulePt();

    std::error_code ec;
    llvm::raw_fd_ostream output("test.ll", ec, llvm::sys::fs::OF_None);

    if (ec) {
        std::cerr << "Could not open file: " << ec.message();
    }
    m->print(output, nullptr);

    TargetGenerator t_generator(m);
    t_generator.Init();

    t_generator.GenerateBitcodeFile("a.bc");

    t_generator.GenerateObjectFile("a.o");

    t_generator.GenerateAssemblyFile("a.s");
    
    return 0;
}