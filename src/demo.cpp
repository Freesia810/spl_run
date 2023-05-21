#include "TargetGenerator.h"
#include "AbstractSyntaxTree.h"
#include <llvm/IRReader/IRReader.h>
#include <memory>
#include <iostream>
#include <string>

#include <stdio.h>

extern FILE *yyin;
extern int yyparse();
extern Program* syntax_root;

int main(){
    yyin = fopen("test.spl","r");
    yyparse();


    printf("%ull", syntax_root->routine);


    // llvm::SMDiagnostic error;
    // llvm::LLVMContext context;
    // std::unique_ptr<llvm::Module> m = llvm::parseIRFile("../test.ll", error, context);

    // TargetGenerator generator(m.get(), "x86_64-linux-gnu", "generic-rv64", "");
    // generator.Init();

    // generator.GenerateBitcodeFile("a.bc");

    // generator.GenerateObjectFile("a");

    // generator.GenerateAssemblyFile("a.s");

    for(int i = 0; i < 10; i++){
        printf("%d", i);
    }

    return 0;
}