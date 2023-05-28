#include "AbstractSyntaxTree.h"
#include "cJSON.h"
#include <string>
#include "generator/IRGenerator.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

cJSON* Program::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Program");
    cJSON_AddItemToObject(this->this_obj, "id_node", this->program_id->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "routine_node", this->routine->createJSONObj());
    return this->this_obj;
}

cJSON* ProgramId::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Program Id");
    cJSON_AddStringToObject(this->this_obj, "node_description", this->id);
    return this->this_obj;
}

cJSON* Routine::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Routine");
    cJSON_AddItemToObject(this->this_obj, "routine_head_node", this->routine_head->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "routine_body_node", this->routine_body->createJSONObj());
    return this->this_obj;
}

cJSON* RoutineHead::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "RoutineHead");

    if(this->const_part != nullptr)
        TraversalItem<ConstExprssion>(this->this_obj, this->const_part, "const_expr_list");
    if(this->type_part != nullptr)
        TraversalItem<TypeDefinition>(this->this_obj, this->type_part, "type_def_list");
    if(this->var_part != nullptr)
        TraversalItem<NormalDecl>(this->this_obj, this->var_part, "var_decl_list");
    if(this->routine_part != nullptr)
        TraversalItem<CallDecl>(this->this_obj, this->routine_part, "call_decl_list");

    return this->this_obj;
}

cJSON* ConstExprssion::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ConstExprssion");
    cJSON_AddItemToObject(this->this_obj, "name_node", this->name->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "value_node", this->value->createJSONObj());
    return this->this_obj;
}

cJSON* Identifier::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Identifier");
    cJSON_AddStringToObject(this->this_obj, "id", this->buffer);
    return this->this_obj;
}

cJSON* ConstValue::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ConstValue");
    switch (this->flag)
    {
    case INT:
        cJSON_AddNumberToObject(this->this_obj, "int_value", this->value.int_value);
        break;
    case REAL:
        cJSON_AddNumberToObject(this->this_obj, "real_value", this->value.real_value);
        break;
    case CHAR:
        cJSON_AddStringToObject(this->this_obj, "char_value", std::to_string(this->value.char_value).c_str());
        break;
    case SYS_CON:
        switch (this->value.sys_con_value)
        {
        case Sys_Con::FALSE:
            cJSON_AddStringToObject(this->this_obj, "sys_value", "FALSE");
            break;
        case Sys_Con::TRUE:
            cJSON_AddStringToObject(this->this_obj, "sys_value", "TRUE");
            break;
        case Sys_Con::MAXINT:
            cJSON_AddStringToObject(this->this_obj, "sys_value", "MAXINT");
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return this->this_obj;
}

cJSON* TypeDefinition::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "TypeDefinition");

    cJSON_AddItemToObject(this->this_obj, "name_node", this->name->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "value_node", this->value->createJSONObj());

    return this->this_obj;
}

cJSON* TypeDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "TypeDecl");

    switch (this->flag)
    {
    case TypeDecl::SIMPLE:
        cJSON_AddItemToObject(this->this_obj, "simple_decl_node", this->decl.simple_decl->createJSONObj());
        break;
    case TypeDecl::ARRAY:
        cJSON_AddItemToObject(this->this_obj, "array_decl_node", this->decl.array_decl->createJSONObj());
        break;
    case TypeDecl::RECORD:
        cJSON_AddItemToObject(this->this_obj, "record_decl_node", this->decl.record_decl->createJSONObj());
        break;
    default:
        break;
    }
    return this->this_obj;
}

cJSON* SimpleTypeDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "SimpleTypeDecl");

    switch (this->flag)
    {
    case SimpleTypeDecl::SYS_TYPE:
        switch (this->type_decl.sys_type_decl)
        {
        case Sys_Type::SYS_BOOLEAN:
            cJSON_AddStringToObject(this->this_obj, "decl_type", "sys_boolean");
            break;
        case Sys_Type::SYS_CHAR:
            cJSON_AddStringToObject(this->this_obj, "decl_type", "sys_char");
            break;
        case Sys_Type::SYS_INTEGER:
            cJSON_AddStringToObject(this->this_obj, "decl_type", "sys_integer");
            break;
        case Sys_Type::SYS_REAL:
            cJSON_AddStringToObject(this->this_obj, "decl_type", "sys_real");
            break;
        default:
            break;
        }
        break;
    case SimpleTypeDecl::NAME:
        cJSON_AddItemToObject(this->this_obj, "name_decl", this->type_decl.name_type_decl->createJSONObj());
        break;
    case SimpleTypeDecl::NAME_LIST:
        TraversalItem<Identifier>(this->this_obj, this->type_decl.name_list_decl, "name_list_decl");
        break;
    case SimpleTypeDecl::RANGE_TYPE:
        cJSON_AddItemToObject(this->this_obj, "range_decl", this->type_decl.range_type_decl->createJSONObj());
        break;
    default:
        break;
    }

    return this->this_obj;
}

cJSON* RangeTypeDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "RangeTypeDecl");
    switch (this->type)
    {
    case RangeTypeDecl::POS_POS:
        cJSON_AddItemToObject(this->this_obj, "pos-lhs", this->c_lhs->createJSONObj());
        cJSON_AddItemToObject(this->this_obj, "pos-rhs", this->c_rhs->createJSONObj());
        break;
    case RangeTypeDecl::NEG_POS:
        cJSON_AddItemToObject(this->this_obj, "neg-lhs", this->c_lhs->createJSONObj());
        cJSON_AddItemToObject(this->this_obj, "pos-rhs", this->c_rhs->createJSONObj());
        break;
    case RangeTypeDecl::NEG_NEG:
        cJSON_AddItemToObject(this->this_obj, "neg-lhs", this->c_lhs->createJSONObj());
        cJSON_AddItemToObject(this->this_obj, "neg-rhs", this->c_rhs->createJSONObj());
        break;
    case RangeTypeDecl::NAME_NAME:
        cJSON_AddItemToObject(this->this_obj, "lhs", this->n_lhs->createJSONObj());
        cJSON_AddItemToObject(this->this_obj, "rhs", this->n_rhs->createJSONObj());
        break;
    default:
        break;
    }

    return this->this_obj;
}

cJSON* ArrayTypeDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ArrayTypeDecl");

    cJSON_AddItemToObject(this->this_obj, "range_decl", this->range_decl->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "element_decl", this->element_decl->createJSONObj());

    return this->this_obj;
}

cJSON* RecordTypeDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "RecordTypeDecl");

    TraversalItem<NormalDecl>(this->this_obj, this->field_decl_list, "fields_list_decl");

    return this->this_obj;
}

cJSON* NormalDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "NormalDecl");

    TraversalItem<Identifier>(this->this_obj, this->name_list, "name_list_decl");
    cJSON_AddItemToObject(this->this_obj, "type_decl", this->type_decl->createJSONObj());

    return this->this_obj;
}

cJSON* CallDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "CallDecl");

    switch (this->flag)
    {
    case CallDecl::FUNC:
        cJSON_AddItemToObject(this->this_obj, "func_decl", this->decl.func_decl->createJSONObj());
        break;
    case CallDecl::PROC:
        cJSON_AddItemToObject(this->this_obj, "proc_decl", this->decl.proc_decl->createJSONObj());
        break;
    default:
        break;
    }

    return this->this_obj;
}

cJSON* FunctionDecl::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "FunctionDecl");

    cJSON_AddItemToObject(this->this_obj, "head", this->head->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "sub_routine", this->sub_routine->createJSONObj());

    return this->this_obj;
}

cJSON* FunctionHead::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "FunctionHead");

    cJSON_AddItemToObject(this->this_obj, "func_name", this->func_name->createJSONObj());

    if(this->params != nullptr)
        TraversalItem<ParaTypeList>(this->this_obj, this->params, "params");

    cJSON_AddItemToObject(this->this_obj, "ret", this->ret->createJSONObj());

    return this->this_obj;
}

cJSON* ParaTypeList::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ParaTypeList");
    switch (this->flag)
    {
    case ParaTypeList::VAR:
        cJSON_AddStringToObject(this->this_obj, "para_type", "var");
        break;
    case ParaTypeList::VAL:
        cJSON_AddStringToObject(this->this_obj, "para_type", "val");
        break;
    default:
        break;
    }
    TraversalItem<Identifier>(this->this_obj, this->para_list, "para_list");
    cJSON_AddItemToObject(this->this_obj, "type", this->type->createJSONObj());

    return this->this_obj;
}

cJSON* ProcedureHead::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ProcedureHead");

    cJSON_AddItemToObject(this->this_obj, "proc_name", this->func_name->createJSONObj());

    if(this->params != nullptr)
        TraversalItem<ParaTypeList>(this->this_obj, this->params, "params");

    return this->this_obj;
}

cJSON* CompoundStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "CompoundStatement");
    if(this->list != nullptr)
        TraversalItem<Statement>(this->this_obj, this->list, "stmt_list");

    return this->this_obj;
}

cJSON* Statement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Statement");

    cJSON_AddNumberToObject(this->this_obj, "label", this->label);
    cJSON_AddItemToObject(this->this_obj, "body", this->body->createJSONObj());

    return this->this_obj;
}

cJSON* NonLabelStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "NonLabelStatement");

    switch (this->flag)
    {
    case NonLabelStatement::ASSIGN:
        cJSON_AddItemToObject(this->this_obj, "ASSIGN", this->statement.assign_statement->createJSONObj());
        break;
    case NonLabelStatement::PROC:
        cJSON_AddItemToObject(this->this_obj, "PROC", this->statement.proc_statement->createJSONObj());
        break;
    case NonLabelStatement::COMPOUND:
        cJSON_AddItemToObject(this->this_obj, "COMPOUND", this->statement.compound_statement->createJSONObj());
        break;
    case NonLabelStatement::IF:
        cJSON_AddItemToObject(this->this_obj, "IF", this->statement.if_statement->createJSONObj());
        break;
    case NonLabelStatement::REPEAT:
        cJSON_AddItemToObject(this->this_obj, "REPEAT", this->statement.repeat_statement->createJSONObj());
        break;
    case NonLabelStatement::WHILE:
        cJSON_AddItemToObject(this->this_obj, "WHILE", this->statement.while_statement->createJSONObj());
        break;
    case NonLabelStatement::FOR:
        cJSON_AddItemToObject(this->this_obj, "FOR", this->statement.for_statment->createJSONObj());
        break;
    case NonLabelStatement::CASE:
        cJSON_AddItemToObject(this->this_obj, "CASE", this->statement.case_statement->createJSONObj());
        break;
    case NonLabelStatement::GOTO:
        cJSON_AddItemToObject(this->this_obj, "GOTO", this->statement.goto_statement->createJSONObj());
        break;
    default:
        break;
    }

    return this->this_obj;
}

cJSON* GotoStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "GotoStatement");
    cJSON_AddNumberToObject(this->this_obj, "target_label", this->target_label);
    return this->this_obj;
}

cJSON* AssignStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "AssignStatement");

    switch (this->flag)
    {
    case AssignStatement::NORMAL:
        cJSON_AddItemToObject(this->this_obj, "normal_assign", this->assign.normal_assign->createJSONObj());
        break;
    case AssignStatement::ARRAY:
        cJSON_AddItemToObject(this->this_obj, "array_assign", this->assign.array_assign->createJSONObj());
        break;
    case AssignStatement::RECORD:
        cJSON_AddItemToObject(this->this_obj, "record_assign", this->assign.record_assign->createJSONObj());
        break;
    default:
        break;
    }

    return this->this_obj;
}

cJSON* NormalAssignment::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "NormalAssignment");

    cJSON_AddItemToObject(this->this_obj, "id", this->id->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "value", this->value_expr->createJSONObj());

    return this->this_obj;
}

cJSON* ArrayAssignment::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ArrayAssignment");

    cJSON_AddItemToObject(this->this_obj, "array_id", this->array_id->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "index_expr", this->index_expr->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "value_expr", this->value_expr->createJSONObj());

    return this->this_obj;
}

cJSON* RecordAssignment::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "RecordAssignment");

    cJSON_AddItemToObject(this->this_obj, "record_id", this->record_id->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "field", this->field_expr->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "value", this->value_expr->createJSONObj());

    return this->this_obj;
}

cJSON* IfStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "IfStatement");

    cJSON_AddItemToObject(this->this_obj, "judge", this->judge_expr->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "s1", this->statement1->createJSONObj());
    if(this->statement2 != nullptr)
        cJSON_AddItemToObject(this->this_obj, "s2", this->statement2->createJSONObj());

    return this->this_obj;
}

cJSON* RepeatStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "RepeatStatement");

    TraversalItem<Statement>(this->this_obj, this->repeat_list, "repeat_list");
    cJSON_AddItemToObject(this->this_obj, "until", this->until_expr->createJSONObj());

    return this->this_obj;
}

cJSON* WhileStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "WhileStatement");

    cJSON_AddItemToObject(this->this_obj, "judge", this->judge_expr->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "statement", this->statement->createJSONObj());
    

    return this->this_obj;
}

cJSON* ForStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ForStatement");

    cJSON_AddItemToObject(this->this_obj, "id", this->iter_id->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "start", this->start_expr->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "end", this->end_expr->createJSONObj());
    switch(this->type){
    case ForStatement::TO:
        cJSON_AddStringToObject(this->this_obj, "type", "to");
        break;
    case ForStatement::DOWNTO:
        cJSON_AddStringToObject(this->this_obj, "type", "downto");
        break;
    }

    cJSON_AddItemToObject(this->this_obj, "statement", this->statement->createJSONObj());

    return this->this_obj;
}

cJSON* CaseStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "CaseStatement");

    cJSON_AddItemToObject(this->this_obj, "judge", this->judge_expression->createJSONObj());
    TraversalItem<CaseExpression>(this->this_obj, this->case_list, "case_list");
    return this->this_obj;
}

cJSON* CaseExpression::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "CaseExpression");

    switch (this->type)
    {
    case CaseExpression::ID_CASE:
        cJSON_AddItemToObject(this->this_obj, "id", this->id->createJSONObj());
        break;
    case CaseExpression::CONST_CASE:
        cJSON_AddItemToObject(this->this_obj, "const", this->value->createJSONObj());
        break;
    default:
        break;
    }

    cJSON_AddItemToObject(this->this_obj, "statement", this->statement->createJSONObj());
    return this->this_obj;
}

cJSON* Procedure::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Procedure");

    cJSON_AddItemToObject(this->this_obj, "id", this->id->createJSONObj());

    if(this->arg_list != nullptr)
        TraversalItem<Expression>(this->this_obj, this->arg_list, "arg_list");

    return this->this_obj;
}

cJSON* SystemProcedure::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "SystemProcedure");


    switch (this->proc)
    {
    case Sys_Proc::WRITE:
        cJSON_AddStringToObject(this->this_obj, "id", "WRITE");
        break;
    case Sys_Proc::WRITELN:
        cJSON_AddStringToObject(this->this_obj, "id", "WRITELN");
        break;
    default:
        break;
    }
    if(this->arg_list != nullptr)
        TraversalItem<Expression>(this->this_obj, this->arg_list, "arg_list");

    return this->this_obj;
}

cJSON* ReadProcedure::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ReadProcedure");
    cJSON_AddItemToObject(this->this_obj, "factor", this->value->createJSONObj());

    return this->this_obj;
}

cJSON* ProcStatement::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "ProcStatement");


    switch (this->flag)
    {
    case ProcStatement::PROC:
        cJSON_AddItemToObject(this->this_obj, "normal_proc", this->proc.normal_proc->createJSONObj());
        break;
    case ProcStatement::SYS_PROC:
        cJSON_AddItemToObject(this->this_obj, "sys_proc", this->proc.sys_proc->createJSONObj());
        break;
    case ProcStatement::READ_PROC:
        cJSON_AddItemToObject(this->this_obj, "read_proc", this->proc.read_proc->createJSONObj());
        break;
    default:
        break;
    }

    return this->this_obj;
}

cJSON* Expression::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Expression");

    if(this->lhs != nullptr)
        cJSON_AddItemToObject(this->this_obj, "lhs", this->lhs->createJSONObj());

    switch (this->type)
    {
    case Expression::GE:
        cJSON_AddStringToObject(this->this_obj, "type", "GE");
        break;
    case Expression::GT:
        cJSON_AddStringToObject(this->this_obj, "type", "GT");
        break;
    case Expression::LE:
        cJSON_AddStringToObject(this->this_obj, "type", "LE");
        break;
    case Expression::LT:
        cJSON_AddStringToObject(this->this_obj, "type", "LT");
        break;
    case Expression::EQUAL:
        cJSON_AddStringToObject(this->this_obj, "type", "EQUAL");
        break;
    case Expression::UNEQUAL:
        cJSON_AddStringToObject(this->this_obj, "type", "UNEQUAL");
        break;
    case Expression::SINGLE:
        cJSON_AddStringToObject(this->this_obj, "type", "SINGLE");
        break;
    default:
        break;
    }
    cJSON_AddItemToObject(this->this_obj, "rhs", this->rhs->createJSONObj());

    return this->this_obj;
}

cJSON* Expr::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Expr");

    if(this->lhs != nullptr)
        cJSON_AddItemToObject(this->this_obj, "lhs", this->lhs->createJSONObj());

    switch (this->type)
    {
    case Expr::PLUS:
        cJSON_AddStringToObject(this->this_obj, "type", "PLUS");
        break;
    case Expr::MINUS:
        cJSON_AddStringToObject(this->this_obj, "type", "MINUS");
        break;
    case Expr::OR:
        cJSON_AddStringToObject(this->this_obj, "type", "OR");
        break;
    case Expr::SINGLE:
        cJSON_AddStringToObject(this->this_obj, "type", "SINGLE");
        break;
    default:
        break;
    }
    cJSON_AddItemToObject(this->this_obj, "rhs", this->rhs->createJSONObj());

    return this->this_obj;
}

cJSON* Term::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Term");

    if(this->lhs != nullptr)
        cJSON_AddItemToObject(this->this_obj, "lhs", this->lhs->createJSONObj());

    switch (this->type)
    {
    case Term::MUL:
        cJSON_AddStringToObject(this->this_obj, "type", "MUL");
        break;
    case Term::DIV:
        cJSON_AddStringToObject(this->this_obj, "type", "DIV");
        break;
    case Term::MOD:
        cJSON_AddStringToObject(this->this_obj, "type", "MOD");
        break;
    case Term::AND:
        cJSON_AddStringToObject(this->this_obj, "type", "AND");
        break;
    case Term::SINGLE:
        cJSON_AddStringToObject(this->this_obj, "type", "SINGLE");
        break;
    default:
        break;
    }
    cJSON_AddItemToObject(this->this_obj, "rhs", this->rhs->createJSONObj());

    return this->this_obj;
}

cJSON* Factor::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "Factor");

    switch (this->flag)
    {
    case Factor::NAME:
        cJSON_AddItemToObject(this->this_obj, "name_factor", this->factor.name_factor->createJSONObj());
        break;
    case Factor::FUNC:
        cJSON_AddItemToObject(this->this_obj, "func_factor", this->factor.func_factor->createJSONObj());
        break;
    case Factor::SYS_FUNC:
        cJSON_AddItemToObject(this->this_obj, "sys_func_factor", this->factor.sys_func_factor->createJSONObj());
        break;
    case Factor::CONST:
        cJSON_AddItemToObject(this->this_obj, "const_factor", this->factor.const_factor->createJSONObj());
        break;
    case Factor::EXPR:
        cJSON_AddItemToObject(this->this_obj, "expr_factor", this->factor.expr_factor->createJSONObj());
        break;
    case Factor::AT:
        cJSON_AddItemToObject(this->this_obj, "at_factor", this->factor.at_factor->createJSONObj());
        break;
    case Factor::GET:
        cJSON_AddItemToObject(this->this_obj, "get_factor", this->factor.get_factor->createJSONObj());
        break;
    case Factor::NOT:
        cJSON_AddItemToObject(this->this_obj, "not_factor", this->factor.not_factor->createJSONObj());
        break;
    case Factor::MINUS:
        cJSON_AddItemToObject(this->this_obj, "minus_factor", this->factor.minus_factor->createJSONObj());
        break;
    default:
        break;
    }

    return this->this_obj;
}

cJSON* NotFactor::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "NotFactor");

    cJSON_AddItemToObject(this->this_obj, "factor", this->factor->createJSONObj());
    return this->this_obj;
}

cJSON* MinusFactor::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "MinusFactor");

    cJSON_AddItemToObject(this->this_obj, "factor", this->factor->createJSONObj());
    return this->this_obj;
}

cJSON* AtOperation::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "AtOperation");

    cJSON_AddItemToObject(this->this_obj, "array_id", this->array_id->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "index_expr", this->index_expr->createJSONObj());
    return this->this_obj;
}

cJSON* GetOperation::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "GetOperation");

    cJSON_AddItemToObject(this->this_obj, "record_id", this->record_id->createJSONObj());
    cJSON_AddItemToObject(this->this_obj, "field_id", this->field_id->createJSONObj());
    return this->this_obj;
}

cJSON* FunctionCall::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "FunctionCall");

    cJSON_AddItemToObject(this->this_obj, "func_name", this->func_name->createJSONObj());
    if(this->args != nullptr)
        TraversalItem<Expression>(this->this_obj, this->args, "args");
    return this->this_obj;
}

cJSON* SysFuncCall::createJSONObj(){
    this->this_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(this->this_obj, "node_name", "SysFuncCall");

    switch (this->sys_func)
    {
    case Sys_Funct::ABS:
        cJSON_AddStringToObject(this->this_obj, "id", "abs");
        break;
    case Sys_Funct::CHR:
        cJSON_AddStringToObject(this->this_obj, "id", "chr");
        break;
    case Sys_Funct::ODD:
        cJSON_AddStringToObject(this->this_obj, "id", "odd");
        break;
    case Sys_Funct::ORD:
        cJSON_AddStringToObject(this->this_obj, "id", "ord");
        break;
    case Sys_Funct::PRED:
        cJSON_AddStringToObject(this->this_obj, "id", "pred");
        break;
    case Sys_Funct::SQR:
        cJSON_AddStringToObject(this->this_obj, "id", "sqr");
        break;
    case Sys_Funct::SQRT:
        cJSON_AddStringToObject(this->this_obj, "id", "sqrt");
        break;
    case Sys_Funct::SUCC:
        cJSON_AddStringToObject(this->this_obj, "id", "succ");
        break;
    default:
        break;
    }
    if(this->args != nullptr)
        TraversalItem<Expression>(this->this_obj, this->args, "args");
    return this->this_obj;
}

void Program::generateIR(IRGenerator* ir){
    ir->GetModulePt() = new llvm::Module(this->program_id->id, ir->GetContext());
    ir->AfterModule();

    //main
    llvm::Type* intType = llvm::Type::getInt32Ty(ir->GetContext());
    llvm::FunctionType* functionType = llvm::FunctionType::get(intType, false);
    llvm::Function* function = llvm::Function::Create(functionType, llvm::GlobalValue::ExternalLinkage, "main", ir->GetModulePt());
    assert(!llvm::verifyFunction(*function));

    //push
    ir->PushFuncStack(function);
    
    //entrypoint
    ir->GetBuilder().SetInsertPoint(llvm::BasicBlock::Create(ir->GetContext(), "entrypoint", function, nullptr));

    this->routine->generateIR(ir);

    //return
    llvm::ConstantInt* zero = ir->GetBuilder().getInt32(0);
    ir->GetBuilder().CreateRet(zero);

    //pop
    ir->PopFuncStack();
}

void Routine::generateIR(IRGenerator* ir){
    if(this->isGlobal){
        this->routine_head->flagGlobal();
        if(this->routine_head != nullptr)
            this->routine_head->generateIR(ir);
        if(this->routine_body != nullptr)
            this->routine_body->generateIR(ir);
    }
    else{
        //sub
        if(this->routine_head != nullptr)
            this->routine_head->generateIR(ir);
        if(this->routine_body != nullptr)
            this->routine_body->generateIR(ir);
    }
    
}

void RoutineHead::flagGlobal(){
    size_t sz = ARRAY_SIZE(const_part);
    for(size_t i = 0; i < sz; i++){
        const_part[i].global = true;
    }

    sz = ARRAY_SIZE(type_part);
    for(size_t i = 0; i < sz; i++){
        type_part[i].global = true;
    }

    sz = ARRAY_SIZE(var_part);
    for(size_t i = 0; i < sz; i++){
        var_part[i].global = true;
    }

    //calldecl not support subroutine
}

void RoutineHead::generateIR(IRGenerator* ir){
    size_t sz = ARRAY_SIZE(const_part);
    for(size_t i = 0; i < sz; i++){
        const_part[i].generateIR(ir);
    }

    sz = ARRAY_SIZE(type_part);
    for(size_t i = 0; i < sz; i++){
        type_part[i].generateIR(ir);
    }

    sz = ARRAY_SIZE(var_part);
    for(size_t i = 0; i < sz; i++){
        var_part[i].generateIR(ir);
    }

    sz = ARRAY_SIZE(routine_part);
    for(size_t i = 0; i < sz; i++){
        routine_part[i].generateIR(ir);
    }
}

void ConstExprssion::generateIR(IRGenerator* ir){
    this->name->buffer;

    llvm::GlobalVariable* gVar = nullptr;
    auto const_val = this->value->getLLVMValue(ir);
    auto sc = new SingleContext();
    if(this->global){
        //global const
        switch (this->value->flag)
        {
        case ConstValue::INT:
            ir->GetModulePt()->getOrInsertGlobal(this->name->buffer, ir->GetBuilder().getInt32Ty());
            gVar = ir->GetModulePt()->getNamedGlobal(this->name->buffer);
            gVar->setInitializer(const_val);
            sc->single_type = Sys_Type::SYS_INTEGER;
            ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt32Ty(), sc, this->global);
            break;
        case ConstValue::REAL:
            ir->GetModulePt()->getOrInsertGlobal(this->name->buffer, ir->GetBuilder().getDoubleTy());
            gVar = ir->GetModulePt()->getNamedGlobal(this->name->buffer);
            gVar->setInitializer(const_val);
            sc->single_type = Sys_Type::SYS_REAL;
            ir->AddVarDef(this->name->buffer, ir->GetBuilder().getDoubleTy(), sc, this->global);
            break;
        case ConstValue::CHAR:
            ir->GetModulePt()->getOrInsertGlobal(this->name->buffer, ir->GetBuilder().getInt8Ty());
            gVar = ir->GetModulePt()->getNamedGlobal(this->name->buffer);
            gVar->setInitializer(const_val);
            sc->single_type = Sys_Type::SYS_CHAR;
            ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt8Ty(), sc, this->global);
            break;
        case ConstValue::SYS_CON:
            switch (this->value->value.sys_con_value)
            {
            case Sys_Con::TRUE:
                ir->GetModulePt()->getOrInsertGlobal(this->name->buffer, ir->GetBuilder().getInt1Ty());
                gVar = ir->GetModulePt()->getNamedGlobal(this->name->buffer);
                gVar->setInitializer(const_val);
                ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt1Ty(), sc, this->global);
                break;
            case Sys_Con::FALSE:
                ir->GetModulePt()->getOrInsertGlobal(this->name->buffer, ir->GetBuilder().getInt1Ty());
                gVar = ir->GetModulePt()->getNamedGlobal(this->name->buffer);
                gVar->setInitializer(const_val);
                ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt1Ty(), sc, this->global);
                break;
            case Sys_Con::MAXINT:
                ir->GetModulePt()->getOrInsertGlobal(this->name->buffer, ir->GetBuilder().getInt32Ty());
                gVar = ir->GetModulePt()->getNamedGlobal(this->name->buffer);
                gVar->setInitializer(const_val);
                sc->single_type = Sys_Type::SYS_INTEGER;
                ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt32Ty(), sc, this->global);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else{
        //local const

        //get current function context
        llvm::IRBuilder<> tmp_builder(&(ir->GetCurrentFunction()->getEntryBlock()), ir->GetCurrentFunction()->getEntryBlock().begin());

        switch (this->value->flag)
        {
        case ConstValue::INT:
            ir->GetBuilder().CreateStore(ir->GetBuilder().getInt32(this->value->value.int_value), 
                tmp_builder.CreateAlloca(ir->GetBuilder().getInt32Ty(), nullptr, this->name->buffer));
            sc->single_type = Sys_Type::SYS_INTEGER;
            ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt32Ty(), sc, this->global);
            break;
        case ConstValue::REAL:
            ir->GetBuilder().CreateStore(llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), this->value->value.real_value), 
                tmp_builder.CreateAlloca(ir->GetBuilder().getDoubleTy(), nullptr, this->name->buffer));
            sc->single_type = Sys_Type::SYS_REAL;
            ir->AddVarDef(this->name->buffer, ir->GetBuilder().getDoubleTy(), sc, this->global);
            break;
        case ConstValue::CHAR:
            ir->GetBuilder().CreateStore(ir->GetBuilder().getInt8(this->value->value.char_value), 
                tmp_builder.CreateAlloca(ir->GetBuilder().getInt8Ty(), nullptr, this->name->buffer));
            sc->single_type = Sys_Type::SYS_CHAR;
            ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt8Ty(), sc, this->global);
            break;
        case ConstValue::SYS_CON:
            switch (this->value->value.sys_con_value)
            {
            case Sys_Con::TRUE:
                ir->GetBuilder().CreateStore(ir->GetBuilder().getTrue(), 
                    tmp_builder.CreateAlloca(ir->GetBuilder().getInt1Ty(), nullptr, this->name->buffer));
                ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt1Ty(), sc, this->global);
                break;
            case Sys_Con::FALSE:
                ir->GetBuilder().CreateStore(ir->GetBuilder().getFalse(), 
                    tmp_builder.CreateAlloca(ir->GetBuilder().getInt1Ty(), nullptr, this->name->buffer));
                ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt1Ty(), sc, this->global);
                break;
            case Sys_Con::MAXINT:
                ir->GetBuilder().CreateStore(ir->GetBuilder().getInt32(INT32_MAX), 
                    tmp_builder.CreateAlloca(ir->GetBuilder().getInt32Ty(), nullptr, this->name->buffer));
                sc->single_type = Sys_Type::SYS_INTEGER;
                ir->AddVarDef(this->name->buffer, ir->GetBuilder().getInt32Ty(), sc, this->global);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

llvm::Type* SimpleTypeDecl::getLLVMType(IRGenerator* ir, CompoundContext*& cc){
    cc = new SingleContext();
    auto sc = static_cast<SingleContext*>(cc);
    switch (this->flag)
    {
    case SimpleTypeDecl::SYS_TYPE:
        sc->single_type = this->type_decl.sys_type_decl;
        switch(this->type_decl.sys_type_decl){
        case Sys_Type::SYS_BOOLEAN:
            return ir->GetBuilder().getInt1Ty();
            break;
        case Sys_Type::SYS_CHAR:
            return ir->GetBuilder().getInt8Ty();
            break;
        case Sys_Type::SYS_INTEGER:
            return ir->GetBuilder().getInt32Ty();
            break;
        case Sys_Type::SYS_REAL:
            return ir->GetBuilder().getDoubleTy();
            break;
        default:
            break;
        }
        break;
    case SimpleTypeDecl::NAME:
        {
            auto r = ir->FindTypeContext(this->type_decl.name_type_decl->buffer);
            cc = r.second;
            return r.first;   
        }
        break;
    case SimpleTypeDecl::NAME_LIST:
        {
            size_t sz = ARRAY_SIZE(this->type_decl.name_list_decl);
            auto r = ir->FindTypeContext(this->type_decl.name_list_decl[sz-1].buffer);
            cc = r.second;
            return r.first;   
        }
        break;
    case SimpleTypeDecl::RANGE_TYPE:
        std::cerr << "Unsupported variable type decl\n";
        assert(false);
        break;
    default:
        break;
    }
    return nullptr;
}

llvm::Type* TypeDecl::getLLVMType(IRGenerator* ir, CompoundContext*& cc){
    switch (this->flag)
    {
    case SIMPLE:
        return this->decl.simple_decl->getLLVMType(ir, cc);
        break;
    case ARRAY:
        {
            if(this->decl.array_decl->range_decl->flag != SimpleTypeDecl::RANGE_TYPE){
                std::cerr << "Unsupported array range decl\n";
                assert(false);
            }

            cc = new ArrayContext();

            auto ac = static_cast<ArrayContext*>(cc);

            auto element_type = this->decl.array_decl->element_decl->getLLVMType(ir, ac->element_context);

            //handle range
            switch (this->decl.array_decl->range_decl->type_decl.range_type_decl->type)
            {
            case RangeTypeDecl::POS_POS:
                if(this->decl.array_decl->range_decl->type_decl.range_type_decl->c_lhs->flag == ConstValue::INT 
                    && this->decl.array_decl->range_decl->type_decl.range_type_decl->c_rhs->flag == ConstValue::INT){
                        ac->range = {
                            this->decl.array_decl->range_decl->type_decl.range_type_decl->c_lhs->value.int_value,
                            this->decl.array_decl->range_decl->type_decl.range_type_decl->c_rhs->value.int_value
                        };
                }
                else{
                    //throw
                    assert(false);
                }
                break;
            case RangeTypeDecl::NEG_POS:
                if(this->decl.array_decl->range_decl->type_decl.range_type_decl->c_lhs->flag == ConstValue::INT 
                    && this->decl.array_decl->range_decl->type_decl.range_type_decl->c_rhs->flag == ConstValue::INT){
                        ac->range = {
                            -(this->decl.array_decl->range_decl->type_decl.range_type_decl->c_lhs->value.int_value),
                            this->decl.array_decl->range_decl->type_decl.range_type_decl->c_rhs->value.int_value
                        };
                }
                else{
                    //throw
                    assert(false);
                }
                break;
            case RangeTypeDecl::NEG_NEG:
                if(this->decl.array_decl->range_decl->type_decl.range_type_decl->c_lhs->flag == ConstValue::INT 
                    && this->decl.array_decl->range_decl->type_decl.range_type_decl->c_rhs->flag == ConstValue::INT){
                        ac->range = {
                            -(this->decl.array_decl->range_decl->type_decl.range_type_decl->c_lhs->value.int_value),
                            -(this->decl.array_decl->range_decl->type_decl.range_type_decl->c_rhs->value.int_value)
                        };
                }
                else{
                    //throw
                    assert(false);
                }
                break;
            case RangeTypeDecl::NAME_NAME:
                {
                    auto lhs = this->decl.array_decl->range_decl->type_decl.range_type_decl->n_lhs;
                    auto rhs = this->decl.array_decl->range_decl->type_decl.range_type_decl->n_rhs;   
                    auto gv_l = ir->GetModulePt()->getGlobalVariable(lhs->buffer);
                    auto gv_r = ir->GetModulePt()->getGlobalVariable(rhs->buffer);
                    auto c_lhs = gv_l->getInitializer();
                    auto c_rhs = gv_r->getInitializer();
                    auto c_int_lhs = llvm::dyn_cast<llvm::ConstantInt>(c_lhs);
                    auto c_int_rhs = llvm::dyn_cast<llvm::ConstantInt>(c_rhs);
                    assert(c_int_lhs != nullptr && c_int_rhs != nullptr);
                    ac->range = {c_int_lhs->getSExtValue(), c_int_rhs->getSExtValue()};
                }
                break;
            default:
                break;
            }
            return llvm::ArrayType::get(element_type, ac->range.second - ac->range.first + 1);
        }
        break;
    case RECORD:
        {
            cc = new RecordContext();

            auto rc = static_cast<RecordContext*>(cc);

            std::vector<llvm::Type*> fields;
            size_t index = 0;
            for(size_t i = 0; i < ARRAY_SIZE(this->decl.record_decl->field_decl_list); i++){
                auto this_names = this->decl.record_decl->field_decl_list[i].name_list;
                auto this_type = this->decl.record_decl->field_decl_list[i].type_decl;

                CompoundContext* this_type_context;
                auto this_llvm_type = this_type->getLLVMType(ir, this_type_context);

                for(size_t j = 0; j < ARRAY_SIZE(this_names); j++){
                    auto this_name = this_names[j].buffer;

                    if(rc->field_map.find(this_name) != rc->field_map.end()){
                        //throw
                        assert(false);
                    }
                    rc->field_map.insert(std::pair<std::string, uint64_t>(this_name, index++));
                    rc->context_map.insert(std::pair<std::string, CompoundContext*>(this_name, this_type_context));
                    fields.push_back(this_llvm_type);
                }  
            }

            return llvm::StructType::get(ir->GetContext(), fields);
        } 
        break;
    default:
        break;
    }
    return nullptr;
}

void TypeDefinition::generateIR(IRGenerator* ir){
    auto name = this->name->buffer;
    CompoundContext* cc;
    auto llvm_type = this->value->getLLVMType(ir, cc);
    
    ir->AddTypeDef(name, llvm_type, cc, this->global);
}

void NormalDecl::generateIR(IRGenerator* ir) {
    CompoundContext* cc;
    auto llvm_type = this->type_decl->getLLVMType(ir, cc);
    
    for(size_t i = 0; i < ARRAY_SIZE(this->name_list); i++){
        auto this_var = this->name_list[i].buffer;

        //tell llvm
        if(this->global){
            llvm::GlobalVariable* gVar = nullptr;
            ir->GetModulePt()->getOrInsertGlobal(this_var, llvm_type);
            gVar = ir->GetModulePt()->getNamedGlobal(this_var);
            gVar->setInitializer(ir->GetDefaultValue(llvm_type));
        }
        else{
            llvm::IRBuilder<> tmp_builder(&(ir->GetCurrentFunction()->getEntryBlock()), ir->GetCurrentFunction()->getEntryBlock().begin());
            tmp_builder.CreateAlloca(llvm_type, nullptr, this_var);
        }

        //store context
        ir->AddVarDef(this_var, llvm_type, cc, this->global);
    }
}

void CallDecl::generateIR(IRGenerator* ir){
    switch (this->flag)
    {
    case CallDecl::FUNC:
        {
            CallContext* call_cxt = new CallContext();
            call_cxt->ret_context.first = this->decl.func_decl->head->ret->getLLVMType(ir, call_cxt->ret_context.second);
            llvm::FunctionType* functionType = nullptr;
            std::vector<llvm::Type*> llvm_para_types;
            if(this->decl.func_decl->head->params == nullptr){
                functionType = llvm::FunctionType::get(call_cxt->ret_context.first, false);
            }
            else{
                for(size_t i = 0; i < ARRAY_SIZE(this->decl.func_decl->head->params); i++){
                    auto this_param = this->decl.proc_decl->head->params[i];
                    CompoundContext* cc;
                    auto this_type = this_param.type->getLLVMType(ir, cc);
                    auto isVal = this_param.flag;

                    for(size_t j = 0; j < ARRAY_SIZE(this_param.para_list); j++){
                        auto para_name = this_param.para_list[i].buffer;

                        if(isVal){
                            llvm_para_types.push_back(this_type);
                            CallContext::ParamInfo* info = new CallContext::ParamInfo(para_name, this_type, cc);
                            call_cxt->params_context.push_back(info);
                        }
                        else{
                            llvm_para_types.push_back(this_type->getPointerTo());
                            CallContext::ParamInfo* info = new CallContext::ParamInfo(para_name, this_type->getPointerTo(), cc);
                            call_cxt->params_context.push_back(info);
                        }
                    }
                }
                functionType = llvm::FunctionType::get(call_cxt->ret_context.first, llvm_para_types, false);
            }

            ir->AddCallDef(this->decl.func_decl->head->func_name->buffer, call_cxt);

            llvm::Function* function = llvm::Function::Create(functionType, llvm::GlobalValue::ExternalLinkage, this->decl.func_decl->head->func_name->buffer, ir->GetModulePt());
            assert(!llvm::verifyFunction(*function));

            //push
            ir->PushFuncStack(function);
            
            //entrypoint
            ir->GetBuilder().SetInsertPoint(llvm::BasicBlock::Create(ir->GetContext(), "entrypoint", function, nullptr));

            //Parameters
            llvm::IRBuilder<> tmp_builder(&(function->getEntryBlock()), function->getEntryBlock().begin());
            llvm::Function::arg_iterator arg_iter =  function->arg_begin();
            size_t idx = 0;
            for(size_t i = 0; i < ARRAY_SIZE(this->decl.func_decl->head->params); i++){
                auto this_param = this->decl.func_decl->head->params[i];
                bool isVal = this_param.flag;
                CompoundContext* cc;
                auto this_type = this_param.type->getLLVMType(ir, cc);

                for(size_t j = 0; j < ARRAY_SIZE(this_param.para_list); j++){
                    auto para_name = this_param.para_list[j].buffer;

                    if(isVal){
                        ir->GetBuilder().CreateStore(arg_iter++, 
                            tmp_builder.CreateAlloca(this_type, nullptr, para_name));
                        ir->AddVarDef(para_name, this_type, cc, false);
                    }
                    else{
                        ir->GetBuilder().CreateGEP(this_type, arg_iter, ir->GetBuilder().getInt32(0), para_name);
                        ir->AddVarDef(para_name, this_type->getPointerTo(), cc, false);
                    }
                    idx++;
                }
            }

            //return val
            tmp_builder.CreateAlloca(call_cxt->ret_context.first, nullptr, this->decl.func_decl->head->func_name->buffer);            
            ir->AddVarDef(this->decl.func_decl->head->func_name->buffer, call_cxt->ret_context.first, call_cxt->ret_context.second, true);

            //subroutine
            this->decl.func_decl->sub_routine->generateIR(ir);

            //return
            ir->GetBuilder().CreateRet(new llvm::LoadInst(call_cxt->ret_context.first, 
                ir->FindSymbolValue(this->decl.func_decl->head->func_name->buffer), "ret", false, 
                    ir->GetBuilder().GetInsertBlock()));

            //pop
            ir->PopFuncStack();
            ir->GetBuilder().SetInsertPoint(&(ir->GetCurrentFunction())->getBasicBlockList().back());
        }
        break;
    case CallDecl::PROC:
        {
            CallContext* call_cxt = new CallContext();
            call_cxt->ret_context.first = ir->GetBuilder().getVoidTy();
            llvm::FunctionType* functionType = nullptr;
            std::vector<llvm::Type*> llvm_para_types;
            if(this->decl.proc_decl->head->params == nullptr){
                functionType = llvm::FunctionType::get(call_cxt->ret_context.first, false);
            }
            else{
                for(size_t i = 0; i < ARRAY_SIZE(this->decl.proc_decl->head->params); i++){
                    auto this_param = this->decl.proc_decl->head->params[i];
                    CompoundContext* cc;
                    auto this_type = this_param.type->getLLVMType(ir, cc);
                    auto isVal = this_param.flag;

                    for(size_t j = 0; j < ARRAY_SIZE(this_param.para_list); j++){
                        auto para_name = this_param.para_list[i].buffer;

                        if(isVal){
                            llvm_para_types.push_back(this_type);
                            CallContext::ParamInfo* info = new CallContext::ParamInfo(para_name, this_type, cc);
                            call_cxt->params_context.push_back(info);
                        }
                        else{
                            llvm_para_types.push_back(this_type->getPointerTo());
                            CallContext::ParamInfo* info = new CallContext::ParamInfo(para_name, this_type->getPointerTo(), cc);
                            call_cxt->params_context.push_back(info);
                        }
                    }
                }
                functionType = llvm::FunctionType::get(call_cxt->ret_context.first, llvm_para_types, false);
            }

            ir->AddCallDef(this->decl.proc_decl->head->func_name->buffer, call_cxt);

            llvm::Function* function = llvm::Function::Create(functionType, llvm::GlobalValue::ExternalLinkage, this->decl.proc_decl->head->func_name->buffer, ir->GetModulePt());
            assert(!llvm::verifyFunction(*function));

            //push
            ir->PushFuncStack(function);
            
            //entrypoint
            ir->GetBuilder().SetInsertPoint(llvm::BasicBlock::Create(ir->GetContext(), "entrypoint", function, nullptr));

            //Parameters
            llvm::IRBuilder<> tmp_builder(&(function->getEntryBlock()), function->getEntryBlock().begin());
            llvm::Function::arg_iterator arg_iter =  function->arg_begin();
            size_t idx = 0;
            for(size_t i = 0; i < ARRAY_SIZE(this->decl.proc_decl->head->params); i++){
                auto this_param = this->decl.proc_decl->head->params[i];
                bool isVal = this_param.flag;
                CompoundContext* cc;
                auto this_type = this_param.type->getLLVMType(ir, cc);

                for(size_t j = 0; j < ARRAY_SIZE(this_param.para_list); j++){
                    auto para_name = this_param.para_list[i].buffer;

                    if(isVal){
                        ir->GetBuilder().CreateStore(arg_iter++, 
                            tmp_builder.CreateAlloca(this_type, nullptr, para_name));
                        ir->AddVarDef(para_name, this_type, cc, false);
                    }
                    else{
                        ir->GetBuilder().CreateGEP(this_type, arg_iter, ir->GetBuilder().getInt32(0), para_name);
                        ir->AddVarDef(para_name, this_type->getPointerTo(), cc, false);
                    }
                    idx++;
                }
            }

            //subroutine
            this->decl.func_decl->sub_routine->generateIR(ir);

            //return
            ir->GetBuilder().CreateRetVoid();

            //pop
            ir->PopFuncStack();
            ir->GetBuilder().SetInsertPoint(&(ir->GetCurrentFunction())->getBasicBlockList().back());
        }
        break;
    default:
        break;
    }
}

void CompoundStatement::generateIR(IRGenerator* ir) {
    for(size_t i = 0; i < ARRAY_SIZE(this->list); i++){
        this->list[i].generateIR(ir);
    }
}

void Statement::generateIR(IRGenerator* ir){
    if(this->label != -1){
        //start of the block
        auto this_block = llvm::BasicBlock::Create(ir->GetContext(), std::string("label ").append(std::to_string(this->label)), ir->GetCurrentFunction());
        ir->GetBuilder().SetInsertPoint(this_block);
        ir->AddLabel(std::to_string(this->label), this_block);
    }
    
    switch (this->body->flag)
    {
    case NonLabelStatement::ASSIGN:
        this->body->statement.assign_statement->generateIR(ir);
        break;
    case NonLabelStatement::PROC:
        this->body->statement.proc_statement->generateIR(ir);
        break;
    case NonLabelStatement::COMPOUND:
        this->body->statement.compound_statement->generateIR(ir);
        break;
    case NonLabelStatement::IF:
        this->body->statement.if_statement->generateIR(ir);
        break;
    case NonLabelStatement::REPEAT:
        this->body->statement.repeat_statement->generateIR(ir);
        break;
    case NonLabelStatement::WHILE:
        this->body->statement.while_statement->generateIR(ir);
        break;
    case NonLabelStatement::FOR:
        this->body->statement.for_statment->generateIR(ir);
        break;
    case NonLabelStatement::CASE:
        this->body->statement.case_statement->generateIR(ir);
        break;
    case NonLabelStatement::GOTO:
        this->body->statement.goto_statement->generateIR(ir);
        break;
    default:
        break;
    }
}

void AssignStatement::generateIR(IRGenerator* ir) {
    switch (this->flag)
    {
    case AssignStatement::NORMAL:
        ir->GetBuilder().CreateStore(this->assign.normal_assign->value_expr->getLLVMValue(ir), ir->FindSymbolValue(this->assign.normal_assign->id->buffer));
        break;
    case AssignStatement::ARRAY:
        this->assign.array_assign->generateIR(ir);
        break;
    case AssignStatement::RECORD:
        this->assign.record_assign->generateIR(ir);
        break;
    default:
        break;
    }
}

llvm::Value* Expression::getLLVMValue(IRGenerator* ir){
    switch (this->type)
    {
    case Expression::GE:
        return ir->GetBuilder().CreateICmpSGE(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_GE");
        break;
    case Expression::GT:
        return ir->GetBuilder().CreateICmpSGT(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_GT");
        break;
    case Expression::LE:
        return ir->GetBuilder().CreateICmpSLE(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_LE");
        break;
    case Expression::LT:
        return ir->GetBuilder().CreateICmpSLT(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_LT");
        break;
    case Expression::EQUAL:
        return ir->GetBuilder().CreateICmpEQ(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_EQUAL");
        break;
    case Expression::UNEQUAL:
        return ir->GetBuilder().CreateICmpNE(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_UNEQUAL");
        break;
    case Expression::SINGLE:
        return this->rhs->getLLVMValue(ir);
        break;
    default:
        break;
    }
    return nullptr;
}

llvm::Value* Expr::getLLVMValue(IRGenerator* ir){
    if(this->type == Expr::SINGLE)
        return this->rhs->getLLVMValue(ir);

    
    bool fp_Flag = this->lhs->getLLVMValue(ir)->getType()->isDoubleTy() || this->rhs->getLLVMValue(ir)->getType()->isDoubleTy();
    switch (this->type)
    {
    case Expr::PLUS:
        return fp_Flag? ir->GetBuilder().CreateFAdd(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_FADD") 
            : ir->GetBuilder().CreateAdd(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_ADD");
        break;
    case Expr::MINUS:
        return fp_Flag? ir->GetBuilder().CreateFSub(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_FSUB") 
            : ir->GetBuilder().CreateSub(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_SUB");
        break;
    case Expr::OR:
        return ir->GetBuilder().CreateOr(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_OR");
        break;
    default:
        break;
    }
    return nullptr;
}

llvm::Value* Term::getLLVMValue(IRGenerator* ir){
    if(this->type == Term::SINGLE)
        return this->rhs->getLLVMValue(ir);

    
    bool fp_Flag = this->lhs->getLLVMValue(ir)->getType()->isDoubleTy() || this->rhs->getLLVMValue(ir)->getType()->isDoubleTy();
    switch (this->type)
    {
    case Term::MUL:
        return fp_Flag? ir->GetBuilder().CreateFMul(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_FMUL") 
            : ir->GetBuilder().CreateMul(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_MUL");
        break;
    case Term::DIV:
        return fp_Flag? ir->GetBuilder().CreateFDiv(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_FDIV") 
            : ir->GetBuilder().CreateSDiv(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_DIV");
        break;
    case Term::MOD:
        return ir->GetBuilder().CreateSRem(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_MOD");
        break;
    case Term::AND:
        return ir->GetBuilder().CreateAnd(this->lhs->getLLVMValue(ir), this->rhs->getLLVMValue(ir), "TMP_AND");
        break;
    default:
        break;
    }
    return nullptr;
}

llvm::Value* Factor::getLLVMValue(IRGenerator* ir){
    switch (this->flag)
    {
    case Factor::NAME:
        return this->factor.name_factor->getLLVMValue(ir);
        break;
    case Factor::FUNC:
        return this->factor.func_factor->getLLVMValue(ir);
        break;
    case Factor::SYS_FUNC:
        return this->factor.sys_func_factor->getLLVMValue(ir);
        break;
    case Factor::CONST:
        return this->factor.const_factor->getLLVMValue(ir);
        break;
    case Factor::EXPR:
        return this->factor.expr_factor->getLLVMValue(ir);
        break;
    case Factor::AT:
        return this->factor.at_factor->getLLVMValue(ir);
        break;
    case Factor::GET:
        return this->factor.get_factor->getLLVMValue(ir);
        break;
    case Factor::NOT:
        if(this->factor.not_factor->factor->getLLVMValue(ir)->getType()->isIntegerTy(1)){
            return ir->GetBuilder().CreateNot(this->factor.minus_factor->factor->getLLVMValue(ir), "TMP_NOT");
        }
        else{
            assert(false);
        }
        break;
    case Factor::MINUS:
        if(this->factor.minus_factor->factor->getLLVMValue(ir)->getType()->isDoubleTy()){
            return ir->GetBuilder().CreateFSub(llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), 0), 
                this->factor.minus_factor->factor->getLLVMValue(ir), "TMP_FSUB");
        }
        else if(this->factor.minus_factor->factor->getLLVMValue(ir)->getType()->isIntegerTy()){
            return ir->GetBuilder().CreateSub(ir->GetBuilder().getInt32(0), 
                this->factor.minus_factor->factor->getLLVMValue(ir), "TMP_SUB");
        }
        else{
            assert(false);
        }
        break;
    default:
        break;
    }
    return nullptr;
}

llvm::Constant* ConstValue::getLLVMValue(IRGenerator* ir){
    switch (this->flag)
    {
    case ConstValue::INT:
        return ir->GetBuilder().getInt32(this->value.int_value);
        break;
    case ConstValue::REAL:
        return llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), this->value.real_value);
        break;
    case ConstValue::CHAR:
        return ir->GetBuilder().getInt8(this->value.char_value);
        break;
    case ConstValue::SYS_CON:
        switch (this->value.sys_con_value)
        {
        case Sys_Con::TRUE:
            return ir->GetBuilder().getTrue();
            break;
        case Sys_Con::FALSE:
            return ir->GetBuilder().getFalse();
            break;
        case Sys_Con::MAXINT:
            return ir->GetBuilder().getInt32(INT32_MAX);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return nullptr;
}

llvm::Value* AtOperation::getLLVMValue(IRGenerator* ir){
    std::vector<llvm::Value*> idx_list;
    idx_list.push_back(ir->GetBuilder().getInt32(0));

    auto idx_value = this->index_expr->getLLVMValue(ir);
    assert(idx_value->getType()->isIntegerTy());
    auto p = ir->FindVarContext(this->array_id->buffer);
    assert(p.first->isArrayTy());

    auto ac = static_cast<ArrayContext*>(p.second);

    idx_list.push_back(ir->GetBuilder().CreateSub(idx_value, ir->GetBuilder().getInt32(ac->range.first)));

    return ir->GetBuilder().CreateLoad(p.first->getArrayElementType(), 
        ir->GetBuilder().CreateInBoundsGEP(p.first, 
            ir->FindSymbolValue(this->array_id->buffer), idx_list), "arrRef");
}

llvm::Value* GetOperation::getLLVMValue(IRGenerator* ir){
    auto p = ir->FindVarContext(this->record_id->buffer);
    assert(p.first->isStructTy());

    auto rc = static_cast<RecordContext*>(p.second);

    auto iter = rc->field_map.find(this->field_id->buffer);
    assert(iter != rc->field_map.end());
    
    return ir->GetBuilder().CreateLoad(
        p.first->getStructElementType(iter->second), 
        ir->GetBuilder().CreateStructGEP(p.first, 
            ir->FindSymbolValue(this->record_id->buffer), iter->second));
}

llvm::Value* FunctionCall::getLLVMValue(IRGenerator* ir){
    std::vector<llvm::Value*> params;

    auto function = ir->GetModulePt()->getFunction(this->func_name->buffer);
    auto cxt = ir->FindCallContext(this->func_name->buffer);
    auto arg_iter = function->arg_begin();
    for(size_t i = 0; i < ARRAY_SIZE(this->args); i++){
        if(cxt->params_context[i]->para_llvm_type->isPointerTy()){
            //ref
            assert(this->args[i].type == Expression::SINGLE 
                && this->args[i].rhs->type == Expr::SINGLE 
                && this->args[i].rhs->rhs->type == Term::SINGLE 
                && this->args[i].rhs->rhs->rhs->flag == Factor::NAME);
            auto ref_name = this->args[i].rhs->rhs->rhs->factor.name_factor;
            params.push_back(ir->FindSymbolValue(ref_name->buffer));
        }
        else{
            params.push_back(this->args[i].getLLVMValue(ir));
        }
        arg_iter++;
    }

    return ir->GetBuilder().CreateCall(function, params);
}

void ArrayAssignment::generateIR(IRGenerator* ir){
    std::vector<llvm::Value*> idx_list;
    idx_list.push_back(ir->GetBuilder().getInt32(0));

    auto idx_value = this->index_expr->getLLVMValue(ir);
    assert(idx_value->getType()->isIntegerTy());
    auto p = ir->FindVarContext(this->array_id->buffer);
    assert(p.first->isArrayTy());

    auto ac = static_cast<ArrayContext*>(p.second);

    idx_list.push_back(ir->GetBuilder().CreateSub(idx_value, ir->GetBuilder().getInt32(ac->range.first)));
    
    ir->GetBuilder().CreateStore(this->value_expr->getLLVMValue(ir), 
        ir->GetBuilder().CreateInBoundsGEP(p.first, ir->FindSymbolValue(this->array_id->buffer), idx_list));
}

void RecordAssignment::generateIR(IRGenerator* ir){
    auto p = ir->FindVarContext(this->record_id->buffer);
    assert(p.first->isStructTy());

    auto rc = static_cast<RecordContext*>(p.second);

    auto iter = rc->field_map.find(this->field_expr->buffer);
    assert(iter != rc->field_map.end());

    ir->GetBuilder().CreateStore(this->value_expr->getLLVMValue(ir), 
        ir->GetBuilder().CreateStructGEP(p.first, ir->FindSymbolValue(this->record_id->buffer), iter->second));
}

void IfStatement::generateIR(IRGenerator* ir){
    llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(ir->GetContext(), "if.then", ir->GetCurrentFunction());
    llvm::BasicBlock* elseBlock = llvm::BasicBlock::Create(ir->GetContext(), "if.else", ir->GetCurrentFunction());
    llvm::BasicBlock* endBlock = llvm::BasicBlock::Create(ir->GetContext(), "if.end", ir->GetCurrentFunction());

    auto expr = this->judge_expr->getLLVMValue(ir);
    ir->GetBuilder().CreateCondBr(
        ir->GetBuilder().CreateICmpNE(expr, ir->GetBuilder().getFalse(), "IF_COND"), thenBlock, elseBlock);
    ir->GetBuilder().SetInsertPoint(thenBlock);
    this->statement1->generateIR(ir);
    ir->GetBuilder().CreateBr(endBlock);


    ir->GetBuilder().SetInsertPoint(elseBlock);
    if (this->statement2 != nullptr)
    {
        this->statement2->generateIR(ir);
    }
    ir->GetBuilder().CreateBr(endBlock);


    ir->GetBuilder().SetInsertPoint(endBlock);
}

void RepeatStatement::generateIR(IRGenerator* ir) {
    llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ir->GetContext(), "cond", ir->GetCurrentFunction());
    llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(ir->GetContext(), "loop", ir->GetCurrentFunction());
    llvm::BasicBlock *finalBlock = llvm::BasicBlock::Create(ir->GetContext(), "final", ir->GetCurrentFunction());
    
    //Loop
    ir->GetBuilder().CreateBr(loopBlock);
    ir->GetBuilder().SetInsertPoint(loopBlock);
    
    for(size_t i = 0; i < ARRAY_SIZE(this->repeat_list); i++){
        this->repeat_list[i].generateIR(ir);
    }

    ir->GetBuilder().CreateBr(condBlock);
    loopBlock = ir->GetBuilder().GetInsertBlock();
    
    //Cond
    ir->GetBuilder().SetInsertPoint(condBlock);
    auto expr = this->until_expr->getLLVMValue(ir);
    ir->GetBuilder().CreateCondBr(
        ir->GetBuilder().CreateICmpNE(expr, ir->GetBuilder().getFalse(), "RP_COND"), loopBlock, finalBlock);
    
    //Final
    ir->GetBuilder().SetInsertPoint(finalBlock);
}

void WhileStatement::generateIR(IRGenerator* ir){
    llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ir->GetContext(), "cond", ir->GetCurrentFunction());
    llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(ir->GetContext(), "loop", ir->GetCurrentFunction());
    llvm::BasicBlock *finalBlock = llvm::BasicBlock::Create(ir->GetContext(), "final", ir->GetCurrentFunction());
    
    //Cond
    ir->GetBuilder().CreateBr(condBlock);
    ir->GetBuilder().SetInsertPoint(condBlock);
    auto expr = this->judge_expr->getLLVMValue(ir);
    ir->GetBuilder().CreateCondBr(
        ir->GetBuilder().CreateICmpNE(expr, ir->GetBuilder().getFalse(), "WHILE_COND"), loopBlock, finalBlock);
    condBlock = ir->GetBuilder().GetInsertBlock();

    //Loop
    ir->GetBuilder().SetInsertPoint(loopBlock);
    this->statement->generateIR(ir);
    ir->GetBuilder().CreateBr(condBlock);
    
    //Final
    ir->GetBuilder().SetInsertPoint(finalBlock);
}

void ForStatement::generateIR(IRGenerator* ir){

    //init
    llvm::Value* cond_value = nullptr;
    llvm::Value* startValue = this->start_expr->getLLVMValue(ir);
    llvm::Value* endValue = this->end_expr->getLLVMValue(ir);
    llvm::Value* iter_value = ir->FindSymbolValue(this->iter_id->buffer);
    ir->GetBuilder().CreateStore(startValue, iter_value);
    
    llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ir->GetContext(), "cond", ir->GetCurrentFunction());
    llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(ir->GetContext(), "loop", ir->GetCurrentFunction());
    llvm::BasicBlock *finalBlock = llvm::BasicBlock::Create(ir->GetContext(), "final", ir->GetCurrentFunction());
    
    //Cond
    ir->GetBuilder().CreateBr(condBlock);
    ir->GetBuilder().SetInsertPoint(condBlock);
    auto curValue = this->iter_id->getLLVMValue(ir);
    if (this->type == ForStatement::TO)
    {
        cond_value = ir->GetBuilder().CreateICmpSLE(curValue, endValue);
    }
    else
    {
        cond_value = ir->GetBuilder().CreateICmpSGE(curValue, endValue);
    }
    ir->GetBuilder().CreateCondBr(
        ir->GetBuilder().CreateICmpNE(cond_value, ir->GetBuilder().getFalse(), "forCond"), loopBlock, finalBlock);
    condBlock = ir->GetBuilder().GetInsertBlock();
    
    //Loop
    ir->GetBuilder().SetInsertPoint(loopBlock);
    this->statement->generateIR(ir);
    llvm::Value* tmpValue = ir->GetBuilder().CreateAdd(curValue, 
        ir->GetBuilder().getInt32(this->type == ForStatement::TO ? 1 : -1));
    ir->GetBuilder().CreateStore(tmpValue, iter_value);
    ir->GetBuilder().CreateBr(condBlock);
    
    //After
    ir->GetBuilder().SetInsertPoint(finalBlock);
}

llvm::Value* Identifier::getLLVMValue(IRGenerator* ir){
    return new llvm::LoadInst(ir->FindVarContext(this->buffer).first, ir->FindSymbolValue(this->buffer), "tmp", false, ir->GetBuilder().GetInsertBlock());
}

void CaseStatement::generateIR(IRGenerator* ir){
    llvm::Value* judge_val = this->judge_expression->getLLVMValue(ir);

    llvm::BasicBlock* finalBlock = llvm::BasicBlock::Create(ir->GetContext(), "final", ir->GetCurrentFunction());
    std::vector<llvm::BasicBlock*> switchBlocks, caseBlocks;
    for (int i = 0; i < ARRAY_SIZE(this->case_list); i++)
    {
        switchBlocks.push_back(llvm::BasicBlock::Create(ir->GetContext(), "switch", ir->GetCurrentFunction()));
        caseBlocks.push_back(llvm::BasicBlock::Create(ir->GetContext(), "case", ir->GetCurrentFunction()));
    }

    ir->GetBuilder().CreateBr(switchBlocks[0]);
    for (size_t i = 0; i < ARRAY_SIZE(this->case_list); i++)
    {
        //Switch
        ir->GetBuilder().SetInsertPoint(switchBlocks[i]);
        llvm::Value* cond_value = nullptr;
        if(this->case_list[i].type == CaseExpression::ID_CASE){
            cond_value = this->case_list[i].id->getLLVMValue(ir);
        }
        else{
            cond_value = this->case_list[i].value->getLLVMValue(ir);
        }
        
        if (i < ARRAY_SIZE(this->case_list) - 1)
        {
            ir->GetBuilder().CreateCondBr(
                ir->GetBuilder().CreateICmpEQ(judge_val, cond_value, "tmpEQ"), caseBlocks[i], switchBlocks[i + 1]);
        }
        else
        {
            ir->GetBuilder().CreateCondBr(
                ir->GetBuilder().CreateICmpEQ(judge_val, cond_value, "tmpEQ"), caseBlocks[i], finalBlock);
        }
        
        //Case
        ir->GetBuilder().SetInsertPoint(caseBlocks[i]);
        this->case_list[i].statement->generateIR(ir);
        ir->GetBuilder().CreateBr(finalBlock);
    }
    
    //After
    ir->GetBuilder().SetInsertPoint(finalBlock);
}

void GotoStatement::generateIR(IRGenerator* ir){
    auto target = ir->FindLabel(std::to_string(this->target_label));

    assert(target != nullptr);

    ir->GetBuilder().CreateBr(target);
}

void ProcStatement::generateIR(IRGenerator* ir){
    switch (this->flag)
    {
    case ProcStatement::PROC:
        {
            std::vector<llvm::Value*> params;
            auto function = ir->GetModulePt()->getFunction(this->proc.normal_proc->id->buffer);
            auto cxt = ir->FindCallContext(this->proc.normal_proc->id->buffer);
            
            auto arg_iter = function->arg_begin();
            for(size_t i = 0; i < ARRAY_SIZE(this->proc.normal_proc->arg_list); i++){
                if(cxt->params_context[i]->para_llvm_type->isPointerTy()){
                    //ref
                    assert(this->proc.normal_proc->arg_list[i].type == Expression::SINGLE 
                        && this->proc.normal_proc->arg_list[i].rhs->type == Expr::SINGLE 
                        && this->proc.normal_proc->arg_list[i].rhs->rhs->type == Term::SINGLE 
                        && this->proc.normal_proc->arg_list[i].rhs->rhs->rhs->flag == Factor::NAME);
                    auto ref_name = this->proc.normal_proc->arg_list[i].rhs->rhs->rhs->factor.name_factor;
                    params.push_back(ir->FindSymbolValue(ref_name->buffer));
                }
                else{
                    params.push_back(this->proc.normal_proc->arg_list[i].getLLVMValue(ir));
                }
                arg_iter++;
            }

            ir->GetBuilder().CreateCall(function, params);
        }
        break;
    case ProcStatement::SYS_PROC:
        {
            std::vector<llvm::Value*> params;
            std::string format = "";
            for(size_t i = 0; i < ARRAY_SIZE(this->proc.sys_proc->arg_list); i++){
                auto val = this->proc.normal_proc->arg_list[i].getLLVMValue(ir);
                if (val->getType() == ir->GetBuilder().getInt32Ty()){
                    format += "%d";
                }
                else if (val->getType() == ir->GetBuilder().getInt8Ty()){
                    format += "%c";
                }
                else if (val->getType() == ir->GetBuilder().getInt1Ty()){
                    format += "%d";
                }
                else if (val->getType() == ir->GetBuilder().getDoubleTy()){
                    format += "%lf";
                }
                else{
                    assert(false);
                }
                params.push_back(val);
            }

            if(this->proc.sys_proc->proc == Sys_Proc::WRITELN){
                format += "\n";
            }

            auto formatVar = new llvm::GlobalVariable(*(ir->GetModulePt()), 
                llvm::ArrayType::get(ir->GetBuilder().getInt8Ty(), format.size() + 1), true, 
                llvm::GlobalValue::ExternalLinkage, 
                llvm::ConstantDataArray::getString(ir->GetContext(), format.c_str()), ".str");
            auto zero = llvm::Constant::getNullValue(ir->GetBuilder().getInt32Ty());
            llvm::Constant* indices[] = {zero, zero};
            auto varRef = llvm::ConstantExpr::getGetElementPtr(formatVar->getType()->getPointerElementType(), formatVar, indices);
            params.insert(params.begin(), varRef);
            ir->GetBuilder().CreateCall(ir->GetPrintf(), llvm::makeArrayRef(params), "printf");
        }
        break;
    case ProcStatement::READ_PROC:
        {
            std::string format = "";
            std::vector<llvm::Value*> params;
            assert(this->proc.read_proc->value->flag == Factor::NAME);
            auto arg = this->proc.read_proc->value->factor.name_factor;
            auto t = ir->FindVarContext(arg->buffer).first;

            if (t->isIntegerTy(32)){
                format += "%d";
            }
            else if (t->isIntegerTy(8)){
                format += "%c";
            }
            else if (t->isIntegerTy(1)){
                format += "%d";
            }
            else if (t->isDoubleTy()){
                format += "%lf";
            }
            else{
                assert(false);
            }
            params.push_back(ir->FindSymbolValue(arg->buffer));
            params.insert(params.begin(), ir->GetBuilder().CreateGlobalStringPtr(format));
            ir->GetBuilder().CreateCall(ir->GetScanf(), params, "scanf");
        }
        break;
    default:
        break;
    }
}

llvm::Value* SysFuncCall::getLLVMValue(IRGenerator* ir){
    assert(ARRAY_SIZE(this->args) == 1);

    auto param = this->args[0];
    auto val = param.getLLVMValue(ir);
    auto t = val->getType();
    
    switch (this->sys_func)
    {
    case Sys_Funct::ABS:
        assert(t->isIntegerTy() || t->isDoubleTy());
        if(t->isIntegerTy(32))
            return ir->GetBuilder().getInt32(
                llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() > 0 ? 
                llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() : 
                -llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue());
        else if(t->isIntegerTy(8))
            return ir->GetBuilder().getInt8(
                llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() > 0 ? 
                llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() : 
                -llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue());
        else
            return llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), 
                llvm::dyn_cast<llvm::ConstantFP>(val)->getValueAPF().convertToDouble() > 0 ? 
                llvm::dyn_cast<llvm::ConstantFP>(val)->getValueAPF().convertToDouble() : 
                -llvm::dyn_cast<llvm::ConstantFP>(val)->getValueAPF().convertToDouble());
        break;
    case Sys_Funct::CHR:
        assert(t->isIntegerTy(32));
        return ir->GetBuilder().getInt8(llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue());
        break;
    case Sys_Funct::ODD:
        assert(t->isIntegerTy());
        if (llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() % 2)
            return ir->GetBuilder().getTrue();
        else 
            return ir->GetBuilder().getFalse();
        break;
    case Sys_Funct::ORD:
        assert(t->isIntegerTy(8));
        return ir->GetBuilder().getInt32(llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue());
        break;
    case Sys_Funct::PRED:
        assert(t->isIntegerTy());
        if(t->isIntegerTy(32))
            return ir->GetBuilder().getInt32(llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() - 1);
        else
            return ir->GetBuilder().getInt8(llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() - 1);
        break;
    case Sys_Funct::SQR:
        assert(t->isIntegerTy() || t->isDoubleTy());
        if (t->isDoubleTy())
            return llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), 
                    llvm::dyn_cast<llvm::ConstantFP>(val)->getValueAPF().convertToDouble() * 
                    llvm::dyn_cast<llvm::ConstantFP>(val)->getValueAPF().convertToDouble()
                    );
        else
            return llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), 
                    llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() * 
                    llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue()
                    );
        break;
    case Sys_Funct::SQRT:
        assert(t->isIntegerTy() || t->isDoubleTy());
        if (t->isDoubleTy())
            return llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), 
                    sqrt(llvm::dyn_cast<llvm::ConstantFP>(val)->getValueAPF().convertToDouble())
                    );
        else
            return llvm::ConstantFP::get(ir->GetBuilder().getDoubleTy(), 
                    sqrt(llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue())
                    );
        break;
    case Sys_Funct::SUCC:
        assert(t->isIntegerTy());
        if(t->isIntegerTy(32))
            return ir->GetBuilder().getInt32(llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() + 1);
        else
            return ir->GetBuilder().getInt8(llvm::dyn_cast<llvm::ConstantInt>(val)->getSExtValue() + 1);
        break;
    default:
        break;
    }
    return nullptr;
}