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

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
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
    EXTERN = 258,                  /* EXTERN  */
    VOID = 259,                    /* VOID  */
    BEG = 260,                     /* BEG  */
    END = 261,                     /* END  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    RETURN = 264,                  /* RETURN  */
    INT = 265,                     /* INT  */
    BOOL = 266,                    /* BOOL  */
    STRING = 267,                  /* STRING  */
    TRUE = 268,                    /* TRUE  */
    FALSE = 269,                   /* FALSE  */
    OPENBRACKET = 270,             /* OPENBRACKET  */
    CLOSEBRACKET = 271,            /* CLOSEBRACKET  */
    OPENBRACE = 272,               /* OPENBRACE  */
    CLOSEBRACE = 273,              /* CLOSEBRACE  */
    AMPERSAND = 274,               /* AMPERSAND  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    NOT = 277,                     /* NOT  */
    EQUAL = 278,                   /* EQUAL  */
    NON_EQUAL = 279,               /* NON_EQUAL  */
    LESS = 280,                    /* LESS  */
    GREATER = 281,                 /* GREATER  */
    L_EQUAL = 282,                 /* L_EQUAL  */
    GR_EQUAL = 283,                /* GR_EQUAL  */
    ADD = 284,                     /* ADD  */
    SUB = 285,                     /* SUB  */
    MUL = 286,                     /* MUL  */
    DIV = 287,                     /* DIV  */
    MOD = 288,                     /* MOD  */
    SEMICOLON = 289,               /* SEMICOLON  */
    COMMA = 290,                   /* COMMA  */
    ID = 291,                      /* ID  */
    STATHERASUMBOLOSEIRA = 292,    /* STATHERASUMBOLOSEIRA  */
    STATHERAAKERAIOU = 293,        /* STATHERAAKERAIOU  */
    WHILE = 294,                   /* WHILE  */
    FOR = 295,                     /* FOR  */
    ASSIGN = 296,                  /* ASSIGN  */
    LOWER_THAN_ELSE = 297          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
