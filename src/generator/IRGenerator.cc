#include "generator/IRGenerator.h"

CallContext* IRGenerator::FindCallContext(const char* call_name){
    //global
    auto gb_iter = _call_map.find(call_name);
    if(gb_iter != _call_map.end()){
        return gb_iter->second;
    }

    PrintError("Undeclared Symbol: ", call_name);
    return nullptr;
}

std::pair<llvm::Type*, CompoundContext*> IRGenerator::FindVarContext(const char* var_name){
    for(auto iter = _local_var_map.crbegin(); iter != _local_var_map.crend(); iter++){
        auto& this_map = *iter;
        auto this_iter = this_map.find(var_name);
        if(this_iter != this_map.end()){
            return this_iter->second;
        }
    }

    //global
    auto gb_iter = _global_var_map.find(var_name);
    if(gb_iter != _global_var_map.end()){
        return gb_iter->second;
    }

    //not found, throw todo
    PrintError("Undeclared Symbol: ", var_name);
    return std::pair<llvm::Type*, CompoundContext*>();
}

std::pair<llvm::Type*, CompoundContext*> IRGenerator::FindTypeContext(const char* type_name){
    for(auto iter = _local_type_map.crbegin(); iter != _local_type_map.crend(); iter++){
        auto& this_map = *iter;
        auto this_iter = this_map.find(type_name);
        if(this_iter != this_map.end()){
            return this_iter->second;
        }
    }

    //global
    auto gb_iter = _global_type_map.find(type_name);
    if(gb_iter != _global_type_map.end()){
        return gb_iter->second;
    }

    //not found, throw todo
    PrintError("Undeclared Symbol: ", type_name);
    return std::pair<llvm::Type*, CompoundContext*>();
}

llvm::Value* IRGenerator::FindSymbolValue(const char* symbol){
    for(auto iter = _func_stack.crbegin(); iter != _func_stack.crend(); iter++){
        auto v = (*iter)->getValueSymbolTable()->lookup(symbol);
        if(v != nullptr){
            return v;
        }
    }

    auto v = _module->getGlobalVariable(symbol);
    if(v != nullptr){
        return v;
    }

    //throw todo
    PrintError("Undeclared Symbol: ", symbol);
    return nullptr;
}

void IRGenerator::AddTypeDef(std::string type_name, llvm::Type* type, CompoundContext* cc, bool global){
    if(global)
        this->_global_type_map.insert({type_name, {type, cc}});
    else
        this->_local_type_map.back().insert({type_name, {type, cc}});
}

void IRGenerator::AddVarDef(std::string var_name, llvm::Type* type, CompoundContext* cc, bool global){
    if(global)
        this->_global_var_map.insert({var_name, {type, cc}});
    else
        this->_local_var_map.back().insert({var_name, {type, cc}});
}

void IRGenerator::AddCallDef(std::string call_name, CallContext* cc){
    this->_call_map.insert({call_name, cc});
}

llvm::Constant* IRGenerator::GetDefaultValue(llvm::Type* this_type){
    switch (this_type->getTypeID())
    {
    case llvm::Type::IntegerTyID:
        if(this_type->isIntegerTy(32))
            return GetBuilder().getInt32(0);
        if(this_type->isIntegerTy(8))
            return GetBuilder().getInt8(0);
        if(this_type->isIntegerTy(1))
            return GetBuilder().getInt1(0);
        else
            return nullptr;
        break;
    case llvm::Type::DoubleTyID:
        return llvm::ConstantFP::get(GetBuilder().getDoubleTy(), 0);
        break;
    case llvm::Type::ArrayTyID:
        {
            std::vector<llvm::Constant*> element;
            for(size_t i = 0; i < this_type->getArrayNumElements(); i++){
                element.push_back(GetDefaultValue(this_type->getArrayElementType()));
            }
            return llvm::ConstantArray::get(llvm::dyn_cast<llvm::ArrayType>(this_type), element);
        }
        break;
    case llvm::Type::StructTyID:
        {
            std::vector<llvm::Constant*> element;
            for(size_t i = 0; i < this_type->getStructNumElements(); i++){
                element.push_back(GetDefaultValue(this_type->getStructElementType(i)));
            }
            return llvm::ConstantStruct::get(llvm::dyn_cast<llvm::StructType>(this_type), element);
        }
        break;
    default:
        return nullptr;
        break;
    }
}
