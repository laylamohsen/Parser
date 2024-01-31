#include <stdio.h>
#include <stdbool.h>
#include "TokenTypes.h"

// Function to get the next token from the lexer
extern int yylex();
extern FILE* yyin;
extern char* yytext;


// Token structure
typedef struct {
    TokenType type;
    char* word;
} Token;

Token token;
int i = 0;

// Function declarations for recursive descent parsing
bool Program();
bool DeclarationList();
bool Declaration();
bool VarDeclaration();
bool TypeSpecifier();
bool Params();
bool ParamsList();
bool Param();
bool CompoundStmt();
bool StatementList();
bool Statement();
bool SelectionStmt();
bool AssignmentStmt();
bool IterationStmt();
bool Var();
bool Expression();
bool Relop();
bool AdditiveExpression();
bool Addop();
bool Term();
bool Mulop();
bool Factor();

// Function to get the next token from the input
Token getNextToken() {

    int tokenType;


    // while ((tokenType = yylex()) != 0) {
        // Process each token based on its type
        tokenType = yylex();
        switch (tokenType) {
            case KEYWORDT:
                token.type = KEYWORDT;
                token.word = yytext;
                break;
            case SPECIAL_SYMBOLT:
                token.type = SPECIAL_SYMBOLT;
                token.word = yytext;
                break;
            case IDT:
                token.type = IDT;
                token.word = yytext;
                break;
            case NUMT:
                token.type = NUMT;
                token.word = yytext;
                break;
            default:
                token.type = NORMALT;
                token.word = yytext;
                break;
        }
    // }

    return token;
}

bool match(char* word, TokenType type, bool checkType){
    printf("MATCHING %s\n",token.word);
    if(checkType){

        if(token.type != type){
            reportError(word);
            exit(0);
            return false;
        }

        return true;

    }
    else{

        if(strcmp(token.word,word) != 0){
            // printf("Expected '%s'\n", token.word);
            reportError(word);
            exit(0);
            return false;
        }

        return true;

    }
}

// Function to report syntax errors
void reportError(const char *message) {
    fprintf(stderr, "Syntax Error: Expected '%s'\n", message);
}

//1
bool Program() {
    
    token = getNextToken();
    if(!match("Program",KEYWORDT,false)) return false;


    token = getNextToken();
    if(!match("IDT", IDT, true)) return false;


    token = getNextToken();
    if(!match("{", SPECIAL_SYMBOLT, false)) return false;


    token = getNextToken();
    if(!DeclarationList()) {
        reportError("DeclarationList");
        return false;
    }

    if(!StatementList()) {
        reportError("StatementList");
        return false;
    }

    token = getNextToken();
    if(!match("}", SPECIAL_SYMBOLT, false)) return false;

    return true;
}

//2
//NOT SURE
bool DeclarationList(){

    if(!Declaration()) {
        reportError("Declaration");
        return false;
    }

    token = getNextToken();
    while (TypeSpecifier())
    {
        if(!Declaration()) {
            reportError("Declaration");
            return false;
        }

        token = getNextToken();
    }
    
    return true;
}

//3
bool Declaration(){

    if(!VarDeclaration()) {
        reportError("VarDeclaration");
        return false;
    }

    return true;
}

//4
bool VarDeclaration(){

    if(!TypeSpecifier()) {
        reportError("TypeSpecifier");
        return false;
    }

    token = getNextToken();
    if(!match("IDT", IDT, true)) return false;

    token = getNextToken();
    if(strcmp(token.word,"[") == 0){

        token = getNextToken();
        if(!match("NUMT", NUMT, true)) return false;

        token = getNextToken();
        if(!match("]", SPECIAL_SYMBOLT, false)) return false;

        token = getNextToken();
    }


    if(!match(";", SPECIAL_SYMBOLT, false)) return false;

    return true;

}

//5
bool TypeSpecifier(){

    switch (token.word[0])
    {
    case 'i': 
        i--;
        return match("int", KEYWORDT, false);

    case 'f': 
        i--;
        return match("float", KEYWORDT, false);

    default:
        i--;
        return false;
    }
}

//7
bool Params(){

    token = getNextToken();
    if(strcmp(token.word,"void") != 0){
        if(!ParamsList()) {
            reportError("ParamsList");
            return false;
        }
    }

    return true;

}

//8
bool ParamsList(){

    if(!Param()) {
        reportError("Param");
        return false;
    }

    token = getNextToken();
    while(strcmp(token.word,",") == 0){
        
        token = getNextToken();
        if(!Param()) {
            reportError("Param");
            return false;
        }

    }

    return true;
}

//9
bool Param(){

    if(!TypeSpecifier()) {
        reportError("TypeSpecifier");
        return false;
    }

    token = getNextToken();
    if(!match("IDT", IDT, true)) return false;

    token = getNextToken();
    if(strcmp(token.word,"[")){
        match("]", SPECIAL_SYMBOLT, false);
    }

    return true;
}

//10
bool CompoundStmt(){

    if(!match("{", SPECIAL_SYMBOLT, false)) return false;

    token = getNextToken();
    if(!StatementList()) {
        reportError("StatementList");
        return false;
    }

    token = getNextToken();
    if(!match("}", SPECIAL_SYMBOLT, false)) return false;

    return true;
}

//12
//NOT SURE
bool StatementList(){

    while (Statement())
    {
        continue;
    }

    return true;
    
}

//13
bool Statement(){

    switch (token.word[0])
    {
    case 'i':   //if
        i--;
        if(!SelectionStmt()) {
            reportError("SelectionStmt");
            return false;
        }
        return true;

    case '{':
        i--;
        if(!CompoundStmt()) {
            reportError("CompoundStmt");
            return false;
        }
        return true;

    case 'w':   //while
        i--;
        if(!IterationStmt()) {
            reportError("IterationStmt");
            return false;
        }
        return true;

    default:
        switch (token.type)
        {
        case IDT:
            if(!AssignmentStmt()) {
                reportError("AssignmentStmt");
                return false;
            }
            return true;
            break;
        
        default:
            return false;
            break;
        }
        return false;
    }
}

//15
bool SelectionStmt(){

    if(!match("if", KEYWORDT, false)) return false;

    token = getNextToken();
    if(!match("(", SPECIAL_SYMBOLT, false)) return false;

    token = getNextToken();
    if(!Expression()) {
        reportError("Expression");
        return false;
    }

    token = getNextToken();
    if(!match(")", SPECIAL_SYMBOLT, false)) return false;

    token = getNextToken();
    if(!Statement()) {
        reportError("Statement");
        return false;
    }

    token = getNextToken();
    if(strcmp(token.word, "else") == 0){

        token = getNextToken();
        if(!Statement()) {
            reportError("Statement");
            return false;
        }
    }

    return true;
}

//16
bool IterationStmt(){

    if(!match("while", KEYWORDT, false)) return false;

    token = getNextToken();
    if(!match("(", SPECIAL_SYMBOLT, false)) return false;

    token = getNextToken();
    if(!Expression()) {
        reportError("Expression");
        return false;
    }

    token = getNextToken();
    if(!match(")", SPECIAL_SYMBOLT, false)) return false;

    token = getNextToken();
    if(!Statement()) {
        reportError("Statement");
        return false;
    }

    return true;
}

//18
bool AssignmentStmt(){

    if(!Var()) {
        reportError("Var");
        return false;
    }

    if(!match("=", SPECIAL_SYMBOLT, false)) return false;

    token = getNextToken();
    if(!Expression()) {
        reportError("Expression");
        return false;
    }

    return true;

}

//19
bool Var(){

    if(!match("IDT", IDT, true)) return false;

    token = getNextToken();
    if(strcmp(token.word, "[") == 0){
        
        token = getNextToken();
        if(!Expression()) {
            reportError("Expression");
            return false;
        }

        if(!match("]", SPECIAL_SYMBOLT, false)) return false;

        token = getNextToken();
    }

    return true;
}

//20
bool Expression(){

    if(!AdditiveExpression()) {
        reportError("AdditiveExpression");
        return false;
    }

    while (Relop())
    {
        token = getNextToken();
        if(!AdditiveExpression()) {
            reportError("AdditiveExpression");
            return false;
        }

    }

    return true;
}

//21
bool Relop(){

    switch (token.word[0])
    {
    case '<':
        switch (token.word[1])
        {
        case '=':
            i--;
            return match("<=", SPECIAL_SYMBOLT, false);
        
        default:
            i--;
            return match("<", SPECIAL_SYMBOLT, false);
        }
    
    case '>':
        switch (token.word[1])
        {
        case '=':
            i--;
            return match(">=", SPECIAL_SYMBOLT, false);
        
        default:
            i--;
            return match(">", SPECIAL_SYMBOLT, false);
        }
    
    case '=':
        i--;
        return match("==", SPECIAL_SYMBOLT, false);

    case '!':
        i--;
        return match("!=", SPECIAL_SYMBOLT, false);

    default:
        i--;
        return false;
    }
}

//22
bool AdditiveExpression(){

    if(!Term()) {
        reportError("Term");
        return false;
    }

    while (Addop())
    {
        token = getNextToken();
        if(!Term()) {
            reportError("Term");
            return false;
        }
    }
    

    return true;
}

//23
bool Addop(){


    switch (token.word[0])
    {
    case '+':
        i--;
        return match("+", SPECIAL_SYMBOLT, false);
        
    case '-':
        i--;
        return match("-", SPECIAL_SYMBOLT, false);

    default:
        i--;
        return false;
    }
}

//24
bool Term(){
    if(!Factor()) {
        reportError("Factor");
        return false;
    }


    while (Mulop())
    {
        token = getNextToken();
        if(!Factor()) {
            reportError("Factor");
            return false;
        }

    }

    return true;    
}

//25
bool Mulop(){

    switch (token.word[0])
    {
    case '*':
        return match("*", SPECIAL_SYMBOLT, false);
    
    case'/':
        i--;
        return match("/", SPECIAL_SYMBOLT, false);
    default:
        i--;
        return false;
    }
}

//26
bool Factor(){
   
    if(strcmp(token.word, "(") == 0){
        printf("MATCHING %s\n", token.word);
        token = getNextToken();
        if(!Expression()) {
            reportError("Expression");
            return false;
        }
        
        if(!match(")", SPECIAL_SYMBOLT, false)) return false;

        token = getNextToken();
    }
    else if(token.type == NUMT){
        token = getNextToken();
        return true;
    }
    else if(token.type == IDT){
        
        if(!Var()) {
            reportError("Var");
            return false;
        }

    }

    return true;
}

int main() {
    
    yyin = fopen("test1.txt", "r");

    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }
    Program();

    return 0;
}
