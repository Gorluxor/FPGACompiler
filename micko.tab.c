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
#line 1 "micko.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"
  #include <string.h>
  #define YYDEBUG 0
  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  int typeOf = 0;
  int pointerType = 0;
  int global = 1;
  FILE *output;
  int arg_counter = 0;
  int par_counter = 0;
  extern unsigned no_type_array[];

#line 97 "micko.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "micko.tab.h".  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
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
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _BYTE_NUMBER = 264,
    _SHORT_NUMBER = 265,
    _LPAREN = 266,
    _RPAREN = 267,
    _LBRACKET = 268,
    _FOR = 269,
    _RBRACKET = 270,
    _ASSIGN = 271,
    _SEMICOLON = 272,
    _AROP = 273,
    _ASTERIKS = 274,
    _RELOP = 275,
    _INC = 276,
    _DEC = 277,
    _DDOT = 278,
    _QMARK = 279,
    _COMMA = 280,
    _DO = 281,
    _WHILE = 282,
    _AMP = 283,
    _ASM = 284,
    ONLY_IF = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "micko.y" /* yacc.c:355  */

  int i;
  char *s;

#line 173 "micko.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "micko.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    83,   104,   108,   109,   110,   115,   129,
     114,   146,   152,   161,   162,   163,   169,   179,   178,   188,
     190,   196,   221,   251,   257,   259,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   276,   286,   299,   304,
     303,   316,   321,   315,   333,   338,   332,   350,   354,   375,
     376,   379,   381,   413,   420,   422,   429,   436,   438,   447,
     455,   483,   503,   506,   514,   513,   535,   536,   540,   542,
     565,   568,   573,   593,   594,   604,   609,   603,   624,   635
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_BYTE_NUMBER", "_SHORT_NUMBER", "_LPAREN",
  "_RPAREN", "_LBRACKET", "_FOR", "_RBRACKET", "_ASSIGN", "_SEMICOLON",
  "_AROP", "_ASTERIKS", "_RELOP", "_INC", "_DEC", "_DDOT", "_QMARK",
  "_COMMA", "_DO", "_WHILE", "_AMP", "_ASM", "ONLY_IF", "$accept",
  "program", "$@1", "asm", "function_list", "function", "$@2", "$@3",
  "type", "parameter_list", "parameter", "body", "$@4", "variable_list",
  "variable_part", "variable", "statement_list", "statement", "increment",
  "decrement", "compound_statement", "do_loop", "@5", "while_loop", "@6",
  "$@7", "for_loop", "@8", "$@9", "assignment_statement",
  "left_part_assignment", "arop", "num_exp", "exp", "literal",
  "function_call", "$@10", "argument_list", "argument", "if_statement",
  "conditional_operator", "conditional_value", "if_part", "@11", "$@12",
  "rel_exp", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -116,    14,  -116,  -116,    22,    11,     7,  -116,    36,  -116,
    -116,  -116,  -116,  -116,    39,    42,    -2,  -116,    46,  -116,
      47,    22,  -116,    61,    -3,  -116,  -116,  -116,    22,    37,
    -116,  -116,  -116,    22,    73,  -116,  -116,    13,    70,    80,
      48,  -116,    79,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,    67,  -116,    89,  -116,  -116,
      23,  -116,  -116,    80,    93,    93,    -6,  -116,  -116,  -116,
    -116,    80,    86,    92,    45,    90,    69,    99,  -116,    69,
      80,  -116,  -116,   100,    43,   101,    80,  -116,  -116,  -116,
    -116,  -116,    93,    19,  -116,  -116,  -116,   102,  -116,    87,
      80,  -116,    59,  -116,    80,  -116,    80,    91,    74,  -116,
      80,   105,  -116,   107,    19,     4,  -116,    19,    98,   103,
      80,   110,    69,  -116,    80,  -116,  -116,    94,    90,   111,
      69,  -116,  -116,    98,   112,   108,  -116,  -116,  -116,  -116,
      69,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    19,     1,     0,    11,     3,     5,     0,    20,
      12,     4,     7,     6,     0,    21,     0,     8,     0,    23,
       0,    13,    22,     0,     0,    14,    16,     9,     0,     0,
      15,    19,    10,    17,     0,    24,    21,     0,     0,     0,
       0,    24,     0,    18,    39,    41,    35,    25,    30,    31,
      26,    32,    33,    34,    27,     0,    28,    70,    29,    75,
      55,    62,    63,     0,     0,     0,     0,    51,    54,    56,
      53,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,    58,    59,     0,     0,     0,     0,    60,    61,    79,
      49,    50,     0,    48,    36,    37,    38,     0,    44,     0,
       0,    71,     0,    76,    68,    57,     0,     0,     0,    52,
       0,     0,    42,     0,    69,     0,    66,    78,     0,     0,
       0,     0,     0,    65,    68,    74,    73,     0,     0,     0,
       0,    77,    67,     0,     0,     0,    43,    72,    45,    40,
       0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -116,  -116,  -116,   120,  -116,   121,  -116,  -116,     0,  -116,
     104,  -116,  -116,    97,  -116,  -116,    88,   -74,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,    55,
       3,  -116,   -39,   -57,  -115,  -116,  -116,  -116,     9,  -116,
    -116,     1,  -116,  -116,  -116,   -79,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    46,     6,     7,    18,    29,    23,    24,
      25,    32,    35,     4,    16,     9,    37,    47,    48,    49,
      50,    51,    76,    52,    77,   121,    53,   110,   140,    54,
      55,    92,   102,    67,    68,    69,    83,   115,   116,    56,
      70,   127,    57,    80,   113,    85,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   103,    99,   126,     8,   101,    14,    87,    88,    27,
       5,    89,    90,    91,     3,    19,   123,    38,   126,    39,
      40,   112,    28,    20,    84,     5,    41,    42,    43,   124,
      10,   119,    93,    34,   -64,   109,    11,    90,    91,    44,
      45,   129,    11,    15,    81,    82,    17,   108,   131,    38,
      31,    39,    40,    -8,    22,   105,   136,    21,    41,    42,
      96,    90,    91,   106,    71,   114,   141,   117,    26,    72,
      73,    44,    45,    38,    11,    39,    40,    90,    91,   106,
      36,    59,    41,    42,    78,   114,   105,    60,    61,    62,
      75,    63,    90,    91,    79,    44,    45,    97,    11,    64,
      60,    61,    62,    94,    86,   125,    61,    62,    65,    95,
     100,   104,    64,   107,   111,   118,   120,   133,    71,   122,
     128,    65,   130,   135,   138,   139,    12,    13,    33,    74,
      98,   134,    30,   132,   137
};

static const yytype_uint8 yycheck[] =
{
      39,    80,    76,   118,     4,    79,     6,    64,    65,    12,
       3,    17,    18,    19,     0,    17,    12,     4,   133,     6,
       7,   100,    25,    25,    63,     3,    13,    14,    15,    25,
      19,   110,    71,    33,    11,    92,    29,    18,    19,    26,
      27,   120,    29,     7,    21,    22,     7,    86,   122,     4,
      13,     6,     7,    11,     7,    12,   130,    11,    13,    14,
      15,    18,    19,    20,    16,   104,   140,   106,     7,    21,
      22,    26,    27,     4,    29,     6,     7,    18,    19,    20,
       7,    11,    13,    14,    17,   124,    12,     7,     8,     9,
      11,    11,    18,    19,     5,    26,    27,     7,    29,    19,
       7,     8,     9,    17,    11,     7,     8,     9,    28,    17,
      11,    11,    19,    12,    27,    24,    11,    23,    16,    12,
      17,    28,    12,    12,    12,    17,     6,     6,    31,    41,
      75,   128,    28,   124,   133
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,     0,    44,     3,    35,    36,    39,    46,
      19,    29,    34,    36,    39,     7,    45,     7,    37,    17,
      25,    11,     7,    39,    40,    41,     7,    12,    25,    38,
      41,    13,    42,    44,    39,    43,     7,    47,     4,     6,
       7,    13,    14,    15,    26,    27,    34,    48,    49,    50,
      51,    52,    54,    57,    60,    61,    70,    73,    77,    11,
       7,     8,     9,    11,    19,    28,    63,    64,    65,    66,
      71,    16,    21,    22,    47,    11,    53,    55,    17,     5,
      74,    21,    22,    67,    63,    76,    11,    64,    64,    17,
      18,    19,    62,    63,    17,    17,    15,     7,    60,    48,
      11,    48,    63,    76,    11,    12,    20,    12,    63,    64,
      58,    27,    76,    75,    63,    68,    69,    63,    24,    76,
      11,    56,    12,    12,    25,     7,    65,    72,    17,    76,
      12,    48,    69,    23,    61,    12,    48,    72,    12,    17,
      59,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    33,    32,    34,    35,    35,    35,    37,    38,
      36,    39,    39,    40,    40,    40,    41,    43,    42,    44,
      44,    45,    45,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    50,    51,    53,
      52,    55,    56,    54,    58,    59,    57,    60,    61,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    67,    66,    68,    68,    69,    69,
      70,    70,    71,    72,    72,    74,    75,    73,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     1,     2,     2,     0,     0,
       8,     1,     2,     0,     1,     3,     2,     0,     5,     0,
       2,     1,     3,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     0,
       8,     0,     0,     7,     0,     0,    10,     2,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     2,     2,
       2,     2,     1,     1,     0,     5,     1,     3,     0,     1,
       1,     3,     7,     1,     1,     0,     0,     7,     3,     3
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
#line 83 "micko.y" /* yacc.c:1646  */
    {
    // CREATED TO JUMP TO MAIN

	code("\tBegin_INST:");
    code("\n\t\tMOV.w sp, %d",LAST_WORKING_ADDRESS);
 	code("\n\t\tADD.w r13, %d", LAST_WORKING_ADDRESS - 4);
    code("\n\t\tCALL\t main"); 
	code("\n\t\tHALT");	
  }
#line 1378 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 93 "micko.y" /* yacc.c:1646  */
    {  
    int idx = lookup_symbol("main", FUN);
    if(idx == -1)
      err("undefined reference to 'main'");
    else 
      if(get_type(idx) != INT)
        warn("return type of 'main' is not int");
      }
#line 1391 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 104 "micko.y" /* yacc.c:1646  */
    {code("\t%s",(yyvsp[0].s));}
#line 1397 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "micko.y" /* yacc.c:1646  */
    {
	global = 0; // its inside the function 
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == -1)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, no_type_array, pointerType); // pointerType for fun
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));

        code("\n%s:", (yyvsp[0].s));

	    code("\n\t\t\tPUSH\tr13"); 
	    code("\n\t\t\tMOV.w \tr13,sp");      
      }
#line 1415 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "micko.y" /* yacc.c:1646  */
    {
        par_counter = 0;
        set_atr1(fun_idx, (yyvsp[-1].i));
        var_num = 0;
      }
#line 1425 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "micko.y" /* yacc.c:1646  */
    {
         
	    clear_symbols(fun_idx + 1);
	    gen_sslab((yyvsp[-6].s),"_exit");
	    code("\n\t\t\tMOV.w \tsp,r13");
	    code("\n\t\t\tPOP \tr13");
	    code("\n\t\t\tRET");			
      }
#line 1438 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 147 "micko.y" /* yacc.c:1646  */
    { 
          typeOf = (yyvsp[0].i);
	  pointerType = 0;
	  (yyval.i) = (yyvsp[0].i);
        }
#line 1448 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 153 "micko.y" /* yacc.c:1646  */
    {
	  typeOf = POINTER;
	  pointerType = (yyvsp[-1].i);
	  (yyval.i) = typeOf;
	}
#line 1458 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = 0;}
#line 1464 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "micko.y" /* yacc.c:1646  */
    { par_counter++; (yyval.i) = (yyvsp[0].i); }
#line 1470 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 163 "micko.y" /* yacc.c:1646  */
    { par_counter = (yyvsp[-2].i) + (yyvsp[0].i); (yyval.i) = (yyvsp[-2].i) + (yyvsp[0].i);}
#line 1476 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "micko.y" /* yacc.c:1646  */
    {       
        insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), 1, no_type_array, NO_ATR);
        set_atr2(fun_idx, par_counter, (yyvsp[-1].i));
        (yyval.i) = 1;
      }
#line 1486 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "micko.y" /* yacc.c:1646  */
    {
       
        if(var_num)
	  code("\n\t\t\tSUB.w\t\tsp, %d",4*var_num); // was 2 before push4
        gen_sslab(get_name(fun_idx), "_body");
      }
#line 1497 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 197 "micko.y" /* yacc.c:1646  */
    {
          if (global ==  0){
	    if(lookup_symbol((yyvsp[0].s), VAR|PAR) == -1){
	      if (typeOf == POINTER)
		insert_symbol((yyvsp[0].s), VAR, typeOf, ++var_num, no_type_array, pointerType);
	      else					
		insert_symbol((yyvsp[0].s), VAR, typeOf, ++var_num, no_type_array, NO_ATR);
	    }else 
		err("redefinition of '%s'", (yyvsp[0].s));		
          } else {
	    if (lookup_symbol((yyvsp[0].s), GLB) == -1){
		if (typeOf == POINTER)
		  insert_symbol((yyvsp[0].s), GLB, typeOf, NO_ATR, no_type_array, pointerType);
		else 
		  insert_symbol((yyvsp[0].s), GLB, typeOf, NO_ATR, no_type_array, NO_ATR);
	    }
		else
		  err("Redefinition of global varibale '%s'", (yyvsp[0].s));
        	// Generate Directives for global variables
	    code("\n%s", (yyvsp[0].s));
	    code("\n\t\t\t #res 4"); // TODO type check??	
       	  }
				 
	}
#line 1526 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 222 "micko.y" /* yacc.c:1646  */
    {
	  if (global == 0){
	    if(lookup_symbol((yyvsp[0].s), VAR|PAR) == -1){
		if (typeOf == POINTER)
		  insert_symbol((yyvsp[0].s), VAR, typeOf, ++var_num, no_type_array, pointerType);
		else					
		  insert_symbol((yyvsp[0].s), VAR, typeOf, ++var_num, no_type_array, NO_ATR);        	  
		}else 
		  err("redefinition of '%s'", (yyvsp[0].s));
		} else {
		  if (lookup_symbol((yyvsp[0].s), GLB) == -1){
		    if (typeOf == POINTER)
		      insert_symbol((yyvsp[0].s), GLB, typeOf, NO_ATR, no_type_array, pointerType);
		    else 
		      insert_symbol((yyvsp[0].s), GLB, typeOf, NO_ATR, no_type_array, NO_ATR);
		  }else
		      err("Redefinition of global varibale '%s'", (yyvsp[0].s));
		
	     // Generate Directives for global variables
	     code("\n%s", (yyvsp[0].s));
	     code("\n\t\t\t #res 4"); // TODO type check??		
          }
		
	}
#line 1555 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 259 "micko.y" /* yacc.c:1646  */
    { print_inc_dec(); }
#line 1561 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 277 "micko.y" /* yacc.c:1646  */
    {
	  int idx = lookup_symbol((yyvsp[-2].s), (VAR|PAR|GLB));
	  if (idx == -1){
	    err("invalid type for increment '%s'", (yyvsp[-2].s));
          }
	  gen_inc(1,idx);		
	}
#line 1573 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 287 "micko.y" /* yacc.c:1646  */
    {
	  int idx = lookup_symbol((yyvsp[-2].s), (VAR|PAR|GLB));
          if (idx == -1){
            err("invalid type for decrement '%s'", (yyvsp[-2].s));
          }
	  gen_dec(1,idx);	
	}
#line 1585 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 304 "micko.y" /* yacc.c:1646  */
    { 
	  (yyval.i) = ++lab_num;
	  gen_snlab("do", lab_num); 	 
	}
#line 1594 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 309 "micko.y" /* yacc.c:1646  */
    {
	  code("\n\t\t\t%s\t.do%d",get_jump_stmt((yyvsp[-2].i), FALSE),(yyvsp[-6].i));
	}
#line 1602 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 316 "micko.y" /* yacc.c:1646  */
    {
	  (yyval.i) = ++lab_num;
	  gen_snlab("while", lab_num);
	}
#line 1611 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 321 "micko.y" /* yacc.c:1646  */
    {
	  code("\n\t\t\t%s\t.exit%d",get_jump_stmt((yyvsp[0].i), TRUE),(yyvsp[-2].i));
	}
#line 1619 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 325 "micko.y" /* yacc.c:1646  */
    {
	  code("\n\t\t\tJ .while%d",(yyvsp[-5].i));
	  code("\n.exit%d:\t", (yyvsp[-5].i));
	}
#line 1628 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 333 "micko.y" /* yacc.c:1646  */
    {
	   (yyval.i) = ++lab_num;
	   gen_snlab("for",lab_num);		
	 }
#line 1637 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 338 "micko.y" /* yacc.c:1646  */
    {
           code("\n\t\t\t%s\t.exit%d", get_jump_stmt((yyvsp[-3].i), TRUE), (yyvsp[-4].i));
	 }
#line 1645 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 342 "micko.y" /* yacc.c:1646  */
    {
	   code("\n\t\t\tj\t.for%d",(yyvsp[-6].i));
	   code("\n.exit%d:",(yyvsp[-6].i));
	 }
#line 1654 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 355 "micko.y" /* yacc.c:1646  */
    {
          
	  int idx = lookup_symbol((yyvsp[-2].s), (VAR|PAR|GLB));
	  if(idx == -1)
		err("invalid lvalue '%s' in assignment", (yyvsp[-2].s));
	  else
          {
	    if (get_type(idx) != POINTER)
	      if (get_type((yyvsp[0].i)) == POINTER && get_type(idx) == INT)
	        warn("Allocating Address into a integer variable!");
	    else				
	      if (get_type(idx) != get_type((yyvsp[0].i)))
	        err("incompatible types in assignment, %d : %d", get_type(idx), get_type((yyvsp[0].i)));
	  }
    	  gen_mov((yyvsp[0].i),idx);
	  code("\t\t;ASSIGN");
	}
#line 1676 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 375 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i);}
#line 1682 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 376 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = MUL; }
#line 1688 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 382 "micko.y" /* yacc.c:1646  */
    {
    if (get_type((yyvsp[-2].i)) == POINTER || get_type((yyvsp[0].i)) == POINTER){
      if (get_type((yyvsp[-2].i)) == POINTER) 
	set_type((yyvsp[-2].i), INT);
      if (get_type((yyvsp[0].i)) == POINTER)
	set_type((yyvsp[0].i), INT);			
      //warn("aritmehic operations with address??");					
      } else if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
      	  err("invalid operands: arithmetic operation, %d : %d", get_type((yyvsp[-2].i)), get_type((yyvsp[0].i)));
        int t1 = get_type((yyvsp[-2].i));
	
	(yyval.i) = take_reg();
        set_type((yyval.i), t1);
	set_pok((yyval.i), get_pok((yyvsp[0].i))); // for pointer
	gen_mov_code((yyvsp[-2].i),(yyval.i));

	code("\t;EXPRESSION");
      //  code("\n\t\t\t%s\t\t", get_arop_stmt_adv($$,$2,t1));
	code("\n\t\t\t%s\t\t", get_arop_stmt((yyvsp[-1].i), t1)); //its for the register, which is always .w
		       
	
	print_symbol((yyval.i));
	code(",");
	print_symbol((yyvsp[0].i)); 


	if((yyvsp[0].i) >= 0 && (yyvsp[0].i) <= LAST_WORKING_REG)
	  free_reg((yyvsp[0].i));
	if((yyvsp[-2].i) >= 0 && (yyvsp[-2].i) <= LAST_WORKING_REG)
	  free_reg((yyvsp[-2].i));
      }
#line 1724 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 423 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = lookup_symbol((yyvsp[0].s), (VAR|PAR|GLB));
        if((yyval.i) == -1)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1734 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 430 "micko.y" /* yacc.c:1646  */
    {
       (yyval.i) = take_reg();
       gen_mov(FUN_REG, (yyval.i));
       code("\t\t;FUN_REG");
     }
#line 1744 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 437 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1750 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 439 "micko.y" /* yacc.c:1646  */
    { // INC
	(yyval.i) = lookup_symbol((yyvsp[-1].s), (VAR|PAR|GLB));
	if ((yyval.i) == -1)
	  err("'%s' undeclared", (yyvsp[-1].s));
        
         post_op((yyval.i), TRUE);
        
	}
#line 1763 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 448 "micko.y" /* yacc.c:1646  */
    { // DEC
	  (yyval.i) = lookup_symbol((yyvsp[-1].s), (VAR|PAR|GLB));
	  if ((yyval.i) == -1)
	    err("'%s' undeclared", (yyvsp[-1].s));

          post_op((yyval.i), FALSE);
	}
#line 1775 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 456 "micko.y" /* yacc.c:1646  */
    {
	  int idx = (yyvsp[0].i);
	  if (idx == -1)
	    err("Can't find Expression in symbol table");
	  if (get_pok((yyvsp[0].i)) == 0)
	    err("Trying to dereference something that isn't a pointer");
	  if (get_pok((yyvsp[0].i)) == 0)
	    err("Error while trying to find what the variable is pointing at");
	  //printf("Before move! %d",idx);
	  print_symtab();	
	
	  (yyval.i) = take_reg();
	
	  //printf("\n\t\tTHISTYPE:%d for var:%d\n\n reg:%d", get_type(get_pok(idx)),idx,$$);
	  gen_mov(idx,(yyval.i));
	  //printf("\n\t\tTHISTYPE:%d\n\n", get_type(get_pok(idx)));
	  set_type((yyval.i),get_type(get_pok(idx)));
	  if (get_type(get_pok(idx)) == BYTE){
	    code("\n\t\t\tLD.b\t r%d,[r%d]", (yyval.i),(yyval.i));
		
	  } else {
	    code("\n\t\t\tLD\t r%d,[r%d]", (yyval.i),(yyval.i)); // for pointer as well
		
	  }
	  print_symtab();	
	}
#line 1806 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 483 "micko.y" /* yacc.c:1646  */
    {
	  int idx = (yyvsp[0].i);
	  if (idx == -1){
	    err("Can't find Expression in symbol table");
	  }
	  if (lookup_symbol(get_name(idx), (VAR|PAR|GLB)) == -1){
	    err("Referencing invalid type");
	  }

	  (yyval.i) = take_reg();
	  set_pok((yyval.i), idx);
	  set_type((yyval.i),POINTER);
	  print_symtab();
	  //printf("\n\n\t%d:%d\n\n",$$,idx);
	  print_symbol_address(idx, (yyval.i));
		
	}
#line 1828 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 504 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1834 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 507 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), BYTE); }
#line 1840 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 514 "micko.y" /* yacc.c:1646  */
    {
       
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == -1)
          err("'%s' is not a function", (yyvsp[0].s));
        print_symtab();
      }
#line 1852 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 522 "micko.y" /* yacc.c:1646  */
    {
        arg_counter = 0;
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
	  code("\n\t\t\tADD.w \tsp, %d", (yyvsp[-1].i) * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
      }
#line 1867 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 535 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i);}
#line 1873 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 536 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-2].i) + (yyvsp[0].i);}
#line 1879 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 540 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = 0; arg_counter = 0;}
#line 1885 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 543 "micko.y" /* yacc.c:1646  */
    { 

      if (get_atr2(fcall_idx,arg_counter) != get_type((yyvsp[0].i)))
        err("incompatible type for argument");      
      //if(get_atr2(fcall_idx) != get_type($1))
      arg_counter++;
      free_if_reg((yyvsp[0].i));
      if (get_type((yyvsp[0].i)) != POINTER){
        code("\n\t\t\tPUSH\t");
        print_symbol((yyvsp[0].i));
      }else { // check
        int a = take_reg();
        gen_mov((yyvsp[0].i), a);
        code("\n\t\t\tPUSH\t");
        print_symbol(a);
        free_if_reg(a);
      }
      (yyval.i) = 1;
    }
#line 1909 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 566 "micko.y" /* yacc.c:1646  */
    { gen_snlab("exit", (yyvsp[0].i)); }
#line 1915 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 569 "micko.y" /* yacc.c:1646  */
    { gen_snlab("exit", (yyvsp[-2].i));}
#line 1921 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 574 "micko.y" /* yacc.c:1646  */
    {
	  ++lab_num;
	  gen_snlab("ter", lab_num);
	  if(get_type((yyvsp[-2].i))!=get_type((yyvsp[0].i)))
	    err("Conditional values not the same type");
	  int reg=take_reg();
	  code("\n\t\t\t%s\t.false%d",get_jump_stmt((yyvsp[-5].i), TRUE),lab_num);

	  gen_snlab("true", lab_num);
	  gen_mov((yyvsp[-2].i), reg);
	  code("\n\t\t\tJ \t.exit%d", lab_num);
 	  gen_snlab("false", lab_num);
	  gen_mov((yyvsp[0].i), reg);
	  gen_snlab("exit",lab_num);
	  (yyval.i) = reg;
	}
#line 1942 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 593 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i);}
#line 1948 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 595 "micko.y" /* yacc.c:1646  */
    {
	  (yyval.i) = lookup_symbol((yyvsp[0].s), (VAR|PAR|GLB));
	  if ((yyval.i) == -1)
	    err("'%s' undeclared", (yyvsp[0].s));
	}
#line 1958 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 604 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = ++lab_num;
        gen_snlab("if", lab_num);
      }
#line 1967 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 609 "micko.y" /* yacc.c:1646  */
    { 
	code("\n\t\t\t%s\t.false%d", 
        get_jump_stmt((yyvsp[0].i), TRUE),(yyvsp[-1].i));
        gen_snlab("true", (yyvsp[-1].i));
      }
#line 1977 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 615 "micko.y" /* yacc.c:1646  */
    {

	code("\n\t\t\tJ \t.exit%d", (yyvsp[-4].i));        
	gen_snlab("false", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 1988 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 625 "micko.y" /* yacc.c:1646  */
    {
	if (get_type((yyvsp[-2].i)) != POINTER && get_type((yyvsp[0].i)) != POINTER)
          if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
    	   err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 2000 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 636 "micko.y" /* yacc.c:1646  */
    {
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
        gen_mov((yyvsp[-1].i), FUN_REG);       
	code("\n\t\t\tJ \t.%s_exit", get_name(fun_idx));          
      }
#line 2011 "micko.tab.c" /* yacc.c:1646  */
    break;


#line 2015 "micko.tab.c" /* yacc.c:1646  */
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
#line 644 "micko.y" /* yacc.c:1906  */


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}


void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
	
  #if YYDEBUG == 1
  extern int yydebug;
  yydebug = 1;
  #endif

  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  print_symtab();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;
  else
    return error_count;
}

