/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT 0 
#define FFOR 1
#define FWHILE 2 

int flag = DEFAULT;
int i,j;
char c;
int k = 0 ;
int k2 = 0;
FILE *fp ;
int loopcounter=0;
int linesWithError[100];
int startvalue=0;
int addvalue=0;
int endvalue=0;
char *Index;
char *printer;
char *copier;
char* tmp = "tmp";
static char buffer[200];


int errors=0;
extern int lines;
extern char* yytext;
extern int yylineno;
extern int yylval;
extern FILE *yyin;
extern FILE *yyout;
void copyPrint(const char s[],int choice);
void yyerror(const char*  );
void copyFunc(char* );
int yylex(void);
extern FILE *output;


#line 113 "bison.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EXTERN = 3,                     /* EXTERN  */
  YYSYMBOL_VOID = 4,                       /* VOID  */
  YYSYMBOL_BEG = 5,                        /* BEG  */
  YYSYMBOL_END = 6,                        /* END  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_TRUE = 13,                      /* TRUE  */
  YYSYMBOL_FALSE = 14,                     /* FALSE  */
  YYSYMBOL_OPENBRACKET = 15,               /* OPENBRACKET  */
  YYSYMBOL_CLOSEBRACKET = 16,              /* CLOSEBRACKET  */
  YYSYMBOL_OPENBRACE = 17,                 /* OPENBRACE  */
  YYSYMBOL_CLOSEBRACE = 18,                /* CLOSEBRACE  */
  YYSYMBOL_AMPERSAND = 19,                 /* AMPERSAND  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_EQUAL = 23,                     /* EQUAL  */
  YYSYMBOL_NON_EQUAL = 24,                 /* NON_EQUAL  */
  YYSYMBOL_LESS = 25,                      /* LESS  */
  YYSYMBOL_GREATER = 26,                   /* GREATER  */
  YYSYMBOL_L_EQUAL = 27,                   /* L_EQUAL  */
  YYSYMBOL_GR_EQUAL = 28,                  /* GR_EQUAL  */
  YYSYMBOL_ADD = 29,                       /* ADD  */
  YYSYMBOL_SUB = 30,                       /* SUB  */
  YYSYMBOL_MUL = 31,                       /* MUL  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_MOD = 33,                       /* MOD  */
  YYSYMBOL_SEMICOLON = 34,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_ID = 36,                        /* ID  */
  YYSYMBOL_STATHERASUMBOLOSEIRA = 37,      /* STATHERASUMBOLOSEIRA  */
  YYSYMBOL_STATHERAAKERAIOU = 38,          /* STATHERAAKERAIOU  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_FOR = 40,                       /* FOR  */
  YYSYMBOL_ASSIGN = 41,                    /* ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 42,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* " "  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_programma = 46,                 /* programma  */
  YYSYMBOL_ekswterikesdilwseis = 47,       /* ekswterikesdilwseis  */
  YYSYMBOL_ekswterikoprwtotupo2 = 48,      /* ekswterikoprwtotupo2  */
  YYSYMBOL_ekswterikoprwtotupo = 49,       /* ekswterikoprwtotupo  */
  YYSYMBOL_kefalidaprogrammatos = 50,      /* kefalidaprogrammatos  */
  YYSYMBOL_tmimaorismwn = 51,              /* tmimaorismwn  */
  YYSYMBOL_orismos2 = 52,                  /* orismos2  */
  YYSYMBOL_orismos = 53,                   /* orismos  */
  YYSYMBOL_orismosmetablitwn = 54,         /* orismosmetablitwn  */
  YYSYMBOL_tuposdedomenwn_metavlites = 55, /* tuposdedomenwn_metavlites  */
  YYSYMBOL_orismossunartisis = 56,         /* orismossunartisis  */
  YYSYMBOL_prwtotuposunartisis = 57,       /* prwtotuposunartisis  */
  YYSYMBOL_kefalidasunartisis = 58,        /* kefalidasunartisis  */
  YYSYMBOL_typos_synartisis_metavlites = 59, /* typos_synartisis_metavlites  */
  YYSYMBOL_c = 60,                         /* c  */
  YYSYMBOL_listatupikwnparametrwn = 61,    /* listatupikwnparametrwn  */
  YYSYMBOL_ntp = 62,                       /* ntp  */
  YYSYMBOL_ptp = 63,                       /* ptp  */
  YYSYMBOL_tupikesparametroi = 64,         /* tupikesparametroi  */
  YYSYMBOL_tuposdedomenwn = 65,            /* tuposdedomenwn  */
  YYSYMBOL_tmimaentolwn = 66,              /* tmimaentolwn  */
  YYSYMBOL_command = 67,                   /* command  */
  YYSYMBOL_entoli = 68,                    /* entoli  */
  YYSYMBOL_sunthetientoli = 69,            /* sunthetientoli  */
  YYSYMBOL_domimenientoli = 70,            /* domimenientoli  */
  YYSYMBOL_aplientoli = 71,                /* aplientoli  */
  YYSYMBOL_entoliif = 72,                  /* entoliif  */
  YYSYMBOL_anathesi = 73,                  /* anathesi  */
  YYSYMBOL_klisisunartisis = 74,           /* klisisunartisis  */
  YYSYMBOL_listapragmatikwnparametrwn = 75, /* listapragmatikwnparametrwn  */
  YYSYMBOL_npp = 76,                       /* npp  */
  YYSYMBOL_ppp = 77,                       /* ppp  */
  YYSYMBOL_pragmatikiparametros = 78,      /* pragmatikiparametros  */
  YYSYMBOL_entolireturn = 79,              /* entolireturn  */
  YYSYMBOL_entolinull = 80,                /* entolinull  */
  YYSYMBOL_genikiekfrasi = 81,             /* genikiekfrasi  */
  YYSYMBOL_ngo = 82,                       /* ngo  */
  YYSYMBOL_pgo = 83,                       /* pgo  */
  YYSYMBOL_genikosoros = 84,               /* genikosoros  */
  YYSYMBOL_ngp = 85,                       /* ngp  */
  YYSYMBOL_pgp = 86,                       /* pgp  */
  YYSYMBOL_genikosparagontas = 87,         /* genikosparagontas  */
  YYSYMBOL_genikosprwtparag = 88,          /* genikosprwtparag  */
  YYSYMBOL_tmimasugkrisis = 89,            /* tmimasugkrisis  */
  YYSYMBOL_sugkritikostelestis = 90,       /* sugkritikostelestis  */
  YYSYMBOL_apliekfrasi = 91,               /* apliekfrasi  */
  YYSYMBOL_nao1 = 92,                      /* nao1  */
  YYSYMBOL_pao1 = 93,                      /* pao1  */
  YYSYMBOL_addsub = 94,                    /* addsub  */
  YYSYMBOL_aplosoros = 95,                 /* aplosoros  */
  YYSYMBOL_nao2 = 96,                      /* nao2  */
  YYSYMBOL_pao2 = 97,                      /* pao2  */
  YYSYMBOL_muldivmod = 98,                 /* muldivmod  */
  YYSYMBOL_aplosparagontas = 99,           /* aplosparagontas  */
  YYSYMBOL_aplosprwtoros = 100,            /* aplosprwtoros  */
  YYSYMBOL_stathera = 101,                 /* stathera  */
  YYSYMBOL_entolifor = 102,                /* entolifor  */
  YYSYMBOL_103_1 = 103,                    /* $@1  */
  YYSYMBOL_104_2 = 104,                    /* $@2  */
  YYSYMBOL_105_3 = 105,                    /* $@3  */
  YYSYMBOL_106_4 = 106,                    /* $@4  */
  YYSYMBOL_107_5 = 107,                    /* $@5  */
  YYSYMBOL_108_6 = 108,                    /* $@6  */
  YYSYMBOL_entoliwhile = 109               /* entoliwhile  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   108,   108,   110,   112,   113,   116,   118,   119,   121,
     123,   124,   126,   127,   128,   130,   132,   133,   134,   135,
     137,   139,   141,   142,   144,   145,   146,   148,   149,   152,
     154,   155,   157,   159,   160,   163,   164,   165,   167,   169,
     170,   172,   173,   174,   175,   176,   178,   180,   182,   183,
     184,   185,   187,   188,   190,   191,   192,   194,   195,   197,
     198,   199,   200,   202,   204,   206,   207,   209,   211,   213,
     214,   216,   218,   220,   221,   223,   225,   226,   228,   229,
     231,   233,   234,   235,   236,   237,   238,   240,   242,   243,
     245,   247,   248,   250,   252,   253,   255,   257,   258,   259,
     261,   262,   264,   265,   266,   267,   269,   270,   271,   272,
     275,   275,   276,   277,   279,   298,   274,   305
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EXTERN", "VOID",
  "BEG", "END", "IF", "ELSE", "RETURN", "INT", "BOOL", "STRING", "TRUE",
  "FALSE", "OPENBRACKET", "CLOSEBRACKET", "OPENBRACE", "CLOSEBRACE",
  "AMPERSAND", "AND", "OR", "NOT", "EQUAL", "NON_EQUAL", "LESS", "GREATER",
  "L_EQUAL", "GR_EQUAL", "ADD", "SUB", "MUL", "DIV", "MOD", "SEMICOLON",
  "COMMA", "ID", "STATHERASUMBOLOSEIRA", "STATHERAAKERAIOU", "WHILE",
  "FOR", "ASSIGN", "LOWER_THAN_ELSE", "';'", "\" \"", "$accept",
  "programma", "ekswterikesdilwseis", "ekswterikoprwtotupo2",
  "ekswterikoprwtotupo", "kefalidaprogrammatos", "tmimaorismwn",
  "orismos2", "orismos", "orismosmetablitwn", "tuposdedomenwn_metavlites",
  "orismossunartisis", "prwtotuposunartisis", "kefalidasunartisis",
  "typos_synartisis_metavlites", "c", "listatupikwnparametrwn", "ntp",
  "ptp", "tupikesparametroi", "tuposdedomenwn", "tmimaentolwn", "command",
  "entoli", "sunthetientoli", "domimenientoli", "aplientoli", "entoliif",
  "anathesi", "klisisunartisis", "listapragmatikwnparametrwn", "npp",
  "ppp", "pragmatikiparametros", "entolireturn", "entolinull",
  "genikiekfrasi", "ngo", "pgo", "genikosoros", "ngp", "pgp",
  "genikosparagontas", "genikosprwtparag", "tmimasugkrisis",
  "sugkritikostelestis", "apliekfrasi", "nao1", "pao1", "addsub",
  "aplosoros", "nao2", "pao2", "muldivmod", "aplosparagontas",
  "aplosprwtoros", "stathera", "entolifor", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "entoliwhile", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,    55,    25,    29,  -132,    16,    -2,    13,    22,  -132,
       7,    32,  -132,    33,    93,  -132,  -132,  -132,  -132,  -132,
      80,    58,    34,    41,    46,    78,  -132,    93,  -132,   -13,
    -132,  -132,     4,    21,  -132,  -132,  -132,    82,  -132,    64,
      -8,    11,    87,   104,  -132,    -4,  -132,  -132,  -132,    84,
      78,  -132,  -132,    51,  -132,    64,    85,  -132,   106,  -132,
     108,    42,    -4,     3,   109,   110,  -132,   120,    -4,  -132,
    -132,    94,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,    42,  -132,  -132,    42,    71,
    -132,  -132,   112,  -132,  -132,  -132,  -132,   113,   116,  -132,
      90,    74,     1,    62,  -132,  -132,   111,    42,    38,    42,
      97,   101,  -132,  -132,  -132,   114,   122,  -132,    42,  -132,
     113,    42,  -132,   116,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,    71,  -132,  -132,     1,    71,  -132,  -132,  -132,  -132,
      62,    71,  -132,  -132,  -132,   123,     8,  -132,     5,    90,
    -132,    -4,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,    42,  -132,   105,    98,   107,   102,
     134,  -132,  -132,  -132,   128,   115,    -4,    -4,  -132,  -132,
    -132,   118,   119,   121,   124,  -132,   125,   127,   117,   129,
     131,   126,  -132,   132,  -132,   130,    -4,  -132,   136,  -132
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     3,     4,     0,     0,     0,     6,
       0,     0,     1,     0,    10,     5,    26,    24,    25,    21,
       0,     0,     0,     0,     0,     0,     9,    10,    12,     0,
      13,    14,    10,     0,    35,    36,    37,     0,    28,    30,
       0,     0,    16,    17,    18,    39,     2,    11,    15,     0,
       0,    23,    22,     0,    29,    30,     0,    33,     0,     7,
       0,    65,    39,     0,     0,     0,    67,     0,    39,    43,
      42,     0,    47,    48,    49,    50,    51,    44,    45,    19,
      20,    32,    31,    34,     8,     0,   108,   109,     0,     0,
      91,    92,   102,   107,   106,   104,    66,    69,    73,    76,
      78,     0,    88,    94,   100,   103,     0,     0,     0,     0,
       0,     0,    38,    40,    41,     0,     0,    77,     0,    68,
      69,     0,    72,    73,    81,    82,    83,    84,    85,    86,
      79,     0,   101,    87,    88,     0,    97,    98,    99,    93,
      94,     0,    46,    55,    57,     0,     0,    64,     0,     0,
     110,     0,   105,    71,    70,    75,    74,    80,    89,    90,
      95,    96,    58,    60,     0,    59,    61,     0,     0,     0,
      52,    63,    62,    56,     0,     0,     0,     0,   111,    53,
     117,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,     0,   113,     0,   114,     0,    39,   115,     0,   116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,   144,  -132,  -132,   135,   139,  -132,  -132,
    -132,  -132,   149,   155,  -132,  -132,  -132,   133,  -132,   137,
    -132,   141,   -61,  -131,  -132,  -132,  -132,  -132,  -132,   -45,
    -132,    -9,  -132,    -3,  -132,  -132,   -59,    48,  -132,    52,
      49,  -132,    50,    86,  -132,    20,    43,    39,  -132,   -92,
      44,    36,  -132,  -132,    37,    76,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    14,    25,    26,    27,    28,
      29,    30,    31,    32,    11,    37,    38,    54,    55,    39,
      40,    46,    67,    68,    69,    70,    71,    72,    73,    95,
     145,   165,   166,   146,    75,    76,   147,   119,   120,    97,
     122,   123,    98,    99,   130,   131,   100,   133,   134,   101,
     102,   139,   140,   141,   103,   104,   105,    77,   169,   181,
     186,   193,   195,   198,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   106,    96,    60,   107,    61,   167,   113,     6,   163,
     135,    56,    58,    62,    22,    23,    24,    74,   108,     1,
     170,    48,    49,    74,   -61,    12,   115,    59,    57,   116,
      90,    91,    63,    13,    16,    64,    65,    51,    19,   -54,
      66,    19,   135,   164,   109,   179,   180,    20,   143,    17,
     148,    86,    87,    88,   144,    86,    87,    88,    18,     6,
      89,    34,    35,    36,    89,     7,     8,    90,    91,    21,
      42,    90,    91,    41,    92,    93,    94,    43,    92,    93,
      94,    33,    44,    45,    86,    87,    88,    86,    87,    88,
      34,    35,    36,   136,   137,   138,   -27,     6,    52,    53,
      90,    91,   -24,    22,    23,    24,    74,    92,    93,    94,
      92,    93,    94,   124,   125,   126,   127,   128,   129,   -25,
      79,    83,    84,    85,   110,   111,   112,   108,   114,   142,
     151,    74,    74,   149,   118,   197,   121,   150,   152,   162,
     164,   173,   176,   175,   177,   174,   184,   196,   194,    15,
       9,    74,   182,   178,   199,   183,    10,   172,   189,   187,
     191,   171,   185,   188,   192,   190,    47,    50,   154,   168,
     153,   155,   156,   158,   157,   117,   160,   132,   161,   159,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
      81,    80
};

static const yytype_int16 yycheck[] =
{
      45,    62,    61,     7,     1,     9,     1,    68,     4,     1,
     102,    19,     1,    17,    10,    11,    12,    62,    15,     3,
     151,    34,    35,    68,    16,     0,    85,    16,    36,    88,
      29,    30,    36,     4,    36,    39,    40,    16,    34,    34,
      44,    34,   134,    35,    41,   176,   177,    15,   107,    36,
     109,    13,    14,    15,    16,    13,    14,    15,    36,     4,
      22,    10,    11,    12,    22,    10,    11,    29,    30,    36,
      36,    29,    30,    15,    36,    37,    38,    36,    36,    37,
      38,     1,    36,     5,    13,    14,    15,    13,    14,    15,
      10,    11,    12,    31,    32,    33,    16,     4,    16,    35,
      29,    30,    15,    10,    11,    12,   151,    36,    37,    38,
      36,    37,    38,    23,    24,    25,    26,    27,    28,    15,
      36,    36,    16,    15,    15,    15,     6,    15,    34,    18,
      16,   176,   177,    36,    21,   196,    20,    36,    16,    16,
      35,    43,     8,    41,    16,    38,    25,    17,    16,     5,
       1,   196,    34,    38,    18,    36,     1,   166,    41,    34,
      29,   164,    38,    36,    38,    36,    27,    32,   120,   149,
     118,   121,   123,   134,   131,    89,   140,   101,   141,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      53,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,    47,    48,    49,     4,    10,    11,    57,
      58,    59,     0,     4,    50,    48,    36,    36,    36,    34,
      15,    36,    10,    11,    12,    51,    52,    53,    54,    55,
      56,    57,    58,     1,    10,    11,    12,    60,    61,    64,
      65,    15,    36,    36,    36,     5,    66,    52,    34,    35,
      51,    16,    16,    35,    62,    63,    19,    36,     1,    16,
       7,     9,    17,    36,    39,    40,    44,    67,    68,    69,
      70,    71,    72,    73,    74,    79,    80,   102,   109,    36,
      66,    64,    62,    36,    16,    15,    13,    14,    15,    22,
      29,    30,    36,    37,    38,    74,    81,    84,    87,    88,
      91,    94,    95,    99,   100,   101,    67,     1,    15,    41,
      15,    15,     6,    67,    34,    81,    81,    88,    21,    82,
      83,    20,    85,    86,    23,    24,    25,    26,    27,    28,
      89,    90,   100,    92,    93,    94,    31,    32,    33,    96,
      97,    98,    18,    81,    16,    75,    78,    81,    81,    36,
      36,    16,    16,    84,    82,    87,    85,    91,    92,    95,
      96,    99,    16,     1,    35,    76,    77,     1,    90,   103,
      68,    78,    76,    43,    38,    41,     8,    16,    38,    68,
      68,   104,    34,    36,    25,    38,   105,    34,    36,    41,
      36,    29,    38,   106,    16,   107,    17,    67,   108,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    50,    50,    51,
      52,    52,    53,    53,    53,    54,    55,    55,    55,    55,
      56,    57,    58,    58,    59,    59,    59,    60,    60,    61,
      62,    62,    63,    64,    64,    65,    65,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    69,    70,    71,    71,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    78,    79,    79,    80,    81,    82,
      82,    83,    84,    85,    85,    86,    87,    87,    88,    88,
      89,    90,    90,    90,    90,    90,    90,    91,    92,    92,
      93,    94,    94,    95,    96,    96,    97,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   101,   101,   101,   101,
     103,   104,   105,   106,   107,   108,   102,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     0,     2,     2,     4,     5,     1,
       0,     2,     1,     1,     1,     2,     2,     2,     2,     3,
       3,     2,     4,     4,     2,     2,     2,     0,     1,     2,
       0,     2,     2,     2,     3,     1,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     5,     7,     3,     3,     5,     3,     4,     2,
       2,     0,     2,     2,     1,     1,     2,     1,     2,     0,
       2,     2,     2,     0,     2,     2,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       2,     1,     1,     2,     0,     2,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     0,     0,     0,     0,     0,    25,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* kefalidaprogrammatos: VOID ID OPENBRACKET error CLOSEBRACKET  */
#line 119 "bison.y"
                                                                                 {yyclearin;  yyerrok;}
#line 1629 "bison.tab.c"
    break;

  case 23: /* kefalidasunartisis: typos_synartisis_metavlites OPENBRACKET error CLOSEBRACKET  */
#line 142 "bison.y"
                                                                                              {yyclearin; yyerrok;}
#line 1635 "bison.tab.c"
    break;

  case 56: /* anathesi: ID ASSIGN genikiekfrasi error ';'  */
#line 192 "bison.y"
                                                    {yyclearin;  yyerrok; }
#line 1641 "bison.tab.c"
    break;

  case 60: /* listapragmatikwnparametrwn: pragmatikiparametros error  */
#line 198 "bison.y"
                                                                               {yyclearin;  yyerrok; }
#line 1647 "bison.tab.c"
    break;

  case 110: /* $@1: %empty  */
#line 275 "bison.y"
                      {Index = strdup(yytext);}
#line 1653 "bison.tab.c"
    break;

  case 111: /* $@2: %empty  */
#line 275 "bison.y"
                                                                        {startvalue=atoi(yytext);}
#line 1659 "bison.tab.c"
    break;

  case 112: /* $@3: %empty  */
#line 276 "bison.y"
                                            {endvalue=atoi(yytext);}
#line 1665 "bison.tab.c"
    break;

  case 113: /* $@4: %empty  */
#line 277 "bison.y"
                                                     {addvalue=atoi(yytext);}
#line 1671 "bison.tab.c"
    break;

  case 114: /* $@5: %empty  */
#line 279 "bison.y"
                   {
			loopcounter =(endvalue-startvalue)/addvalue;
			if(loopcounter>3)
			{
				k = 1 ;
				flag = FWHILE;
				fprintf(output,"%s = %d ;\n",Index,startvalue);
				fprintf(output,"while (%s < %d) ",Index,endvalue);
				fprintf(output,"{ \n %s = %s + %d;",Index,Index,addvalue);
				flag=DEFAULT;
			}
			else 
			{
				k2=1;
				k=1;
				flag = FFOR;
			}
		   }
#line 1694 "bison.tab.c"
    break;

  case 115: /* $@6: %empty  */
#line 298 "bison.y"
                           {k=1;}
#line 1700 "bison.tab.c"
    break;

  case 116: /* entolifor: FOR OPENBRACKET ID $@1 ASSIGN STATHERAAKERAIOU $@2 SEMICOLON ID LESS STATHERAAKERAIOU $@3 SEMICOLON ID ASSIGN ID ADD STATHERAAKERAIOU $@4 CLOSEBRACKET $@5 OPENBRACE command $@6 CLOSEBRACE  */
#line 299 "bison.y"
                              {
		   			   if (flag == FFOR) 
		   			   	   copyPrint(tmp,2);
		   			   flag=DEFAULT;
		              }
#line 1710 "bison.tab.c"
    break;


#line 1714 "bison.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 308 "bison.y"

void yyerror(char const *s)
{
	fprintf (stderr, "%s\n", s);
	linesWithError[errors]=yylineno;	
	errors++;
	yyclearin;
}

int main(int argc, char *argv[])
{
	fp = fopen (argv[1],"r");
	output = fopen("output.txt", "w");
	if(!fp)
	{
		printf("Can't open file \n");
		return -1;
	}
	yyin = fp;
	do {
			yyparse();
		} 
	while (!feof(yyin));
	if(errors==0)
		printf("Program Parsed Successfully! \n");
	else
	{
		printf("There were %d parsing errors \n",errors);
		for(i=0;i<errors;i++)
			printf("Syntax Error on line %d \n",linesWithError[i]);
	}
	fclose(fp);
	fclose(output);
}

void copyPrint(const char s[],int choice)
{
	char *temp;
	char *tokenize[1000];
	int position=0;
	if(choice == 1)
	{	
		copier = strdup(s);
	    strcat(buffer,copier);  
	    strcat(buffer," ");   
	}
	else if(choice == 2)
	{
		int met = 0,j = 0;
		temp = strdup(buffer);
		printer= strtok(temp," ");
		while(printer!=NULL)
		{	tokenize[met] = printer;
			met++;
			printer = strtok(NULL," ");
		}
		for(i=startvalue;i<endvalue;i=i+addvalue)
	    {
	    	for (j=0;j<met;j++)
	    	{
	    		if (!strcmp(Index,tokenize[j]) && strcmp("=",tokenize[j+1]))
		    		fprintf(output,"%d ",i);
		    	else
		    		fprintf(output,"%s ",tokenize[j]);
	    	}
		}
	}
}
