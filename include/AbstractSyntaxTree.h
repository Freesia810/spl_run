#pragma once


#include <algorithm>
#include <malloc.h>
#include <cmath>
#include <cstring>
#include "generator/IRGenerator.h"
#include "cJSON.h"
#define ARRAY_SIZE(p) malloc_usable_size(p) / sizeof(p[0])

struct Expression;
struct Factor;
struct Statement;
struct CompoundStatement;
struct TypeDecl;
struct CallDecl;
struct Routine;


template<typename T>
T* AddElement(T* lhs, T* rhs){
    T* res = nullptr;
    if(lhs == nullptr){
        res = rhs;
        return res;
    }
    else{
        res = new T[ARRAY_SIZE(lhs)+1];
        memmove(res, lhs, malloc_usable_size(lhs));
        memmove(&res[ARRAY_SIZE(lhs)], rhs, malloc_usable_size(rhs));
        delete lhs;
        return res;
    }
};


template<typename T>
void TraversalItem(cJSON* obj, T* p, const char* des){
    auto const_array = cJSON_CreateArray();
    for(size_t i = 0; i < ARRAY_SIZE(p); i++){
        cJSON_AddItemToArray(const_array, p[i].createJSONObj());
    }
    cJSON_AddItemToObject(obj, des, const_array);
};

struct AbstractNode{
    char description[64];
    cJSON* this_obj;
    virtual cJSON* createJSONObj(){ return nullptr; };
    virtual void generateIR(IRGenerator*){};
};

enum Sys_Con{
    FALSE,
    MAXINT,
    TRUE
};

enum Sys_Funct{
    ABS,
    CHR,
    ODD,
    ORD,
    PRED,
    SQR,
    SQRT,
    SUCC
};

enum Sys_Proc{
    WRITE,
    WRITELN
};

struct Statement;
struct Expression;

using StatementList = Statement*;
using ExpressionList = Expression*;

struct ConstValue : public AbstractNode{
    union {
        int int_value;
        double real_value;
        char char_value;
        Sys_Con sys_con_value;
    } value;

    enum{
        INT,
        REAL,
        CHAR,
        SYS_CON
    } flag;

    cJSON* createJSONObj();
    llvm::Constant* getLLVMValue(IRGenerator*);
};

struct Identifier : public AbstractNode{
    char buffer[64];
    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

using NameList = Identifier*;

struct FunctionCall: public AbstractNode{
    Identifier* func_name;
    ExpressionList args;
    FunctionCall(Identifier* n, Expression* a): func_name(n), args(a){};
    FunctionCall() = default;
    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct SysFuncCall: public AbstractNode{
    Sys_Funct sys_func;
    ExpressionList args;
    SysFuncCall(Sys_Funct f, Expression* a): sys_func(f), args(a){};
    SysFuncCall() = default;
    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct AtOperation: public AbstractNode{
    Identifier* array_id;
    Expression* index_expr;

    AtOperation(Identifier* id, Expression* idx): array_id(id), index_expr(idx){};
    AtOperation() = default;
    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct GetOperation: public AbstractNode{
    Identifier* record_id;
    Identifier* field_id;

    GetOperation(Identifier* rec, Identifier* field): record_id(rec), field_id(field){};
    GetOperation() = default;

    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct NotFactor: public AbstractNode{
    Factor* factor;
    NotFactor(Factor* f): factor(f){};
    NotFactor() = default;
    cJSON* createJSONObj();
};

struct MinusFactor: public AbstractNode{
    Factor* factor;
    MinusFactor(Factor* f): factor(f){};
    MinusFactor() = default;
    cJSON* createJSONObj();
};

struct Factor: public AbstractNode{
    union {
        Identifier* name_factor;
        FunctionCall* func_factor;
        SysFuncCall* sys_func_factor;
        ConstValue* const_factor;
        Expression* expr_factor;
        AtOperation* at_factor;
        GetOperation* get_factor;
        NotFactor* not_factor;
        MinusFactor* minus_factor;
    } factor;

    enum {
        NAME,
        FUNC,
        SYS_FUNC,
        CONST,
        EXPR,
        AT,
        GET,
        NOT,
        MINUS
    } flag;
    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct Term: public AbstractNode{
    Term* lhs;
    Factor* rhs;
    enum Type{
        MUL,
        DIV,
        MOD,
        AND,
        SINGLE
    } type;
    Term(Term* l, Factor* r, Type t): lhs(l), rhs(r), type(t){};
    Term() = default;
    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct Expr: public AbstractNode{
    Expr* lhs;
    Term* rhs;
    enum Type{
        PLUS,
        MINUS,
        OR,
        SINGLE
    } type;
    Expr(Expr* l, Term* r, Type t):lhs(l), rhs(r), type(t){};
    Expr() = default;
    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct Expression: public AbstractNode{
    Expression* lhs;
    Expr* rhs;
    enum Type{
        GE,
        GT,
        LE,
        LT,
        EQUAL,
        UNEQUAL,
        SINGLE
    } type;
    Expression(Expression* l, Expr* r, Type t): lhs(l), rhs(r), type(t){};
    Expression() = default;

    cJSON* createJSONObj();
    llvm::Value* getLLVMValue(IRGenerator*);
};

struct NormalAssignment: public AbstractNode{
    Identifier* id;
    Expression* value_expr;
    NormalAssignment(Identifier* i, Expression* e): id(i), value_expr(e){};
    NormalAssignment() = default;

    cJSON* createJSONObj();
};

struct ArrayAssignment: public AbstractNode{
    Identifier* array_id;
    Expression* index_expr;
    Expression* value_expr;
    ArrayAssignment(Identifier* a, Expression* i, Expression* v): array_id(a), index_expr(i), value_expr(v){};
    ArrayAssignment() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct RecordAssignment: public AbstractNode{
    Identifier* record_id;
    Identifier* field_expr;
    Expression* value_expr;
    RecordAssignment(Identifier* r, Identifier* f, Expression* v): record_id(r), field_expr(f), value_expr(v){};
    RecordAssignment() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct AssignStatement: public AbstractNode{
    union{
        NormalAssignment* normal_assign;
        ArrayAssignment* array_assign;
        RecordAssignment* record_assign;
    } assign;
    
    enum{
        NORMAL,
        ARRAY,
        RECORD
    } flag;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct IfStatement: public AbstractNode{
    Expression* judge_expr;
    Statement* statement1;
    Statement* statement2;
    IfStatement(Expression* j, Statement* s1, Statement* s2): judge_expr(j), statement1(s1), statement2(s2){};
    IfStatement() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct RepeatStatement: public AbstractNode{
    StatementList repeat_list;
    Expression* until_expr;
    RepeatStatement(Statement* r, Expression* u): repeat_list(r), until_expr(u){};
    RepeatStatement() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct WhileStatement: public AbstractNode{
    Expression* judge_expr;
    Statement* statement;
    WhileStatement(Expression* j, Statement* s): judge_expr(j), statement(s){};
    WhileStatement() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct ForStatement: public AbstractNode{
    Identifier* iter_id;
    Expression* start_expr;
    enum For_Type{
        TO,
        DOWNTO
    } type;
    Expression* end_expr;
    Statement* statement;
    ForStatement() = default;
    ForStatement(Identifier* i, Expression* s, For_Type t, Expression* e, Statement* x): iter_id(i), start_expr(s), type(t), end_expr(e), statement(x){};

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct GotoStatement: public AbstractNode{
    int target_label{-1};
    GotoStatement(int l): target_label(l){};
    GotoStatement() = default;
    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct CaseExpression: public AbstractNode{
    Identifier* id;
    ConstValue* value;
    Statement* statement;
    enum Type{
        ID_CASE,
        CONST_CASE
    } type;
    CaseExpression(Identifier* i, ConstValue* v, Statement* s, Type t): id(i), value(v), statement(s), type(t){};
    CaseExpression() = default;

    cJSON* createJSONObj();
};

using CaseExpressionList = CaseExpression*;

struct CaseStatement: public AbstractNode{
    Expression* judge_expression;
    CaseExpressionList case_list;
    CaseStatement(Expression* j, CaseExpression* c): judge_expression(j), case_list(c){};
    CaseStatement() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct Procedure: public AbstractNode{
    Identifier* id;
    ExpressionList arg_list;
    Procedure(Identifier* i, ExpressionList a): id(i), arg_list(a) {};
    Procedure() = default;

    cJSON* createJSONObj();
};

struct SystemProcedure: public AbstractNode{
    Sys_Proc proc;
    ExpressionList arg_list;
    SystemProcedure(Sys_Proc p, ExpressionList a): proc(p), arg_list(a){};
    SystemProcedure() = default;

    cJSON* createJSONObj();
};

struct ReadProcedure: public AbstractNode{
    Factor* value;
    ReadProcedure(Factor* v): value(v){};
    ReadProcedure() = default;

    cJSON* createJSONObj();
};

struct ProcStatement: public AbstractNode{
    union{
        Procedure* normal_proc;
        SystemProcedure* sys_proc;
        ReadProcedure* read_proc;
    } proc;
    
    enum{
        PROC,
        SYS_PROC,
        READ_PROC
    } flag;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct NonLabelStatement: public AbstractNode{
    union{
        AssignStatement* assign_statement;
        ProcStatement* proc_statement;
        CompoundStatement* compound_statement;
        IfStatement* if_statement;
        RepeatStatement* repeat_statement;
        WhileStatement* while_statement;
        ForStatement* for_statment;
        CaseStatement* case_statement;
        GotoStatement* goto_statement;
    } statement;

    enum{
        ASSIGN,
        PROC,
        COMPOUND,
        IF,
        REPEAT,
        WHILE,
        FOR,
        CASE,
        GOTO
    } flag;

    cJSON* createJSONObj();
};

struct Statement: public AbstractNode{
    NonLabelStatement* body;
    int label;
    Statement(NonLabelStatement* b, int l): body(b), label(l){};
    Statement() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct CompoundStatement: public AbstractNode{
    StatementList list;
    CompoundStatement(Statement* l): list(l){};
    CompoundStatement() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

struct LabelPart: public AbstractNode{
    /* data */
};

struct ConstExprssion: public AbstractNode{
    Identifier* name;
    ConstValue* value;
    bool global{false};
    ConstExprssion(Identifier* n, ConstValue* v): name(n), value(v){};
    ConstExprssion() = default;
    void generateIR(IRGenerator*) override;
    cJSON* createJSONObj();
};

struct NormalDecl: public AbstractNode{
    NameList name_list;
    TypeDecl* type_decl;
    bool global{false};
    NormalDecl(NameList n, TypeDecl* t): name_list(n), type_decl(t){};
    NormalDecl() = default;

    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

using NormalDeclList = NormalDecl*;

struct RecordTypeDecl: public AbstractNode{
    NormalDeclList field_decl_list;
    RecordTypeDecl(NormalDecl* f): field_decl_list(f){};
    RecordTypeDecl() = default;

    cJSON* createJSONObj();
};

struct RangeTypeDecl: public AbstractNode{
    ConstValue* c_lhs;
    ConstValue* c_rhs;
    Identifier* n_lhs;
    Identifier* n_rhs;
    enum{
        POS_POS,
        NEG_POS,
        NEG_NEG,
        NAME_NAME
    } type;
    cJSON* createJSONObj();
};

struct SimpleTypeDecl: public AbstractNode{
    union {
        Sys_Type sys_type_decl;
        Identifier* name_type_decl;
        NameList name_list_decl;
        RangeTypeDecl* range_type_decl;
    } type_decl;
    
    enum {
        SYS_TYPE,
        NAME,
        NAME_LIST,
        RANGE_TYPE
    } flag;
    cJSON* createJSONObj();
    llvm::Type* getLLVMType(IRGenerator*, CompoundContext*&);
};

struct ArrayTypeDecl: public AbstractNode{
    SimpleTypeDecl* range_decl;
    TypeDecl* element_decl;

    ArrayTypeDecl(SimpleTypeDecl* r, TypeDecl* e): range_decl(r), element_decl(e){};
    ArrayTypeDecl() = default;
    cJSON* createJSONObj();
};

struct TypeDecl: public AbstractNode{
    union{
        SimpleTypeDecl* simple_decl;
        ArrayTypeDecl* array_decl;
        RecordTypeDecl* record_decl;
    } decl;
    enum{
        SIMPLE,
        ARRAY,
        RECORD
    } flag;
    cJSON* createJSONObj();
    llvm::Type* getLLVMType(IRGenerator*, CompoundContext*&);
};

struct TypeDefinition: public AbstractNode{
    Identifier* name;
    TypeDecl* value;
    bool global{false};
    TypeDefinition(Identifier* n, TypeDecl* v): name(n), value(v){};
    TypeDefinition() = default;
    cJSON* createJSONObj();
    void generateIR(IRGenerator*) override;
};

using VarPart = NormalDecl*;
using ConstPart = ConstExprssion*;
using TypePart = TypeDefinition*;
using RoutinePart = CallDecl*;

struct RoutineHead: public AbstractNode{
    LabelPart* label_part;
    ConstPart const_part;
    TypePart type_part;
    VarPart var_part;
    RoutinePart routine_part;
    RoutineHead() = default;
    cJSON* createJSONObj() override;
    void flagGlobal();
    void generateIR(IRGenerator*) override;
    RoutineHead(LabelPart* l, ConstPart c, TypePart t, VarPart v, RoutinePart r): label_part(l), const_part(c), type_part(t), var_part(v), routine_part(r){};
};

struct ParaTypeList: public AbstractNode{
    NameList para_list;
    SimpleTypeDecl* type;

    enum {
        VAR,
        VAL
    } flag;

    cJSON* createJSONObj();
};

using Params = ParaTypeList*;

struct FunctionHead: public AbstractNode{
    Identifier* func_name;
    Params params;
    SimpleTypeDecl* ret;
    FunctionHead() = default;
    FunctionHead(Identifier* f, ParaTypeList* p, SimpleTypeDecl* r): func_name(f), params(p), ret(r){};

    cJSON* createJSONObj();
};

struct FunctionDecl: public AbstractNode{
    FunctionHead* head;
    Routine* sub_routine;
    FunctionDecl() = default;
    FunctionDecl(FunctionHead* h, Routine* r): head(h), sub_routine(r){};
    cJSON* createJSONObj();
};

struct ProcedureHead: public AbstractNode{
    Identifier* func_name;
    Params params;
    ProcedureHead() = default;
    ProcedureHead(Identifier* f, ParaTypeList* p): func_name(f), params(p){};

    cJSON* createJSONObj();
};

struct ProcedureDecl: public AbstractNode{
    ProcedureHead* head;
    Routine* sub_routine;
    ProcedureDecl() = default;
    ProcedureDecl(ProcedureHead* h, Routine* r): head(h), sub_routine(r){};
};

struct CallDecl: public AbstractNode
{
    union{
        FunctionDecl* func_decl;
        ProcedureDecl* proc_decl;
    } decl;
    
    enum {
        FUNC,
        PROC
    } flag;

    cJSON* createJSONObj();
    void generateIR(IRGenerator* ir);
};

struct Routine: public AbstractNode{
    RoutineHead* routine_head;
    CompoundStatement* routine_body;
    bool isGlobal;
    Routine() = default;
    Routine(RoutineHead* h, CompoundStatement* b, bool bo): routine_head(h), routine_body(b), isGlobal(bo){};
    cJSON* createJSONObj() override;
    void generateIR(IRGenerator* ir);
};

struct ProgramId: public AbstractNode{
    char id[64];
    cJSON* createJSONObj() override;
};

struct Program: public AbstractNode{
    ProgramId* program_id;
    Routine* routine;
    Program() = default;
    Program(ProgramId* i, Routine* r): program_id(i), routine(r){};
    cJSON* createJSONObj() override;
    void generateIR(IRGenerator* ir);
};

