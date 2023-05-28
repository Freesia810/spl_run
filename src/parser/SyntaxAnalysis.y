%{
#include "AbstractSyntaxTree.h"
#include <cstring>
#include <cstdio>

void yyerror(const char *s) { 
    printf("Error: %s\n", s);
    exit(1); 
}

int yylex(void);

Program* syntax_root;

%}
%define parse.error verbose
%union {
    int int_value;
    double real_value;
    char str_value[64];
    char char_value;
    Program* program;
    ProgramId* program_head;
    Routine* routine;
    RoutineHead* routine_head;
    CompoundStatement* routine_body;
    ConstValue* const_value;
    ConstExprssion* const_expr;
    TypeDefinition* type_definition;
    NormalDecl* normal_decl;
    CallDecl* call_decl;
    TypeDecl* type_decl;
    SimpleTypeDecl* simple_type_decl;
    ArrayTypeDecl* array_type_decl;
    RecordTypeDecl* record_type_decl;
    Identifier* identifier;
    FunctionDecl* function_decl;
    ProcedureDecl* procedure_decl;
    FunctionHead* function_head;
    ProcedureHead* procedure_head;
    ParaTypeList* para_type_list;
    Statement* statement;
    NonLabelStatement* non_label_stmt;
    AssignStatement* assign_stmt;
    ProcStatement* proc_stmt;
    Expression* expression;
    Expr* expr;
    Term* term;
    Factor* factor;
    IfStatement* if_stmt;
    RepeatStatement* repeat_stmt;
    WhileStatement* while_stmt;
    ForStatement* for_stmt;
    CaseStatement* case_stmt;
    CaseExpression* case_expr;
    GotoStatement* goto_stmt;
    CompoundStatement* compound_stmt;
    ForStatement::For_Type direction;
}

%token  LP RP LB RB DOT COMMA COLON
        MUL UNEQUAL NOT PLUS MINUS
        GE GT LE LT EQUAL ASSIGN MOD DOTDOT
        SEMI
        AND ARRAY SPL_BEGIN CASE CONST
        DIV DO DOWNTO ELSE END
        FOR FUNCTION GOTO
        IF OF OR ENDIF
        PROCEDURE PROGRAM RECORD REPEAT
        THEN TO TYPE UNTIL VAR WHILE
%token<int_value> INTEGER
%token<str_value> IDENTIFIER SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE READ
%token<real_value> REAL
%token<char_value> CHAR


%type<program>                          program
%type<program_head>                     program_head
%type<routine>                          routine sub_routine
%type<routine_head>                     routine_head
%type<routine_body>                     routine_body
%type<const_expr>                       const_part const_expr_list
%type<const_value>                      const_value
%type<type_definition>                  type_part type_decl_list type_definition
%type<normal_decl>                      var_part var_decl_list var_decl field_decl_list field_decl
%type<call_decl>                        routine_part
%type<type_decl>                        type_decl
%type<simple_type_decl>                 simple_type_decl
%type<array_type_decl>                  array_type_decl
%type<record_type_decl>                 record_type_decl
%type<identifier>                       name_list name var_para_list val_para_list
%type<function_decl>                    function_decl
%type<procedure_decl>                   procedure_decl
%type<function_head>                    function_head
%type<procedure_head>                   procedure_head
%type<para_type_list>                   parameters para_decl_list para_type_list
%type<statement>                        stmt else_clause stmt_list
%type<non_label_stmt>                   non_label_stmt
%type<assign_stmt>                      assign_stmt
%type<proc_stmt>                        proc_stmt
%type<expression>                       expression_list expression args_list
%type<expr>                             expr
%type<term>                             term
%type<factor>                           factor
%type<if_stmt>                          if_stmt
%type<repeat_stmt>                      repeat_stmt
%type<while_stmt>                       while_stmt
%type<for_stmt>                         for_stmt
%type<case_stmt>                        case_stmt
%type<case_expr>                        case_expr_list case_expr
%type<goto_stmt>                        goto_stmt
%type<compound_stmt>                    compound_stmt                   
%type<direction>                        direction


%start program
%%

program: program_head routine DOT   { $$ = new Program($1, $2); syntax_root = $$; }
                                    ;

program_head: PROGRAM IDENTIFIER SEMI   { $$ = new ProgramId(); strcpy($$->id, $2); }
                                        ;

routine: routine_head routine_body  { $$ = new Routine($1, $2, true); }
                                    ;

routine_head: const_part  type_part  var_part  routine_part { $$ = new RoutineHead(nullptr, $1, $2, $3, $4); }
                                                            ;

const_part : 
    CONST  const_expr_list  { $$ = $2; }
    |                       { $$ = nullptr; }
                            ;

const_expr_list : 
    const_expr_list  name  EQUAL  const_value  SEMI {   $$ = AddElement<ConstExprssion>($1, new ConstExprssion($2, $4)); }
    |  name  EQUAL  const_value  SEMI               {   $$ = new ConstExprssion($1, $3); }
                                                    ;

const_value :
    INTEGER     { 
                    $$ = new ConstValue();
                    $$->flag = ConstValue::INT;
                    $$->value.int_value = $1;
                }
    |  REAL     { 
                    $$ = new ConstValue();
                    $$->flag = ConstValue::REAL;
                    $$->value.real_value = $1;
                }
    |  CHAR     { 
                    $$ = new ConstValue();
                    $$->flag = ConstValue::CHAR;
                    $$->value.char_value = $1;
                }
    |  SYS_CON  {
                    $$ = new ConstValue();
                    $$->flag = ConstValue::SYS_CON;
                    if(!strcmp($1, "true"))
                        $$->value.sys_con_value = Sys_Con::TRUE;
                    else if(!strcmp($1, "false"))
                        $$->value.sys_con_value = Sys_Con::FALSE;
                    else if(!strcmp($1, "maxint"))
                        $$->value.sys_con_value = Sys_Con::MAXINT;
                    else
                        yyerror($1);
                }
                ;

type_part : 
    TYPE type_decl_list { $$ = $2; }
    |                   { $$ = nullptr; }
                        ;

type_decl_list : 
    type_decl_list  type_definition { $$ = AddElement<TypeDefinition>($1, $2); }
    |  type_definition              { $$ = $1; }
                                    ;

type_definition : 
    name  EQUAL  type_decl  SEMI    { $$ = new TypeDefinition($1, $3); }
                                    ;

type_decl : 
    simple_type_decl    { $$ = new TypeDecl(); $$->flag = TypeDecl::SIMPLE; $$->decl.simple_decl = $1; }
    |  array_type_decl  { $$ = new TypeDecl(); $$->flag = TypeDecl::ARRAY; $$->decl.array_decl = $1; }
    |  record_type_decl { $$ = new TypeDecl(); $$->flag = TypeDecl::RECORD; $$->decl.record_decl = $1; }
                        ;

simple_type_decl : 
    SYS_TYPE                                            {
                                                            $$ = new SimpleTypeDecl();
                                                            $$->flag = SimpleTypeDecl::SYS_TYPE;
                                                            if(!strcmp($1, "integer"))
                                                                $$->type_decl.sys_type_decl = Sys_Type::SYS_INTEGER;
                                                            else if(!strcmp($1, "boolean"))
                                                                $$->type_decl.sys_type_decl = Sys_Type::SYS_BOOLEAN;
                                                            else if(!strcmp($1, "real"))
                                                                $$->type_decl.sys_type_decl = Sys_Type::SYS_REAL;
                                                            else if(!strcmp($1, "char"))
                                                                $$->type_decl.sys_type_decl = Sys_Type::SYS_CHAR;
                                                            else
                                                                yyerror($1);
                                                        }
    |  name                                             {   
                                                            $$ = new SimpleTypeDecl();
                                                            $$->flag = SimpleTypeDecl::NAME;
                                                            $$->type_decl.name_type_decl = $1;
                                                        }
    |  LP  name_list  RP                                { 
                                                            $$ = new SimpleTypeDecl();
                                                            $$->flag = SimpleTypeDecl::NAME_LIST;
                                                            $$->type_decl.name_list_decl = $2;
                                                        }
    |  const_value  DOTDOT  const_value                 {   
                                                            $$ = new SimpleTypeDecl();
                                                            $$->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::POS_POS;
                                                            tmp->c_lhs = $1;
                                                            tmp->c_rhs = $3;
                                                            $$->type_decl.range_type_decl = tmp;
                                                        }
    |  MINUS  const_value  DOTDOT  const_value          { 
                                                            $$ = new SimpleTypeDecl();
                                                            $$->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::NEG_POS;
                                                            tmp->c_lhs = $2;
                                                            tmp->c_rhs = $4;
                                                            $$->type_decl.range_type_decl = tmp;
                                                        }
    |  MINUS  const_value  DOTDOT  MINUS  const_value   { 
                                                            $$ = new SimpleTypeDecl();
                                                            $$->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::NEG_NEG;
                                                            tmp->c_lhs = $2;
                                                            tmp->c_rhs = $5;
                                                            $$->type_decl.range_type_decl = tmp;
                                                        }
    |  name  DOTDOT  name                               { 
                                                            $$ = new SimpleTypeDecl();
                                                            $$->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::NAME_NAME;
                                                            tmp->n_lhs = $1;
                                                            tmp->n_rhs = $3;
                                                            $$->type_decl.range_type_decl = tmp;
                                                        }
                                                        ;

array_type_decl : ARRAY  LB  simple_type_decl  RB  OF  type_decl     { $$ = new ArrayTypeDecl($3, $6); }
                                                                     ;

record_type_decl : RECORD  field_decl_list  END { $$ = new RecordTypeDecl($2); }
                                                ;

field_decl_list : 
    field_decl_list  field_decl { $$ = AddElement<NormalDecl>($1, $2); }
    |  field_decl               { $$ = $1; }
                                ;

field_decl : name_list  COLON  type_decl  SEMI  { $$ = new NormalDecl($1, $3); }
                                                ;

name_list : 
    name_list  COMMA  name      { $$ = AddElement<Identifier>($1, $3); }
    |  name                     { $$ = $1; }
                                ;

var_part : 
    VAR  var_decl_list  { $$ = $2; }
    |                   { $$ = nullptr; }
                        ;

var_decl_list :  
    var_decl_list  var_decl { $$ = AddElement<NormalDecl>($1, $2); }
    |  var_decl             { $$ = $1; }
                            ;

var_decl :  name_list  COLON  type_decl  SEMI   { $$ = new NormalDecl($1, $3); }
                                                ;

routine_part:  
    routine_part  function_decl     {   
                                        CallDecl* tmp = new CallDecl();
                                        tmp->flag = CallDecl::FUNC;
                                        tmp->decl.func_decl = $2;
                                        $$ = AddElement<CallDecl>($1, tmp);
                                    }
    |  routine_part  procedure_decl {   
                                        CallDecl* tmp = new CallDecl();
                                        tmp->flag = CallDecl::PROC;
                                        tmp->decl.proc_decl = $2;
                                        $$ = AddElement<CallDecl>($1, tmp);
                                    }
    |                               {   $$ = nullptr; }
                                    ;

function_decl : function_head  SEMI  sub_routine  SEMI  { $$ = new FunctionDecl($1, $3); }
                                                        ;

function_head :  FUNCTION  name  parameters  COLON  simple_type_decl    { $$ = new FunctionHead($2, $3, $5); }
                                                                        ;

procedure_decl :  procedure_head  SEMI  sub_routine  SEMI   { $$ = new ProcedureDecl($1, $3); }
                                                            ;

procedure_head :  PROCEDURE name parameters { $$ = new ProcedureHead($2, $3); }
                                            ;

parameters : 
    LP  para_decl_list  RP  { $$ = $2; }
    |                       { $$ = nullptr; }
                            ;

para_decl_list : 
    para_decl_list  SEMI  para_type_list    { $$ = AddElement<ParaTypeList>($1, $3); }
    | para_type_list                        { $$ = $1; }
                                            ;

para_type_list : 
    var_para_list COLON  simple_type_decl       { 
                                                    $$ = new ParaTypeList();
                                                    $$->flag = ParaTypeList::VAR;
                                                    $$->type = $3;
                                                    $$->para_list = $1;
                                                }
    |  val_para_list  COLON  simple_type_decl   { 
                                                    $$ = new ParaTypeList();
                                                    $$->flag = ParaTypeList::VAL;
                                                    $$->type = $3;
                                                    $$->para_list = $1;
                                                }
                                                ;

var_para_list : VAR  name_list  { $$ = $2; }
                                ;

val_para_list : name_list   { $$ = $1; }
                            ;

sub_routine : routine_head  routine_body    { $$ = new Routine($1, $2, false); }
                                            ;

routine_body : compound_stmt    { $$ = $1; }
                                ;

compound_stmt : SPL_BEGIN  stmt_list  END   { $$ = new CompoundStatement($2); }
                                        ;

stmt_list : 
    stmt_list  stmt  SEMI   { $$ = AddElement<Statement>($1, $2); }
    |                       { $$ = nullptr; }
                            ;

stmt : 
    INTEGER  COLON  non_label_stmt  { $$ = new Statement($3, $1); }
    |  non_label_stmt               { $$ = new Statement($1, -1); }
                                    ;

non_label_stmt : 
    assign_stmt     { 
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::ASSIGN;
                        $$->statement.assign_statement = $1; 
                    }
    | proc_stmt     { 
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::PROC;
                        $$->statement.proc_statement = $1; 
                    }
    | compound_stmt { 
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::COMPOUND;
                        $$->statement.compound_statement = $1; 
                    }
    | if_stmt       { 
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::IF;
                        $$->statement.if_statement = $1; 
                    }
    | repeat_stmt   {   
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::REPEAT;
                        $$->statement.repeat_statement = $1;  
                    }
    | while_stmt    {   
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::WHILE;
                        $$->statement.while_statement = $1; 
                    }
    | for_stmt      {   
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::FOR;
                        $$->statement.for_statment = $1; 
                    }
    | case_stmt     {   
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::CASE;
                        $$->statement.case_statement = $1;  
                    }
    | goto_stmt     {   
                        $$ = new NonLabelStatement();
                        $$->flag = NonLabelStatement::GOTO;
                        $$->statement.goto_statement = $1; 
                    }
                    ;

assign_stmt : 
    name  ASSIGN  expression                        {
                                                        $$ = new AssignStatement();
                                                        $$->flag = AssignStatement::NORMAL;
                                                        $$->assign.normal_assign = new NormalAssignment($1, $3);
                                                    }
    | name LB expression RB ASSIGN expression       { 
                                                        $$ = new AssignStatement();
                                                        $$->flag = AssignStatement::ARRAY;
                                                        $$->assign.array_assign = new ArrayAssignment($1, $3, $6);
                                                    }
    | name  DOT  name  ASSIGN  expression           { 
                                                        $$ = new AssignStatement();
                                                        $$->flag = AssignStatement::RECORD;
                                                        $$->assign.record_assign = new RecordAssignment($1, $3, $5);
                                                    }
                                                        ;

proc_stmt : 
    name                                    { 
                                                $$ = new ProcStatement();
                                                $$->flag = ProcStatement::PROC;
                                                $$->proc.normal_proc = new Procedure($1, nullptr);
                                            }
    |  name  LP  args_list  RP              {   
                                                $$ = new ProcStatement();
                                                $$->flag = ProcStatement::PROC;
                                                $$->proc.normal_proc = new Procedure($1, $3);
                                            }
    |  SYS_PROC                             {
                                                $$ = new ProcStatement();
                                                $$->flag = ProcStatement::SYS_PROC;
                                                if (!strcmp($1, "write")){
                                                    $$->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITE, nullptr);
                                                }
                                                else if(!strcmp($1, "writeln")){
                                                    $$->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITELN, nullptr); 
                                                }
                                                else{
                                                    yyerror($1);
                                                }
                                            }
    |  SYS_PROC  LP  expression_list  RP    { 
                                                $$ = new ProcStatement();
                                                $$->flag = ProcStatement::SYS_PROC;
                                                if (!strcmp($1, "write")){
                                                    $$->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITE, $3);
                                                }
                                                else if(!strcmp($1, "writeln")){
                                                    $$->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITELN, $3); 
                                                }
                                                else{
                                                    yyerror($1);
                                                }
                                            }
    |  READ  LP  factor  RP                 { 
                                                $$ = new ProcStatement();
                                                $$->flag = ProcStatement::READ_PROC;
                                                $$->proc.read_proc = new ReadProcedure($3); 
                                            }
                                            ;

if_stmt : IF  expression  THEN  stmt  else_clause ENDIF  { $$ = new IfStatement($2, $4, $5); }
                                                    ;

else_clause : 
    ELSE stmt                                       { $$ = $2; }
    |                                               { $$ = nullptr; }
                                                    ;

repeat_stmt : REPEAT  stmt_list  UNTIL  expression  { $$ = new RepeatStatement($2, $4); }
                                                    ;

while_stmt : WHILE  expression  DO stmt             { $$ = new WhileStatement($2, $4); }
                                                    ;

for_stmt : 
    FOR  name  ASSIGN  expression  direction  expression  DO stmt   { $$ = new ForStatement($2, $4, $5, $6, $8); }
                                                                    ;

direction : 
    TO          { $$ = ForStatement::For_Type::TO; }
    | DOWNTO    { $$ = ForStatement::For_Type::DOWNTO; }
                ;

case_stmt : CASE expression OF case_expr_list  END  { $$ = new CaseStatement($2, $4);}
                                                    ;

case_expr_list : 
    case_expr_list  case_expr                       { $$ = AddElement<CaseExpression>($1, $2); }
    |  case_expr                                    { $$ = $1; }
                                                    ;

case_expr : 
    const_value  COLON  stmt  SEMI                  { $$ = new CaseExpression(nullptr, $1, $3, CaseExpression::Type::CONST_CASE); }
    |  name  COLON  stmt  SEMI                      { $$ = new CaseExpression($1, nullptr, $3, CaseExpression::Type::ID_CASE); }
                                                    ;

goto_stmt : GOTO  INTEGER                           { $$ = new GotoStatement($2); }
                                                    ;

expression_list : 
    expression_list  COMMA  expression  { $$ = AddElement<Expression>($1, $3); }
    |  expression                       { $$ = $1; }
                                        ;

expression : 
    expression  GE  expr            { $$ = new Expression($1, $3, Expression::Type::GE); }
    |  expression  GT  expr         { $$ = new Expression($1, $3, Expression::Type::GT); }
    |  expression  LE  expr         { $$ = new Expression($1, $3, Expression::Type::LE); }
    |  expression  LT  expr         { $$ = new Expression($1, $3, Expression::Type::LT); }
    |  expression  EQUAL  expr      { $$ = new Expression($1, $3, Expression::Type::EQUAL); }
    |  expression  UNEQUAL  expr    { $$ = new Expression($1, $3, Expression::Type::UNEQUAL); }
    |  expr                         { $$ = new Expression(nullptr, $1, Expression::Type::SINGLE); }
                                    ;

expr : 
    expr  PLUS  term                { $$ = new Expr($1, $3, Expr::PLUS); }
    |  expr  MINUS  term            { $$ = new Expr($1, $3, Expr::MINUS); }
    |  expr  OR  term               { $$ = new Expr($1, $3, Expr::OR); }
    |  term                         { $$ = new Expr(nullptr, $1, Expr::SINGLE); }
                                    ;

term : 
    term  MUL  factor           { $$ = new Term($1, $3, Term::MUL); }
    |  term  DIV  factor        { $$ = new Term($1, $3, Term::DIV); }
    |  term  MOD  factor        { $$ = new Term($1, $3, Term::MOD); }
    |  term  AND  factor        { $$ = new Term($1, $3, Term::AND); }
    |  factor                   { $$ = new Term(nullptr, $1, Term::SINGLE); }
                                ;

factor : 
    name                                { $$ = new Factor(); $$->factor.name_factor = $1; $$->flag = Factor::NAME; }
    |  name  LP  args_list  RP          { $$ = new Factor(); $$->factor.func_factor = new FunctionCall($1, $3); $$->flag = Factor::FUNC; }
    |  SYS_FUNCT                        {
                                            $$ = new Factor(); 
                                            $$->flag = Factor::SYS_FUNC;
                                            if(!strcmp($1, "abs")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ABS, nullptr); 
                                            }
                                            else if(!strcmp($1, "chr")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::CHR, nullptr); 
                                            }
                                            else if(!strcmp($1, "odd")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ODD, nullptr); 
                                            }
                                            else if(!strcmp($1, "ord")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ORD, nullptr); 
                                            }
                                            else if(!strcmp($1, "pred")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::PRED, nullptr); 
                                            }
                                            else if(!strcmp($1, "sqr")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQR, nullptr);  
                                            }
                                            else if(!strcmp($1, "sqrt")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQRT, nullptr); 
                                            }
                                            else if(!strcmp($1, "succ")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SUCC, nullptr); 
                                            }
                                            else{
                                                yyerror($1);
                                            }
                                        }
    |  SYS_FUNCT  LP  args_list  RP     { 
                                            $$ = new Factor(); 
                                            $$->flag = Factor::SYS_FUNC;
                                            if(!strcmp($1, "abs")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ABS, $3); 
                                            }
                                            else if(!strcmp($1, "chr")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::CHR, $3); 
                                            }
                                            else if(!strcmp($1, "odd")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ODD, $3); 
                                            }
                                            else if(!strcmp($1, "ord")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ORD, $3); 
                                            }
                                            else if(!strcmp($1, "pred")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::PRED, $3); 
                                            }
                                            else if(!strcmp($1, "sqr")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQR, $3);  
                                            }
                                            else if(!strcmp($1, "sqrt")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQRT, $3); 
                                            }
                                            else if(!strcmp($1, "succ")){
                                                $$->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SUCC, $3); 
                                            }
                                            else{
                                                yyerror($1);
                                            }
                                        }
    |  const_value                      { $$ = new Factor(); $$->factor.const_factor = $1; $$->flag = Factor::CONST; }
    |  LP  expression  RP               { $$ = new Factor(); $$->factor.expr_factor = $2; $$->flag = Factor::EXPR; }
    |  NOT  factor                      { $$ = new Factor(); $$->factor.not_factor = new NotFactor($2); $$->flag = Factor::NOT; }
    |  MINUS  factor                    { $$ = new Factor(); $$->factor.minus_factor = new MinusFactor($2); $$->flag = Factor::MINUS; }
    |  name  LB  expression  RB         { 
                                            $$ = new Factor(); 
                                            $$->factor.at_factor = new AtOperation($1, $3);
                                            $$->flag = Factor::AT; 
                                        }
    |  name  DOT  name                  { 
                                            $$ = new Factor(); 
                                            $$->factor.get_factor = new GetOperation($1, $3); 
                                            $$->flag = Factor::GET; 
                                        }
                                        ;

args_list : 
    args_list  COMMA  expression    { $$ = AddElement<Expression>($1, $3); }
    |  expression                   { $$ = $1; }
                                    ;

name :
    IDENTIFIER  { 
                    $$ = new Identifier(); 
                    strcpy($$->buffer, $1);
                }
                ;