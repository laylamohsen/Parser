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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    VOID = 260,                    /* VOID  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    RETURN = 263,                  /* RETURN  */
    WHILE = 264,                   /* WHILE  */
    PLUS_OP = 265,                 /* PLUS_OP  */
    MINUS_OP = 266,                /* MINUS_OP  */
    MUL_OP = 267,                  /* MUL_OP  */
    DIV_OP = 268,                  /* DIV_OP  */
    COMMA = 269,                   /* COMMA  */
    OPEN_BR = 270,                 /* OPEN_BR  */
    CLOSE_BR = 271,                /* CLOSE_BR  */
    OPEN_BR_SQ = 272,              /* OPEN_BR_SQ  */
    CLOSE_BR_SQ = 273,             /* CLOSE_BR_SQ  */
    OPEN_BR_CR = 274,              /* OPEN_BR_CR  */
    CLOSE_BR_CR = 275,             /* CLOSE_BR_CR  */
    SPECIAL_SYMBOL = 276,          /* SPECIAL_SYMBOL  */
    NON_ALPHA = 277,               /* NON_ALPHA  */
    DIGIT = 278,                   /* DIGIT  */
    LETTER = 279,                  /* LETTER  */
    DOT = 280,                     /* DOT  */
    HASH = 281,                    /* HASH  */
    DOLLAR_SIGN = 282,             /* DOLLAR_SIGN  */
    UNDER_SCORE = 283,             /* UNDER_SCORE  */
    EXP = 284,                     /* EXP  */
    exp = 285,                     /* exp  */
    COMMENT = 286,                 /* COMMENT  */
    ECOMMENT = 287,                /* ECOMMENT  */
    ID = 288,                      /* ID  */
    NUM = 289,                     /* NUM  */
    ERROR_TOKEN = 290,             /* ERROR_TOKEN  */
    EOL = 291,                     /* EOL  */
    SEMICOLON = 292,               /* SEMICOLON  */
    ASS_OP = 293,                  /* ASS_OP  */
    GREATER = 294,                 /* GREATER  */
    GREATER_EQ = 295,              /* GREATER_EQ  */
    LESS = 296,                    /* LESS  */
    LESS_EQ = 297,                 /* LESS_EQ  */
    EQUAL = 298,                   /* EQUAL  */
    NOT_EQUAL = 299                /* NOT_EQUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define VOID 260
#define IF 261
#define ELSE 262
#define RETURN 263
#define WHILE 264
#define PLUS_OP 265
#define MINUS_OP 266
#define MUL_OP 267
#define DIV_OP 268
#define COMMA 269
#define OPEN_BR 270
#define CLOSE_BR 271
#define OPEN_BR_SQ 272
#define CLOSE_BR_SQ 273
#define OPEN_BR_CR 274
#define CLOSE_BR_CR 275
#define SPECIAL_SYMBOL 276
#define NON_ALPHA 277
#define DIGIT 278
#define LETTER 279
#define DOT 280
#define HASH 281
#define DOLLAR_SIGN 282
#define UNDER_SCORE 283
#define EXP 284
#define exp 285
#define COMMENT 286
#define ECOMMENT 287
#define ID 288
#define NUM 289
#define ERROR_TOKEN 290
#define EOL 291
#define SEMICOLON 292
#define ASS_OP 293
#define GREATER 294
#define GREATER_EQ 295
#define LESS 296
#define LESS_EQ 297
#define EQUAL 298
#define NOT_EQUAL 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
