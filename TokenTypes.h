// tokens.h

#ifndef TOKENS
#define TOKENS

typedef enum {
    KEYWORD,  
    INT,    
    FLOAT,       
    VOID,     
    IF,       
    ELSE,     
    RETURN,    
    WHILE,
    SPECIAL_SYMBOL,
    NON_ALPHA,
    DIGIT,
    LETTER,
    GREATER,
    GREATER_EQ,
    LESS,
    LESS_EQ,
    EQUAL,
    NOT_EQUAL,
    ASS_OP,
    SEMICOLON,
    DOT,
    HASH,
    DOLLAR_SIGN,
    UNDER_SCORE,
    EXP,
    exp,
    PLUS_OP,
    MINUS_OP,
    MUL_OP,
    DIV_OP,
    COMMA,
    OPEN_BR,
    CLOSE_BR,
    OPEN_BR_SQ,
    CLOSE_BR_SQ,
    OPEN_BR_CR,
    CLOSE_BR_CR,
    COMMENT,
    ECOMMENT,
    ID,
    NUM,
    EOL
} TokenType;

extern int line_count;
int line_count = 1;

#endif
