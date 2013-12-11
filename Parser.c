/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */


#include "Sociaty.h"
#include "Eval.h"
#include "Parser.h"
#include "Lexer.h"

int yyparse(yyscan_t scanner);
int yyerror(yyscan_t scanner, const char *msg){
		printf("yyerror, %s\n",msg);
	}

#define YACCDEBUG
#ifdef YACCDEBUG
#define yd_print(s) \
  {\
    fprintf(ns.Err, "--->Match %s\n", s);\
  }
#else
#define yd_print(s) 
#endif
extern Sociaty ns;
 

#line 97 "Parser.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 32 "Parser.y" /* yacc.c:355  */

#include "Common.h"  
#include "Role.h"
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif
void ParseExpressionFromFile(char *fpath);
void ParseExpressionFromFp(FILE *fp);
void ParseExpressionFromString(char *str);
yyscan_t current_scanner;

#line 140 "Parser.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    INTEGER = 260,
    BLOCK = 261,
    ADDRESS = 262,
    FOR = 263,
    WHILE = 264,
    IF = 265,
    ELSIF = 266,
    ELSE = 267,
    USE = 268,
    LOAD = 269,
    ADD = 270,
    INVOKE = 271,
    PRINT = 272,
    PUTSTR = 273,
    VALUE = 274,
    READFILE = 275,
    NOT = 276,
    ISFILE = 277,
    ISDIR = 278,
    END_OF_STATEMENT = 279,
    SETFLAG = 280,
    SETARGS = 281
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 52 "Parser.y" /* yacc.c:355  */

	Role* roleval;
	int numval;
	RoleArray* rolearr;
	StringInt strint;
	char* strval;

#line 187 "Parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "Parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,     2,
      30,    31,     2,    36,    39,     2,    38,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,     2,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    33,     2,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    94,    99,   100,   101,   105,   111,   112,
     113,   114,   115,   129,   150,   158,   172,   176,   181,   188,
     195,   200,   205,   209,   213,   217,   221,   225,   229,   233,
     237,   241,   247,   254,   275,   304,   309,   314,   319,   326,
     333,   337,   341,   349,   358,   366,   379,   404,   405,   408,
     412,   416,   423,   429,   435,   439,   446,   451,   457,   462
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "INTEGER",
  "BLOCK", "ADDRESS", "FOR", "WHILE", "IF", "ELSIF", "ELSE", "USE", "LOAD",
  "ADD", "INVOKE", "PRINT", "PUTSTR", "VALUE", "READFILE", "NOT", "ISFILE",
  "ISDIR", "END_OF_STATEMENT", "SETFLAG", "SETARGS", "'='", "'<'", "'>'",
  "'('", "')'", "'&'", "'|'", "'['", "']'", "'+'", "':'", "'.'", "','",
  "$accept", "translation_unit", "statement", "expression",
  "control_expression", "else_expression", "boolean_expression",
  "internal_function", "assignment_expression", "inherent_expression",
  "eval_expression", "role_as_const", "const_or_int", "role", "member",
  "argument", "argument_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    60,    62,
      40,    41,    38,   124,    91,    93,    43,    58,    46,    44
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,     5,   -35,    48,    86,    92,    92,    48,   -35,   -35,
     111,   -35,     1,   -35,   -35,   -35,   -35,   -35,    37,    18,
      -3,     0,    12,   -35,   -35,    92,    86,    92,    92,    86,
      15,   -17,   -35,   -35,   -35,   -35,    92,   -35,   -35,   -35,
     -35,    81,    23,    11,    48,   -35,   -35,   -35,    21,    56,
      65,    28,   -35,   -35,   -35,   -35,   -35,   -35,    71,    70,
      73,    78,    42,   127,   -35,    48,    30,   -35,   -35,   -24,
      92,   -35,    30,    52,   -35,   -35,   -35,    85,    77,    60,
      92,    92,    92,   -35,    92,   -35,   -35,    59,   -35,   -35,
     -35,   -35,    86,    86,   -35,    86,   -35,   -35,   -35,   -35,
     -35,   -35,    61,    89,   116,   -35,   -35,   114,    60,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    50,    51,     0,     0,     0,     0,     0,     7,     4,
       0,     2,     0,     8,     9,    10,    11,    12,    40,    49,
       0,     0,     0,    47,    48,     0,     0,     0,     0,     0,
       0,    19,    45,    44,    32,    33,     0,     1,     3,     6,
       5,     0,     0,     0,     0,    56,    57,    58,    42,     0,
       0,     0,    52,    13,    46,    26,    27,    28,     0,    14,
       0,     0,     0,     0,    34,     0,     0,    36,    41,     0,
       0,    39,     0,     0,    54,    53,    29,     0,     0,     0,
       0,     0,     0,    22,     0,    23,    38,     0,    43,    37,
      59,    55,     0,     0,    16,     0,    15,    21,    20,    24,
      25,    35,     0,     0,     0,    30,    31,    17,     0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   113,   -35,   -35,    20,   -12,   -35,   -35,   -35,
     -35,    -5,   -13,     6,   -35,    64,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    96,    30,    14,    15,    16,
      17,    31,    32,    33,    19,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    35,    51,    52,    60,    45,    18,    88,    69,    22,
      61,    62,    63,    36,    55,    72,    18,    58,    53,    39,
      54,    59,    56,    57,    46,    40,     1,    23,    24,    45,
       2,    64,    87,     1,    23,    24,    67,     2,    70,    20,
       1,    23,    24,    21,     2,     1,    23,    24,    46,     2,
      71,     1,    49,    45,    68,     2,    50,    83,    85,    45,
      72,    73,    25,    75,    41,    89,    94,    42,    74,    82,
      95,    86,    46,    43,    44,    97,    98,    99,    46,   100,
     102,   103,    79,   104,     1,    23,    24,    91,     2,     1,
      23,    24,   105,     2,   101,     1,    23,    24,    72,     2,
      80,    25,    76,    77,    78,    81,    25,    26,    27,    28,
      93,    37,    25,    65,     1,    66,    29,    92,     2,     3,
     106,     4,   107,    38,     5,     6,   108,     7,   109,     8,
       1,    23,    24,     0,     2,     9,    90,     0,     1,     0,
       0,     0,     2,     3,     0,     4,     0,    25,     5,     6,
       0,     7,     0,     8,    84,     0,     0,     0,     0,     9
};

static const yytype_int8 yycheck[] =
{
       5,     6,     5,     3,    21,    18,     0,    31,    42,     3,
      27,    28,    29,     7,    26,    39,    10,    29,     6,    18,
      25,     6,    27,    28,    18,    24,     3,     4,     5,    42,
       7,    36,    66,     3,     4,     5,    41,     7,    27,    34,
       3,     4,     5,    38,     7,     3,     4,     5,    42,     7,
      44,     3,    34,    66,    31,     7,    38,    62,    63,    72,
      39,     5,    20,    35,    27,    70,     6,    30,     3,    27,
      10,    65,    66,    36,    37,    80,    81,    82,    72,    84,
      92,    93,    12,    95,     3,     4,     5,    35,     7,     3,
       4,     5,    31,     7,    35,     3,     4,     5,    39,     7,
      27,    20,    31,    32,    33,    27,    20,    21,    22,    23,
      33,     0,    20,    32,     3,    34,    30,    32,     7,     8,
      31,    10,     6,    10,    13,    14,    12,    16,   108,    18,
       3,     4,     5,    -1,     7,    24,    72,    -1,     3,    -1,
      -1,    -1,     7,     8,    -1,    10,    -1,    20,    13,    14,
      -1,    16,    -1,    18,    27,    -1,    -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     8,    10,    13,    14,    16,    18,    24,
      41,    42,    43,    44,    47,    48,    49,    50,    53,    54,
      34,    38,    53,     4,     5,    20,    21,    22,    23,    30,
      46,    51,    52,    53,    51,    51,    53,     0,    42,    18,
      24,    27,    30,    36,    37,    52,    53,    55,    56,    34,
      38,     5,     3,     6,    51,    46,    51,    51,    46,     6,
      21,    27,    28,    29,    51,    32,    34,    51,    31,    56,
      27,    53,    39,     5,     3,    35,    31,    32,    33,    12,
      27,    27,    27,    51,    27,    51,    53,    56,    31,    51,
      55,    35,    32,    33,     6,    10,    45,    51,    51,    51,
      51,    35,    46,    46,    46,    31,    31,     6,    12,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    42,    43,    43,
      43,    43,    43,    44,    44,    44,    45,    45,    45,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    48,    48,    48,    48,    49,
      50,    50,    50,    50,    51,    51,    51,    52,    52,    53,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     5,     1,     3,     5,     1,
       4,     4,     3,     3,     4,     4,     2,     2,     2,     3,
       6,     6,     2,     2,     3,     5,     3,     4,     4,     3,
       1,     3,     2,     4,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     4,     3,     4,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, yyscan_t scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 91 "Parser.y" /* yacc.c:1661  */
    { 
  yd_print("statement");
}
#line 1346 "Parser.c" /* yacc.c:1661  */
    break;

  case 3:
#line 94 "Parser.y" /* yacc.c:1661  */
    { 
	yd_print("translation_unit statement");
}
#line 1354 "Parser.c" /* yacc.c:1661  */
    break;

  case 6:
#line 102 "Parser.y" /* yacc.c:1661  */
    {
	Sociaty_PutString((yyvsp[0].strval));
}
#line 1362 "Parser.c" /* yacc.c:1661  */
    break;

  case 7:
#line 106 "Parser.y" /* yacc.c:1661  */
    {
	Sociaty_PutString((yyvsp[0].strval));
}
#line 1370 "Parser.c" /* yacc.c:1661  */
    break;

  case 12:
#line 116 "Parser.y" /* yacc.c:1661  */
    {
	char *rtn;
	rtn = Eval((yyvsp[0].roleval));
	if(rtn != NULL){
		yd_print(rtn);
		ParseExpressionFromString(rtn);
	}
//	Sociaty_WriteMembers();
//	printf("clearargs%d\n", $1);
//	Sociaty_ClearArgs($1);
}
#line 1386 "Parser.c" /* yacc.c:1661  */
    break;

  case 13:
#line 130 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("FOR");
	int i;
	Role *ri, *rt;
	char str[8];
	char *rtn;
	rt = Sociaty_RoleEmploy((yyvsp[-1].roleval), "_Iterator");
	ri = Sociaty_RoleEmploy((yyvsp[-1].roleval), "_Index");
	for(i=0; i< (yyvsp[-1].roleval)->_Elements->Length; i++){
    Role_SetTarget(rt, (yyvsp[-1].roleval)->_Elements->Values[i]);
		sprintf(str, "%d", i);
		Role_SetValue(ri, estrdup(str));
////////////////
		if((yyvsp[0].strval)!=NULL){
			rtn = EvalString((yyvsp[-1].roleval), (yyvsp[0].strval), 1);
			ParseExpressionFromString(rtn);
		}
///////////////
  }
}
#line 1411 "Parser.c" /* yacc.c:1661  */
    break;

  case 14:
#line 151 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("IF");
	if((yyvsp[-1].numval)){
		estraddeol(&(yyvsp[0].strval));
		ParseExpressionFromString((yyvsp[0].strval));
	}
}
#line 1423 "Parser.c" /* yacc.c:1661  */
    break;

  case 15:
#line 159 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("IF ELSE");
  if((yyvsp[-3].numval)){
		estraddeol(&(yyvsp[-2].strval));
    ParseExpressionFromString((yyvsp[-2].strval));
  }
	else{
		estraddeol(&(yyvsp[0].strval));
		ParseExpressionFromString((yyvsp[0].strval));
	}
}
#line 1439 "Parser.c" /* yacc.c:1661  */
    break;

  case 16:
#line 173 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.strval) = (yyvsp[0].strval);
}
#line 1447 "Parser.c" /* yacc.c:1661  */
    break;

  case 17:
#line 177 "Parser.y" /* yacc.c:1661  */
    {
	if((yyvsp[-1].numval)) (yyval.strval) = (yyvsp[0].strval);
	else (yyval.strval) = estrdup("");
}
#line 1456 "Parser.c" /* yacc.c:1661  */
    break;

  case 18:
#line 182 "Parser.y" /* yacc.c:1661  */
    {
	if((yyvsp[-3].numval)) (yyval.strval) = (yyvsp[-2].strval);
  else (yyval.strval) = (yyvsp[0].strval);
}
#line 1465 "Parser.c" /* yacc.c:1661  */
    break;

  case 19:
#line 189 "Parser.y" /* yacc.c:1661  */
    {
	if(!estrisnull((yyvsp[0].strval)) && strcmp((yyvsp[0].strval), "0"))
		(yyval.numval) = 1;
	else
		(yyval.numval) = 0;
}
#line 1476 "Parser.c" /* yacc.c:1661  */
    break;

  case 20:
#line 196 "Parser.y" /* yacc.c:1661  */
    {
	if(!strcmp((yyvsp[-3].strval), (yyvsp[0].strval))) (yyval.numval) = 1;
	else (yyval.numval) = 0;
}
#line 1485 "Parser.c" /* yacc.c:1661  */
    break;

  case 21:
#line 201 "Parser.y" /* yacc.c:1661  */
    {
	if(strcmp((yyvsp[-3].strval), (yyvsp[0].strval))) (yyval.numval) = 1;
	else (yyval.numval) = 0;
}
#line 1494 "Parser.c" /* yacc.c:1661  */
    break;

  case 22:
#line 206 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (atoi((yyvsp[-2].strval)) < atoi((yyvsp[0].strval)));
}
#line 1502 "Parser.c" /* yacc.c:1661  */
    break;

  case 23:
#line 210 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (atoi((yyvsp[-2].strval)) >= atoi((yyvsp[0].strval)));
}
#line 1510 "Parser.c" /* yacc.c:1661  */
    break;

  case 24:
#line 214 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = (atoi((yyvsp[-3].strval)) <= atoi((yyvsp[0].strval)));
}
#line 1518 "Parser.c" /* yacc.c:1661  */
    break;

  case 25:
#line 218 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = (atoi((yyvsp[-3].strval)) >= atoi((yyvsp[0].strval)));
}
#line 1526 "Parser.c" /* yacc.c:1661  */
    break;

  case 26:
#line 222 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = !(yyvsp[0].numval);
}
#line 1534 "Parser.c" /* yacc.c:1661  */
    break;

  case 27:
#line 226 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = eisfile((yyvsp[0].strval));
}
#line 1542 "Parser.c" /* yacc.c:1661  */
    break;

  case 28:
#line 230 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = eisdir((yyvsp[0].strval));
}
#line 1550 "Parser.c" /* yacc.c:1661  */
    break;

  case 29:
#line 234 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (yyvsp[-1].numval);
}
#line 1558 "Parser.c" /* yacc.c:1661  */
    break;

  case 30:
#line 238 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.numval) = (yyvsp[-4].numval) && (yyvsp[-1].numval);
}
#line 1566 "Parser.c" /* yacc.c:1661  */
    break;

  case 31:
#line 242 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.numval) = (yyvsp[-4].numval) || (yyvsp[-1].numval);
}
#line 1574 "Parser.c" /* yacc.c:1661  */
    break;

  case 32:
#line 248 "Parser.y" /* yacc.c:1661  */
    {
	char *fpath;
  fpath = UseFile((yyvsp[0].strval));
		if(fpath != NULL)
			ParseExpressionFromFile(fpath);
}
#line 1585 "Parser.c" /* yacc.c:1661  */
    break;

  case 33:
#line 255 "Parser.y" /* yacc.c:1661  */
    {
	ParseExpressionFromFile((yyvsp[0].strval));
}
#line 1593 "Parser.c" /* yacc.c:1661  */
    break;

  case 34:
#line 276 "Parser.y" /* yacc.c:1661  */
    {
  yd_print("INVOKE");
	char *rtn;
	rtn = EvalString((yyvsp[-1].roleval), (yyvsp[0].strval), 1);
//  yd_print(rtn);
	ParseExpressionFromString(rtn);
}
#line 1605 "Parser.c" /* yacc.c:1661  */
    break;

  case 35:
#line 305 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("ASSIGN ARRAY");
	Sociaty_RoleSetElements((yyvsp[-4].roleval), (yyvsp[-1].rolearr));
}
#line 1614 "Parser.c" /* yacc.c:1661  */
    break;

  case 36:
#line 310 "Parser.y" /* yacc.c:1661  */
    { 
	yd_print("ASSIGN VALUE");
	Role_SetValue((yyvsp[-2].roleval), estrdup((yyvsp[0].strval)));
}
#line 1623 "Parser.c" /* yacc.c:1661  */
    break;

  case 37:
#line 315 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("CONCAT VALUE");
  estrcat(&(yyvsp[-3].roleval)->_Value, (yyvsp[0].strval));
}
#line 1632 "Parser.c" /* yacc.c:1661  */
    break;

  case 38:
#line 320 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("ASSIGN REF");
	Role_SetTarget((yyvsp[-3].roleval), (yyvsp[0].roleval));
}
#line 1641 "Parser.c" /* yacc.c:1661  */
    break;

  case 39:
#line 327 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("INHERENT");
	Role_AddPrt((yyvsp[-2].roleval), (yyvsp[0].roleval));
}
#line 1650 "Parser.c" /* yacc.c:1661  */
    break;

  case 40:
#line 333 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("EVAL");
	(yyval.roleval) = (yyvsp[0].roleval); 
}
#line 1659 "Parser.c" /* yacc.c:1661  */
    break;

  case 41:
#line 337 "Parser.y" /* yacc.c:1661  */
    {  
	yd_print("EVAL");
	(yyval.roleval) = (yyvsp[-2].roleval); 
}
#line 1668 "Parser.c" /* yacc.c:1661  */
    break;

  case 42:
#line 342 "Parser.y" /* yacc.c:1661  */
    {

	yd_print("EVAL ARGS");
	Role *t = Sociaty_RoleEmploy((yyvsp[-1].roleval), "_Args");
	Sociaty_RoleSetElements(t, (yyvsp[0].rolearr));
	(yyval.roleval) = (yyvsp[-1].roleval);
}
#line 1680 "Parser.c" /* yacc.c:1661  */
    break;

  case 43:
#line 350 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("EVAL ARGS");
  Role *t = Sociaty_RoleEmploy((yyvsp[-3].roleval), "_Args");
	Sociaty_RoleSetElements(t, (yyvsp[-1].rolearr));
	(yyval.roleval) = (yyvsp[-3].roleval);
}
#line 1691 "Parser.c" /* yacc.c:1661  */
    break;

  case 44:
#line 358 "Parser.y" /* yacc.c:1661  */
    {
//////////////////////////////////////////////////////
	char *v=GetDymValue((yyvsp[0].roleval));
	if(v == NULL) (yyval.strval) = NULL;
	else (yyval.strval) = EvalString((yyvsp[0].roleval), v, 0);

////////////////
}
#line 1704 "Parser.c" /* yacc.c:1661  */
    break;

  case 45:
#line 366 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.strval) = (yyvsp[0].strval);
}
#line 1712 "Parser.c" /* yacc.c:1661  */
    break;

  case 46:
#line 380 "Parser.y" /* yacc.c:1661  */
    {
	yd_print("READFILE");
	char* fpath;
  FILE *fp;
  fpath=GetPath((yyvsp[0].strval));
  if(fpath == NULL){
		(yyval.strval) = "";
  }
	yd_print(fpath);
  fp = fopen(fpath, "r");
  (yyval.strval) = ereadfile(fp);
}
#line 1729 "Parser.c" /* yacc.c:1661  */
    break;

  case 47:
#line 404 "Parser.y" /* yacc.c:1661  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1735 "Parser.c" /* yacc.c:1661  */
    break;

  case 48:
#line 405 "Parser.y" /* yacc.c:1661  */
    {(yyval.strval) = (yyvsp[0].strval); }
#line 1741 "Parser.c" /* yacc.c:1661  */
    break;

  case 49:
#line 409 "Parser.y" /* yacc.c:1661  */
    {
  (yyval.roleval) = (yyvsp[0].roleval);
}
#line 1749 "Parser.c" /* yacc.c:1661  */
    break;

  case 50:
#line 413 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.roleval) = Sociaty_RoleEmploy(ns.Curr, (yyvsp[0].strval));
}
#line 1757 "Parser.c" /* yacc.c:1661  */
    break;

  case 51:
#line 417 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.roleval) = (Role*)atol((yyvsp[0].strval));
}
#line 1765 "Parser.c" /* yacc.c:1661  */
    break;

  case 52:
#line 424 "Parser.y" /* yacc.c:1661  */
    {
	Role *r;
	r = Sociaty_RoleEmploy(ns.Curr, (yyvsp[-2].strval));
	(yyval.roleval) = Sociaty_RoleEmploy(r, (yyvsp[0].strval));
}
#line 1775 "Parser.c" /* yacc.c:1661  */
    break;

  case 53:
#line 430 "Parser.y" /* yacc.c:1661  */
    {
	Role *r;
  r = Sociaty_RoleEmploy(ns.Curr, (yyvsp[-3].strval));
	(yyval.roleval) = Sociaty_RoleExpend(r, atoi((yyvsp[-1].strval)));
}
#line 1785 "Parser.c" /* yacc.c:1661  */
    break;

  case 54:
#line 436 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.roleval) = Sociaty_RoleEmploy((yyvsp[-2].roleval), (yyvsp[0].strval));
}
#line 1793 "Parser.c" /* yacc.c:1661  */
    break;

  case 55:
#line 440 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.roleval) = Sociaty_RoleExpend((yyvsp[-3].roleval), atoi((yyvsp[-1].strval)));
}
#line 1801 "Parser.c" /* yacc.c:1661  */
    break;

  case 56:
#line 447 "Parser.y" /* yacc.c:1661  */
    {	
	(yyval.roleval) = Role_New();
	(yyval.roleval)->_Value = (yyvsp[0].strval);
}
#line 1810 "Parser.c" /* yacc.c:1661  */
    break;

  case 57:
#line 452 "Parser.y" /* yacc.c:1661  */
    {
	(yyval.roleval) = (yyvsp[0].roleval);
}
#line 1818 "Parser.c" /* yacc.c:1661  */
    break;

  case 58:
#line 458 "Parser.y" /* yacc.c:1661  */
    { 
	RoleArray_Init(&(yyval.rolearr)); 
	RoleArray_Add((yyval.rolearr), (yyvsp[0].roleval));
}
#line 1827 "Parser.c" /* yacc.c:1661  */
    break;

  case 59:
#line 462 "Parser.y" /* yacc.c:1661  */
    { 
	RoleArray_Add((yyvsp[-2].rolearr), (yyvsp[0].roleval));
	(yyval.rolearr) = (yyvsp[-2].rolearr);
}
#line 1836 "Parser.c" /* yacc.c:1661  */
    break;


#line 1840 "Parser.c" /* yacc.c:1661  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, scanner);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 468 "Parser.y" /* yacc.c:1906  */


	//void ParseExpressionFromString(Expression *expr, char *str){
void ParseExpressionFromFp(FILE *fp){
	char *content;
	content = ereadfile(fp);
	estraddeol(&content);
	ParseExpressionFromString(content);
//	free(fpath);
}
void ParseExpressionFromFile(char *fpath){
  char *content;
  FILE *ifp;
  if(fpath[0]){
    if((ifp=fopen(fpath,"r")) != NULL){
			ParseExpressionFromFp(ifp);
		}
		else{
			eerror("file not exist");
			exit(1);
		}
  }
  else{
    eerror("file not exist");
    exit(1);
  }
	fclose(ifp);
//  free(fpath);
}

void ParseExpressionFromString(char *str){
//	printf("\nParseExpressionFromString\n=====\n%s\n=====\n\n", str);
  yyscan_t scanner;
	current_scanner = scanner;
  YY_BUFFER_STATE state;
	if (yylex_init(&scanner)) {
    // couldn't initialize
		eerror("yylex_init failed");
    return;
  }
	state = yy_scan_string(str, scanner);
//	if (yyparse(&expr, scanner)) {
	if (yyparse(scanner)){
    // error parsing
		eerror("yyparse failed");
    exit(1);
  }
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);
//	free(str);

}
