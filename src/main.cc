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
    if(argc <= 1){
        std::cout << "SPL-RUN Help:\n./spl-run -arg1 -arg2 ... file1 file2 ... [target-triple] [outputs_dir]\n";
        return 0;
    }
    std::vector<std::string> input_files;
    std::string target_triple = "";
    std::string output = ".";
    int mode = 0;
    char arg_flag = 0;

    for(int i = 1; i < argc; i++){
        switch (argv[i][0])
        {
        case '-':
            if(mode == 0){
                std::string arg = argv[i];

                if(arg == "-ll"){
                    arg_flag = (arg_flag | 1);
                }
                else if(arg == "-bc"){
                    arg_flag = (arg_flag | 2);
                }
                else if(arg == "-s"){
                    arg_flag = (arg_flag | 4);
                }
                else if(arg == "-o"){
                    arg_flag = (arg_flag | 8);
                }
                else if(arg == "-json"){
                    arg_flag = (arg_flag | 16);
                }
                else{
                    std::cout << "SPL-RUN: arg not found.\n";
                    return 0;
                }
            }
            else if(mode == 1){
                std::string target = argv[i];
                if(target.substr(0, 9) == "--target="){
                    target_triple = target.substr(9);
                }
                else if(target.substr(0, 9) == "--output="){
                    output = target.substr(9);
                }
                else{
                    std::cout << "SPL-RUN: arg not found.\n";
                    return 0;
                }
                mode = 2;
            }
            else{
                std::cout << "SPL-RUN: arg not found.\n";
                return 0;
            }
            break;
        default:
            if(mode == 0){
                mode = 1;
            }
            if(mode == 1){
                input_files.push_back(argv[i]);
            }
            else if(mode == 2){
                output = argv[i];
            }
            break;
        }
    }

    if(arg_flag == 0){
        arg_flag = 31;
    }

    for(auto file: input_files){
        yyin = fopen(file.c_str(),"r");
        yyparse();

        IRGenerator generator;
        generator.Init();
        syntax_root->generateIR(&generator);
        auto m = generator.GetModulePt();

        std::unique_ptr<TargetGenerator> t_generator;
        if(target_triple == ""){
            t_generator = std::make_unique<TargetGenerator>(m);
        }
        else{
            t_generator = std::make_unique<TargetGenerator>(m, target_triple);
        }
        t_generator->Init();

        auto filename = file.substr(0, file.find_last_of('.'));

        if(arg_flag & 16){
            Visualization(syntax_root, (output + "/" + filename + ".json").c_str());
        }

        if(arg_flag & 1){
            std::error_code ec;
            llvm::raw_fd_ostream os((output + "/" + filename + ".ll").c_str(), ec, llvm::sys::fs::OF_None);

            if (ec) {
                std::cerr << "Could not open file: " << ec.message();
            }
            m->print(os, nullptr);
        }

        if(arg_flag & 2){
            t_generator->GenerateBitcodeFile((output + "/" + filename + ".bc").c_str());
        }

        if(arg_flag & 4){
            t_generator->GenerateAssemblyFile((output + "/" + filename + ".s").c_str());
        }

        if(arg_flag & 8){
            t_generator->GenerateObjectFile((output + "/" + filename + ".o").c_str());
        }
    }
    
    return 0;
}