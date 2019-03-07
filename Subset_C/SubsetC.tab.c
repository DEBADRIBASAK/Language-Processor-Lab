/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "SubsetC.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "SubSet.h"
	extern int yylineno;
	extern int yylex();
	extern FILE *yyin,*yyout;
	int yyerror(char* s);
	
int varcounter = 1,labelcounter = 1;
struct symbol_table tab[NHASH];
char label[10] = {'L','\0'};
char temp_var[10] = {'t','\0'};

#line 82 "SubsetC.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN = 258,
    DATATYPE = 259,
    ID = 260,
    INTEGER = 261,
    FLOAT = 262,
    ERR = 263,
    LOG = 264,
    ASSGN = 265,
    BIT = 266,
    CMP = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    WHILE = 271
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "SubsetC.y" /* yacc.c:355  */

	struct ast* a;
	double d;
	struct symbol_table *s;
	int assfn,logfn,bitfn,i,errfn,fn,dt;

#line 143 "SubsetC.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 160 "SubsetC.tab.c" /* yacc.c:358  */

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  4
/* YYNRULES -- Number of rules.  */
#define YYNRULES  28
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  77

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   271

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    23,     2,     2,
      25,    26,    21,    19,     2,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,    29,
       2,     2,     2,    17,    24,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    71,    72,
      73,    79,    80,    81,    82,    83,    84,    86,    87
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "DATATYPE", "ID", "INTEGER",
  "FLOAT", "ERR", "LOG", "ASSGN", "BIT", "CMP", "IF", "ELSE", "FOR",
  "WHILE", "'?'", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'@'", "'('",
  "')'", "'{'", "'}'", "';'", "$accept", "exp", "stmt", "calclist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    63,    58,    43,
      45,    42,    47,    37,    64,    40,    41,   123,   125,    59
};
# endif

#define YYPACT_NINF -27

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-27)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   139,   -27,   -26,    -3,    -1,   -27,   -27,   193,    49,
      49,   -21,   -18,   -15,    -6,   -27,   193,   -17,    49,   -27,
     147,   147,    49,    49,    49,    49,    49,    49,   193,    49,
      49,    49,    49,    49,    49,   193,    -9,   193,   147,    82,
      50,    98,   147,   147,   147,     6,   151,   151,   167,   167,
     171,   171,   -27,   -27,   -27,    -2,    49,     1,   193,   193,
      66,   193,   -27,     3,    49,     4,    19,   114,   -27,    13,
      20,   193,   193,    21,    24,   -27,   -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      27,     0,     1,     0,     0,     4,     2,     3,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,    25,
      13,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,    17,     0,
       0,     0,    12,    15,    14,     0,     5,     6,     7,     8,
      10,     9,    20,    18,    19,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,    21,     0,    23,     0,
       0,     0,     0,     0,     0,    22,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,    12,    -8,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,     1
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    16,    17,    25,    22,    26,    27,    23,    36,    18,
      24,    28,    37,    29,    30,    31,    32,    33,    34,    53,
      45,    20,    21,    35,    58,    59,     0,    52,    61,    54,
      38,    66,    68,    69,    39,    40,    41,    42,    43,    44,
      71,    46,    47,    48,    49,    50,    51,    72,     0,    75,
      62,    63,    76,    65,     5,     6,     7,     0,     9,    25,
      10,    26,    27,    73,    74,     0,     0,    28,    60,    29,
      30,    31,    32,    33,    34,    25,    67,    26,    27,    56,
       0,     0,     0,    28,     0,    29,    30,    31,    32,    33,
      34,    25,     0,    26,    27,    64,     0,     0,     0,    28,
       0,    29,    30,    31,    32,    33,    34,    25,    55,    26,
      27,     0,     0,     0,     0,    28,     0,    29,    30,    31,
      32,    33,    34,    25,    57,    26,    27,     0,     0,     0,
       0,    28,     0,    29,    30,    31,    32,    33,    34,     2,
      70,     0,     3,     4,     5,     6,     7,     8,     9,     0,
      10,     0,    11,     0,    12,    13,    25,     0,    26,    27,
      25,     0,    26,    27,    28,     0,    29,    30,    31,    32,
      33,    34,    31,    32,    33,    34,    25,     0,    26,    27,
      25,     0,    26,    27,     0,     0,     0,     0,     0,     0,
      33,    34,     0,     0,     0,    34,     3,     4,     5,     6,
       7,     8,     9,     0,    10,     0,    11,     0,    12,    13
};

static const yytype_int8 yycheck[] =
{
       8,    27,     5,     9,    25,    11,    12,    25,    16,    10,
      25,    17,    29,    19,    20,    21,    22,    23,    24,    28,
      28,     9,    10,    29,    18,    27,    -1,    35,    27,    37,
      18,    28,    28,    14,    22,    23,    24,    25,    26,    27,
      27,    29,    30,    31,    32,    33,    34,    27,    -1,    28,
      58,    59,    28,    61,     5,     6,     7,    -1,     9,     9,
      11,    11,    12,    71,    72,    -1,    -1,    17,    56,    19,
      20,    21,    22,    23,    24,     9,    64,    11,    12,    29,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,     9,    -1,    11,    12,    29,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,     9,    26,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,     9,    26,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,     0,
      26,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    13,    -1,    15,    16,     9,    -1,    11,    12,
       9,    -1,    11,    12,    17,    -1,    19,    20,    21,    22,
      23,    24,    21,    22,    23,    24,     9,    -1,    11,    12,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    24,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,    -1,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,     0,     3,     4,     5,     6,     7,     8,     9,
      11,    13,    15,    16,    31,    32,    27,     5,    10,    32,
      31,    31,    25,    25,    25,     9,    11,    12,    17,    19,
      20,    21,    22,    23,    24,    29,    32,    29,    31,    31,
      31,    31,    31,    31,    31,    32,    31,    31,    31,    31,
      31,    31,    32,    28,    32,    26,    29,    26,    18,    27,
      31,    27,    32,    32,    29,    32,    28,    31,    28,    14,
      26,    27,    27,    32,    32,    28,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    33,    33
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     5,     3,     2,     3,     3,     2,     3,     4,     4,
       3,     7,    11,     7,    11,     2,     2,     0,     2
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
      yychar = yylex ();
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
#line 52 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newnum('N',1,(double)(yyvsp[0].i));}
#line 1298 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newnum('N',2,(yyvsp[0].d));}
#line 1304 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newref('R',(yyvsp[0].s));}
#line 1310 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 55 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1316 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 56 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1322 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 57 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1328 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 58 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1334 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 59 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newast('@',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1340 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 60 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newast('%',(yyvsp[-2].a),(yyvsp[0].a));}
#line 1346 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 61 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newflow('I',2,(yyvsp[-4].a),(yyvsp[-2].a),(yyvsp[0].a),NULL,NULL);}
#line 1352 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 62 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newlog('L',(yyvsp[-1].logfn),(yyvsp[-2].a),(yyvsp[0].a));}
#line 1358 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 63 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newlog('L',(yyvsp[-1].logfn),NULL,(yyvsp[0].a));}
#line 1364 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 64 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newcmp('C',(yyvsp[-1].fn),(yyvsp[-2].a),(yyvsp[0].a));}
#line 1370 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 65 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newbit('B',(yyvsp[-1].bitfn),(yyvsp[-2].a),(yyvsp[0].a));}
#line 1376 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 66 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newlog('B',(yyvsp[-1].bitfn),NULL,(yyvsp[0].a));}
#line 1382 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 67 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newassgn('A',(yyvsp[-1].assfn),(yyvsp[-2].s),(yyvsp[0].a));}
#line 1388 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 71 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = (yyvsp[-1].a);}
#line 1394 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 72 "SubsetC.y" /* yacc.c:1646  */
    { (yyval.a) = newast('S',newassgn('A',1,(yyvsp[-2].s),newnum('N',1,0.0)),(yyvsp[0].a)); }
#line 1400 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "SubsetC.y" /* yacc.c:1646  */
    { 
    			if((yyvsp[0].a)==NULL)
    			(yyval.a) = (yyvsp[-2].a);
    			else
    			(yyval.a) = newast('S',(yyvsp[-2].a),(yyvsp[0].a));
    		   }
#line 1411 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 79 "SubsetC.y" /* yacc.c:1646  */
    { (yyval.a) = newflow('I',1,(yyvsp[-4].a),(yyvsp[-1].a),NULL,NULL,NULL);}
#line 1417 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 80 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newflow('I',2,(yyvsp[-8].a),(yyvsp[-5].a),(yyvsp[-1].a),NULL,NULL);}
#line 1423 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 81 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newflow('W',1,(yyvsp[-4].a),(yyvsp[-1].a),NULL,NULL,NULL);}
#line 1429 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 82 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = newflow('F',2,(yyvsp[-6].a),(yyvsp[-1].a),NULL,(yyvsp[-8].a),(yyvsp[-4].a));}
#line 1435 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 83 "SubsetC.y" /* yacc.c:1646  */
    { yyerror("One error ocurred");}
#line 1441 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 84 "SubsetC.y" /* yacc.c:1646  */
    {(yyval.a) = (yyvsp[-1].a);}
#line 1447 "SubsetC.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 87 "SubsetC.y" /* yacc.c:1646  */
    {generate_code((yyvsp[0].a));}
#line 1453 "SubsetC.tab.c" /* yacc.c:1646  */
    break;


#line 1457 "SubsetC.tab.c" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 89 "SubsetC.y" /* yacc.c:1906  */


int hash(char* s)
{
	int n = strlen(s);
	int h = 0;
	for(int i=0;i<n;i++)
	{
		h = (h+((int)s[i])*(i+1))%NHASH;
	}
	return h;
}

struct symbol_table* insert_into_symbol_table(char* s)
{
	int h = hash(s),i;
	printf("Hash: %d\n",h);
	i = h;int lookups = NHASH;
	struct symbol_table* sp;
	sp = &tab[h];
	while(lookups--)
	{
		if(sp->type==-1)
		{
			printf("Inserting at: %d\n",i);
			sp->name = (char*)malloc(sizeof(char));
			strcpy(sp->name,s);
			return sp;
		}
		i = (i+1)%NHASH;
		sp++;
		if(sp>=tab+NHASH)
		sp = tab;
	}
	return NULL;
}

struct symbol_table* search(char* s,int scope)
{
//	printf("Here\n");
	int h = hash(s);
	//printf("Here\n");
	int i =h,lookups = NHASH;
	struct symbol_table* sp;
	sp = &tab[h];
	while(lookups--)
	{
		//printf("*\n");
		if(sp->type==-1)
		{
			printf("Returning\n");
			return NULL;
		}
		else if(sp->scope==scope&&strcmp(sp->name,s)==0)
		{
			printf("Found at: %d\n",i);
			return sp;
		}
		i = (i+1)%NHASH;
		sp++;
		if(sp>=tab+NHASH)
		sp = tab;
	}
	//printf("Returning\n");
	return NULL;
}

struct ast* newast(int nodetype,struct ast* l,struct ast* r)
{
	struct ast* a = (struct ast*)malloc(sizeof(struct ast));
	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}

struct ast* newnum(int nodetype,int type,double val)
{
	struct num* a = (struct num*)malloc(sizeof(struct num));
	a->nodetype = nodetype;
	a->type = type;
	a->val = val;
	return (struct ast*)a;
}

struct ast* newref(int nodetype,struct symbol_table* s)
{
	struct ref* a = (struct ref*)malloc(sizeof(struct ref));
	a->nodetype = nodetype;
	a->s = s;
	return (struct ast*)a;
}

struct ast* newassgn(int nodetype,int type,struct symbol_table* s,struct ast* t)
{
	struct assgn* a = (struct assgn*)malloc(sizeof(struct assgn));
	a->nodetype = nodetype;
	a->type = type;
	a->sym = s;
	a->s = t;
	return (struct ast*)a;
}

struct ast* newcmp(int nodetype,int type,struct ast* exp,struct ast* s)
{
	struct cmpnode* a = (struct cmpnode*)malloc(sizeof(struct cmpnode));
	a->nodetype = nodetype;
	a->type = type;
	a->l = exp;
	a->r = s;
	return (struct ast*)a;
}

struct ast* newflow(int nodetype,int type,struct ast* cond,struct ast* s,struct ast* e,struct ast* init,struct ast *inc)
{
	struct flow* a = (struct flow*)malloc(sizeof(struct flow));
	a->nodetype = nodetype;
	a->type = type;
	a->cond = cond;
	a->s = s;
	a->e = e;
	a->init = init;
	a->inc = inc;
	return (struct ast*)a;
}

struct ast* newbit(int nodetype,int type,struct ast* l,struct ast* r)
{
	struct bitwise* a = (struct bitwise*)malloc(sizeof(struct bitwise));
	a->nodetype = nodetype;
	a->type = type;
	a->l = l;
	a->r = r;
	return (struct ast*)a;
}

struct ast* newlog(int nodetype,int type,struct ast* l,struct ast* r)
{
	struct logical* a = (struct logical*)malloc(sizeof(struct logical));
	a->nodetype = nodetype;
	a->type = type;
	a->l = l;
	a->r = r;
	return (struct ast*)a;
}


char* generate_code(struct ast* a)
{
	if(a==NULL)
	return NULL;
	int st;
	char* rtn = (char*)malloc(sizeof(char)*50);
	char* s = (char*)malloc(sizeof(char)*50);
	char* l = (char*)malloc(sizeof(char)*50);
	char* r = (char*)malloc(sizeof(char)*50);
	switch(a->nodetype)
	{
		case 'N': // just a number
		
		if(((struct num*)a)->type==1)
		sprintf(rtn," %d",(int)((struct num*)a)->val);
		else
		sprintf(rtn," %f",((struct num*)a)->val);
		break;
		
		case 'R':
		sprintf(rtn," %s",((struct ref*)a)->s->name);
		break;
		
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '@':
		
		l = strdup(generate_code(a->l));
		r = strdup(generate_code(a->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d",varcounter);
		varcounter++;
		sprintf(s+strlen(s),"%s ",l);
		l[0] = a->nodetype;
		l[1] = '\0';
		sprintf(s+strlen(s),"%s ",l);
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'C':
		
		l = strdup(generate_code(((struct cmpnode*)a)->l));
		r = strdup(generate_code(((struct cmpnode*)a)->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d",varcounter);
		sprintf(s+strlen(s),"%s",l);
		if(((struct cmpnode*)a)->type==1)
		sprintf(s+strlen(s)," > ");
		else if(((struct cmpnode*)a)->type==2)
		sprintf(s+strlen(s)," < ");
		else if(((struct cmpnode*)a)->type==3)
		sprintf(s+strlen(s)," >= ");
		else if(((struct cmpnode*)a)->type==4)
		sprintf(s+strlen(s)," <= ");
		else if(((struct cmpnode*)a)->type==5)
		sprintf(s+strlen(s)," == ");
		else if(((struct cmpnode*)a)->type==6)
		sprintf(s+strlen(s)," != ");
		
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'L':
		if(((struct logical*)a)->l!=NULL)
		l = strdup(generate_code(((struct logical*)a)->l));
		r = strdup(generate_code(((struct logical*)a)->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d = ",varcounter);
		if(((struct logical*)a)->l!=NULL)
		sprintf(s+strlen(s),"%s",l);
		if(((struct logical*)a)->type==1)
		sprintf(s+strlen(s)," || ");
		else if(((struct logical*)a)->type==2)
		sprintf(s+strlen(s)," && ");
		else if(((struct logical*)a)->type==3)
		sprintf(s+strlen(s)," ! ");
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'B':
		if(((struct bitwise*)a)->l!=NULL)
		l = strdup(generate_code(((struct bitwise*)a)->l));
		r = strdup(generate_code(((struct bitwise*)a)->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d = ",varcounter);
		if(((struct bitwise*)a)->l!=NULL)
		sprintf(s+strlen(s),"%s",l);
		if(((struct bitwise*)a)->type==1)
		sprintf(s+strlen(s)," | ");
		else if(((struct bitwise*)a)->type==2)
		sprintf(s+strlen(s)," & ");
		else if(((struct bitwise*)a)->type==3)
		sprintf(s+strlen(s)," ~ ");
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'A':
		printf("Assignment operation: %s\n",((struct assgn*)a)->sym->name);
		r = strdup(generate_code(((struct assgn*)a)->s));
		sprintf(s,"%s",((struct assgn*)a)->sym->name);
		sprintf(rtn,"%s",((struct assgn*)a)->sym->name);
		sprintf(s+strlen(s)," = ");
		// few lines are to be added
		
		if(((struct assgn*)a)->type==2)
		sprintf(s+strlen(s),"%s + ",((struct assgn*)a)->sym->name);
		else if(((struct assgn*)a)->type==3)
		sprintf(s+strlen(s),"%s - ",((struct assgn*)a)->sym->name);
		else if(((struct assgn*)a)->type==4)
		sprintf(s+strlen(s),"%s * ",((struct assgn*)a)->sym->name);
		else if(((struct assgn*)a)->type==5)
		sprintf(s+strlen(s),"%s / ",((struct assgn*)a)->sym->name);
		sprintf(s+strlen(s),"%s",r);
		
		break;
		
		case 'I': // now the tricky part!!!
		//char* sto = (char*)malloc(sizeof(char)*10);
		st = labelcounter;
		l = strdup(generate_code(((struct flow*)a)->cond));
		fprintf(yyout,"L%d: \n",labelcounter);
		fprintf(yyout,"if (%s) goto L%d\ngoto L%d\nL%d: \n",l,labelcounter+1,labelcounter+2,labelcounter+1);
		generate_code(((struct flow*)a)->s);
		fprintf(yyout,"L%d: ",labelcounter+2);
		labelcounter+=2;
		if(((struct flow*)a)->e!=NULL)
		{
			generate_code(((struct flow*)a)->e);
		}
		break;
		
		case 'W':
		st = labelcounter;
		l = strdup(generate_code(((struct flow*)a)->cond));
		fprintf(yyout,"L%d: \n",labelcounter);
		fprintf(yyout,"if (%s) goto L%d\ngoto L%d\nL%d: \n",l,labelcounter+1,labelcounter+2,labelcounter+1);
		generate_code(((struct flow*)a)->s);
		fprintf(yyout,"goto L%d\n",st);
		fprintf(yyout,"L%d: ",labelcounter+2);
		labelcounter+=2;
		break;
		
		case 'F':
		generate_code(((struct flow*)a)->init);
		st = labelcounter;
		fprintf(yyout,"L%d: \n",labelcounter);
		l = strdup(generate_code(((struct flow*)a)->cond));
		fprintf(yyout,"if (%s) goto L%d\ngoto L%d\nL%d: \n",l,labelcounter+1,labelcounter+2,labelcounter+1);
		generate_code(((struct flow*)a)->s);
		generate_code(((struct flow*)a)->inc);
		fprintf(yyout,"goto L%d\n",st);
		fprintf(yyout,"L%d: ",labelcounter+2);
		labelcounter+=2;
		break;
		
		case 'S':
		generate_code(a->l);
		generate_code(a->r);
		break;
	}
	if(a->nodetype!='N'&&a->nodetype!='R'&&a->nodetype!='I'&&a->nodetype!='F'&&a->nodetype!='W'&&a->nodetype!='S')
	{
		fprintf(yyout,"%s\n",s);
	}
	return rtn;
}


int main(int argc,char *argv[])
{
	for(int i=0;i<NHASH;i++)
	{
		tab[i].type = -1;
		tab[i].scope = -1;
		tab[i].name = NULL;
		tab[i].val = 0;
	}
	yydebug = 1;
	if(argc!=2)
	{
		printf("Number of input files not proper");
		exit(0);
	}
	yyin = fopen(argv[1],"r");
	if(yyin==NULL)
	{
		perror("Input file not opened");
		exit(0);
	}
	yyout = fopen("out.txt","w");
	if(yyout==NULL)
	{
		perror("Output file not opened");
		exit(0);
	}
	yyparse();
	return 0;
}

int yyerror(char* s)
{
	printf("ERROR: %s\n",s);
	return 0;
}
