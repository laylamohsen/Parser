%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}

%token INT FLOAT VOID IF ELSE RETURN WHILE
%token PLUS_OP MINUS_OP MUL_OP DIV_OP COMMA OPEN_BR CLOSE_BR OPEN_BR_SQ CLOSE_BR_SQ OPEN_BR_CR CLOSE_BR_CR
%token SPECIAL_SYMBOL NON_ALPHA DIGIT LETTER DOT HASH DOLLAR_SIGN UNDER_SCORE EXP exp
%token COMMENT ECOMMENT ID NUM ERROR_TOKEN EOL
%token SEMICOLON ASS_OP GREATER GREATER_EQ LESS LESS_EQ EQUAL NOT_EQUAL

%%

program: declaration_list   {printf("program");}

declaration_list: declaration_list declaration  {printf("declaration_list");}
                | declaration   {printf("declaration_list");}

declaration: var_declaration    {printf("declaration");}
           | fun_declaration    {printf("declaration_list");}

var_declaration: type_specifier ID SEMICOLON    {printf("var_declaration");}
               | type_specifier ID OPEN_BR_SQ NUM CLOSE_BR_SQ SEMICOLON {printf("var_declaration");}

type_specifier: INT {printf("type_specifier");}
              | FLOAT   {printf("type_specifier");}

fun_declaration: type_specifier ID OPEN_BR params CLOSE_BR compound_stmt    {printf("fun_declaration");}

params: param_list  {printf("params");}
      | VOID    {printf("params");}

param_list: param_list COMMA param  {printf("param_list");}
          | param   {printf("param_list");}

param: type_specifier ID    {printf("param");}
     | type_specifier ID OPEN_BR_SQ CLOSE_BR_SQ {printf("param");}

compound_stmt: OPEN_BR_CR local_declarations statement_list CLOSE_BR_CR {printf("compound_stmt");}
             | /* empty */  {printf("compound_stmt");}

local_declarations: local_declarations var_declaration  {printf("local_declarations");}
                  | /* empty */ {printf("local_declarations");}

statement_list: statement_list statement    {printf("statement_list");}
              | /* empty */ {printf("statement_list");}

statement: expression_stmt  {printf("statement");}
         | compound_stmt    {printf("statement");}
         | selection_stmt   {printf("statement");}
         | iteration_stmt   {printf("statement");}
         | return_stmt  {printf("statement");}

expression_stmt: expression SEMICOLON   {printf("expression_stmt");}
               | SEMICOLON  {printf("expression_stmt");}

selection_stmt: IF OPEN_BR expression CLOSE_BR statement    {printf("selection_stmt");}
              | IF OPEN_BR expression CLOSE_BR statement ELSE statement {printf("selection_stmt");}

iteration_stmt: WHILE OPEN_BR expression CLOSE_BR statement {printf("iteration_stmt");}

return_stmt: RETURN SEMICOLON   {printf("return_stmt");}
           | RETURN expression SEMICOLON    {printf("return_stmt");}

expression: var ASS_OP expression   {printf("expression");}
          | simple_expression   {printf("expression");}

var: ID {printf("var");}
   | ID OPEN_BR_SQ expression CLOSE_BR_SQ   {printf("var");}

simple_expression: additive_expression relop additive_expression    {printf("simple_expression");}
                 | additive_expression  {printf("simple_expression");}

relop: GREATER  {printf("relop");}
     | GREATER_EQ   {printf("relop");}
     | LESS {printf("relop");}
     | LESS_EQ  {printf("relop");}
     | EQUAL    {printf("relop");}
     | NOT_EQUAL    {printf("relop");}

additive_expression: additive_expression addop term {printf("additive_expression");}
                   | term   {printf("additive_expression");}

addop: PLUS_OP  {printf("addop");}
     | MINUS_OP {printf("addop");}

term: term mulop factor {printf("term");}
    | factor    {printf("term");}
    
mulop: MUL_OP   {printf("mulop");}
     | DIV_OP   {printf("mulop");}

factor: OPEN_BR expression CLOSE_BR {printf("factor");}
      | var {printf("factor");}
      | call    {printf("factor");}
      | NUM {printf("factor");}

call: ID OPEN_BR args CLOSE_BR  {printf("call");}

args: arg_list  {printf("args");}
    | /* empty */   {printf("args");}

arg_list: arg_list COMMA expression {printf("arg_list");}
        | expression    {printf("arg_list");}

%%





extern FILE* yyin;  // External variable for Flex/Bison to read from a file


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
