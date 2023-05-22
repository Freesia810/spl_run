#include "AbstractSyntaxTree.h"
#include "cJSON.h"
#include <string>

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
    case Sys_Proc::WRITE:
        cJSON_AddStringToObject(this->this_obj, "id", "WRITE");
        break;
    case Sys_Proc::WRITELN:
        cJSON_AddStringToObject(this->this_obj, "id", "WRITELN");
        break;
    default:
        break;
    }
    if(this->args != nullptr)
        TraversalItem<Expression>(this->this_obj, this->args, "args");
    return this->this_obj;
}