添加`endif`的token，解决移进-规约冲突
```yacc
if_stmt ： IF  expression  THEN  stmt  else_clause ENDIF
else_clause ： ELSE stmt |  ε
```

改变`routine_part`规则，解决移进-规约冲突
```yacc
routine_part:   routine_part  function_decl  
            |  routine_part  procedure_decl
            | ε
```