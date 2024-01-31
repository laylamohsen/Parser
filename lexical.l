%{
#include <stdio.h>
#include <string.h>


%}
KEYWORD     (int|float|void|if|else|return|while)
INT         "int" 
FLOAT       "float"
VOID        "void"
IF          "if"
ELSE        "else"
RETURN      "return"
WHILE       "while"
SPECIAL_SYMBOL ("*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|";"|","|"("|")"|"["|"]"|"{"|"}"|"/*"|"*/"|"+"|"-")
NON_ALPHA      ("`"|"!"|"@"|"#"|"%"|"$"|"?"|":"|"*"|"^"|"~"|"/")
DIGIT        [0-9]
LETTER       [a-zA-Z]
GREATER     "<"
GREATER_EQ  ">="
LESS        ">"
LESS_EQ     "<="
EQUAL       "=="
NOT_EQUAL   "!="
ASS_OP      "="
SEMICOLON   ";"
DOT          "."
HASH         "#"
DOLLAR_SIGN  "$"
UNDER_SCORE  "_"
EXP          "E"
exp          "e"
PLUS_OP      "+"
MINUS_OP     "-"
MUL_OP       "*"
DIV_OP       "/"
COMMA        ","
OPEN_BR      "("
CLOSE_BR     ")"
OPEN_BR_SQ   "["
CLOSE_BR_SQ  "]"
OPEN_BR_CR   "{"
CLOSE_BR_CR  "}"
COMMENT       "/*"([^*]|"*"+[^*/])*"*"+"/"
ECOMMENT      "/"([^*]|("*"+[^*/]))*

%%
{ECOMMENT} {printf("ERROR (1) Unclosed comment in line %d\n", line_count);}
{COMMENT} {printf("COMMENT: %s\n", yytext);}

{INT} { printf("INT: %s\n", yytext); return INT;}
{FLOAT} { printf("FLOAT: %s\n", yytext); return FLOAT;}
{VOID} { printf("VOID : %s\n", yytext); return VOID;}
{IF} { printf("IF: %s\n", yytext); return IF;}
{ELSE} { printf("ELSE: %s\n", yytext); return ELSE;}
{RETURN} { printf("RETURN: %s\n", yytext); return RETURN;}
{WHILE} { printf("WHILE: %s\n", yytext); return WHILE;}
{PLUS_OP} { printf("PLUS OP: %s\n", yytext); return PLUS_OP;}
{MINUS_OP} { printf("MINUS OP: %s\n", yytext); return MINUS_OP;}
{MUL_OP} { printf("MUL OP: %s\n", yytext); return MUL_OP;}
{DIV_OP} { printf("DIV OP: %s\n", yytext); return DIV_OP;}
{ASS_OP} { printf("ASS OP: %s\n", yytext); return ASS_OP;}
{NOT_EQUAL} { printf("NOT EQUAL: %s\n", yytext); return NOT_EQUAL;}
{EQUAL} { printf("EQUAL: %s\n", yytext); return EQUAL;}
{LESS} { printf("LESS THAN: %s\n", yytext); return LESS;}
{LESS_EQ} { printf("LESS THAN OR EQUAL: %s\n", yytext); return LESS_EQ;}
{GREATER} { printf("GREATER THAN: %s\n", yytext); return GREATER;}
{GREATER_EQ} { printf("GREATER THAN OR EQUAL: %s\n", yytext); return GREATER_EQ;}



{COMMA} { printf("COMMA : %s\n", yytext); return COMMA;}
{OPEN_BR} { printf("OPEN BRACKET: %s\n", yytext); return OPEN_BR;}
{CLOSE_BR} { printf("CLOSE BRACKET: %s\n", yytext); return CLOSE_BR;}
{OPEN_BR_SQ} { printf("OPEN SQUARE: %s\n", yytext); return OPEN_BR_SQ;}
{CLOSE_BR_SQ} { printf("CLOSE SQUARE: %s\n", yytext); return CLOSE_BR_SQ;}
{OPEN_BR_CR} { printf("OPEN CURLY: %s\n", yytext); return OPEN_BR_CR;}
{CLOSE_BR_CR} { printf("CLOSE CURLY: %s\n", yytext); return CLOSE_BR_CR;}
{SEMICOLON} { printf("SEMICOLON: %s\n", yytext); return SEMICOLON;}

{LETTER}({LETTER}|{DIGIT})*(({DOT}|{HASH}|{DOLLAR_SIGN}|{UNDER_SCORE})?({LETTER}|{DIGIT}+)?) {  printf("ID: %s\n", yytext); return ID;}
({DIGIT}+|{DIGIT}+{DOT}{DIGIT}*)(({EXP}|{exp})({PLUS_OP}|{MINUS_OP})?{DIGIT}+)?              { printf("NUM: %s\n", yytext); return NUM;}

{LETTER}({LETTER}|{DIGIT})*(({DOT}|{HASH}|{DOLLAR_SIGN}|{UNDER_SCORE}|{NON_ALPHA})[^a-zA-Z0-9])* {printf("ERROR (3) Wrong identfier in line %d : %s\n", line_count , yytext); }
({DIGIT}+|{DIGIT}+{DOT}{DIGIT}*)(({EXP}|{exp})({PLUS_OP}|{MINUS_OP})[^0-9])* {printf("ERROR (4) Wrong number in line %d : %s\n", line_count , yytext) ;line_count++ ;}
{NON_ALPHA}         { printf("ERROR (2) Charcter is not in the alphabet in line %d : %s\n", line_count ,yytext);}
\n          { line_count++; return EOL; } // Increment line count and character count on encountering a newline

%%





int yywrap()
{
 return 1;
}
