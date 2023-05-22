/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_FREESIA_SPL_RUN_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_HOME_FREESIA_SPL_RUN_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LP = 258,                      /* LP  */
    RP = 259,                      /* RP  */
    LB = 260,                      /* LB  */
    RB = 261,                      /* RB  */
    DOT = 262,                     /* DOT  */
    COMMA = 263,                   /* COMMA  */
    COLON = 264,                   /* COLON  */
    MUL = 265,                     /* MUL  */
    UNEQUAL = 266,                 /* UNEQUAL  */
    NOT = 267,                     /* NOT  */
    PLUS = 268,                    /* PLUS  */
    MINUS = 269,                   /* MINUS  */
    GE = 270,                      /* GE  */
    GT = 271,                      /* GT  */
    LE = 272,                      /* LE  */
    LT = 273,                      /* LT  */
    EQUAL = 274,                   /* EQUAL  */
    ASSIGN = 275,                  /* ASSIGN  */
    MOD = 276,                     /* MOD  */
    DOTDOT = 277,                  /* DOTDOT  */
    SEMI = 278,                    /* SEMI  */
    AND = 279,                     /* AND  */
    ARRAY = 280,                   /* ARRAY  */
    SPL_BEGIN = 281,               /* SPL_BEGIN  */
    CASE = 282,                    /* CASE  */
    CONST = 283,                   /* CONST  */
    DIV = 284,                     /* DIV  */
    DO = 285,                      /* DO  */
    DOWNTO = 286,                  /* DOWNTO  */
    ELSE = 287,                    /* ELSE  */
    END = 288,                     /* END  */
    FOR = 289,                     /* FOR  */
    FUNCTION = 290,                /* FUNCTION  */
    GOTO = 291,                    /* GOTO  */
    IF = 292,                      /* IF  */
    OF = 293,                      /* OF  */
    OR = 294,                      /* OR  */
    ENDIF = 295,                   /* ENDIF  */
    PROCEDURE = 296,               /* PROCEDURE  */
    PROGRAM = 297,                 /* PROGRAM  */
    RECORD = 298,                  /* RECORD  */
    REPEAT = 299,                  /* REPEAT  */
    THEN = 300,                    /* THEN  */
    TO = 301,                      /* TO  */
    TYPE = 302,                    /* TYPE  */
    UNTIL = 303,                   /* UNTIL  */
    VAR = 304,                     /* VAR  */
    WHILE = 305,                   /* WHILE  */
    INTEGER = 306,                 /* INTEGER  */
    IDENTIFIER = 307,              /* IDENTIFIER  */
    SYS_CON = 308,                 /* SYS_CON  */
    SYS_FUNCT = 309,               /* SYS_FUNCT  */
    SYS_PROC = 310,                /* SYS_PROC  */
    SYS_TYPE = 311,                /* SYS_TYPE  */
    READ = 312,                    /* READ  */
    REAL = 313,                    /* REAL  */
    CHAR = 314                     /* CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "/home/freesia/spl_run/src/parser/SyntaxAnalysis.y"

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

#line 167 "/home/freesia/spl_run/include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_FREESIA_SPL_RUN_INCLUDE_PARSER_H_INCLUDED  */
