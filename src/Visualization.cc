#include "AbstractSyntaxTree.h"
#include "generator/TargetGenerator.h"
#include "AbstractSyntaxTree.h"
#include <llvm/IRReader/IRReader.h>
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "cJSON.h"

void Visualization(Program* p, const char* file_name){
    auto obj = p->createJSONObj();
    std::ofstream os(file_name);
    os << cJSON_Print(obj);
    os.close();
    cJSON_Delete(obj);
}