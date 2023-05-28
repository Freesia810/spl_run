%{
#include "AbstractSyntaxTree.h"
#include "parser.h"
#include <stdio.h>
#include <cstring>
extern "C" int yywrap() {return 1;}
%}

%%
[ \t\n]                                                 { }
\'.\'                                                   { 
                                                            yylval.char_value = yytext[1];
                                                            return CHAR; 
                                                        }
";"                                                     { return SEMI; }
"("                                                     { return LP; }
")"                                                     { return RP; }
"["                                                     { return LB; }
"]"                                                     { return RB; }
".."                                                    { return DOTDOT; }
"."                                                     { return DOT; }
","                                                     { return COMMA; }
":="                                                    { return ASSIGN; }
":"                                                     { return COLON; }
"*"                                                     { return MUL; }
"/"                                                     { return DIV; }
"<>"                                                    { return UNEQUAL; }
"not"                                                   { return NOT; }
"+"                                                     { return PLUS; }
"-"                                                     { return MINUS; }
">="                                                    { return GE; }
">"                                                     { return GT; }
"<="                                                    { return LE; }
"<"                                                     { return LT; }
"="                                                     { return EQUAL; }
"mod"                                                   { return MOD; }
"and"                                                   { return AND; }
"array"                                                 { return ARRAY; }
"begin"                                                 { return SPL_BEGIN; }
"case"                                                  { return CASE; }
"const"                                                 { return CONST; }
"div"                                                   { return DIV; }
"do"                                                    { return DO; }
"downto"                                                { return DOWNTO; }
"else"                                                  { return ELSE; }
"end"                                                   { return END; }
"for"                                                   { return FOR; }
"function"                                              { return FUNCTION; }
"goto"                                                  { return GOTO; }
"if"                                                    { return IF; }
"of"                                                    { return OF; }
"or"                                                    { return OR; }
"procedure"                                             { return PROCEDURE; }
"program"                                               { return PROGRAM; }
"record"                                                { return RECORD; }
"repeat"                                                { return REPEAT; }
"then"                                                  { return THEN; }
"to"                                                    { return TO; }
"type"                                                  { return TYPE; }
"until"                                                 { return UNTIL; }
"var"                                                   { return VAR; }
"while"                                                 { return WHILE; }
"endif"                                                 { return ENDIF; }

"boolean"|"char"|"integer"|"real"                       {
                                                            strcpy(yylval.str_value, yytext);
                                                            return SYS_TYPE; 
                                                        }

"abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"      {
                                                            strcpy(yylval.str_value, yytext);
                                                            return SYS_FUNCT; 
                                                        }

"false"|"maxint"|"true"                                 {
                                                            strcpy(yylval.str_value, yytext);
                                                            return SYS_CON; 
                                                        }

"write"|"writeln"                                       { 
                                                            strcpy(yylval.str_value, yytext);
                                                            return SYS_PROC; 
                                                        }

"read"                                                  { 
                                                            strcpy(yylval.str_value, "read");
                                                            return READ; 
                                                        }

[0-9]+\.[0-9]+                                          { 
                                                            double tmp;
                                                            sscanf(yytext, "%lf", &tmp);
                                                            yylval.real_value = tmp;
                                                            return REAL; 
                                                        }
[0-9]+                                                  {
                                                            int tmp;
                                                            sscanf(yytext, "%d", &tmp);
                                                            yylval.int_value = tmp; 
                                                            return INTEGER; 
                                                        }

[a-zA-Z_][a-zA-Z0-9_]*                                  { 
                                                            strcpy(yylval.str_value, yytext);
                                                            return IDENTIFIER; 
                                                        }
%%