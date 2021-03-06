/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 11 "mini_l.y"

  #define YY_NO_UNPUT
  #include <iostream>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string>
  #include <string.h>
  #include <fstream>
  #include <sstream>
  #include <map>
  #include <stack>
  #include <vector>

  using namespace std;

  //#define YYDEBUG 1
  //#define YYPRINT(file, type, value) yyprint (file, type value)
  //yydebug = 1;
  enum symbol_type {INT, INTARRAY, FUNC};

  struct Func {
    string name;
    Func(): name() {}
    Func(string n) 
    : name(n){}
  };

  struct Sym {
    int val;
    int size;
    string name;
    symbol_type type; 
    Sym():val(0),size(0),name(),type() {}
    Sym(int v, int s, string n, symbol_type t) 
    :val(v), size(s), name(n), type(t)
    {}
  };

  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *message);
  extern int currLine;
  extern int currPos;

  stack<string> ident_stack; // using
  stack<string> var_stack; // using
  stack<string> exp_stack; // using
  stack<string> param_stack; //using
  stack<string> label_stack; //using
  
  void add_symbol(Sym sym);
  void add_func(Func func);
  void check_symbol(string name);
  void check_func(string name);
  void print_declarations();
  string make_temp();
  string make_label();
  map<string, Sym> symbol_table;
  map<string, Func> func_table;

  stringstream milhouse;
  ostringstream out_code;

  int temp_cnt = 0;
  int label_cnt = 0;
  int param_cnt = 0;
  bool main_exists = 0;
  

/* Line 371 of yacc.c  */
#line 138 "y.tab.c"

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FUNCTION = 258,
     BEGIN_PARAMS = 259,
     END_PARAMS = 260,
     BEGIN_LOCALS = 261,
     END_LOCALS = 262,
     BEGIN_BODY = 263,
     END_BODY = 264,
     INTEGER = 265,
     ARRAY = 266,
     OF = 267,
     IF = 268,
     THEN = 269,
     ENDIF = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     BEGINLOOP = 274,
     ENDLOOP = 275,
     CONTINUE = 276,
     READ = 277,
     WRITE = 278,
     AND = 279,
     OR = 280,
     NOT = 281,
     TRUE = 282,
     FALSE = 283,
     RETURN = 284,
     NUMBER = 285,
     IDENT = 286,
     SUB = 287,
     ADD = 288,
     MULT = 289,
     DIV = 290,
     MOD = 291,
     UMINUS = 292,
     EQ = 293,
     NEQ = 294,
     LT = 295,
     GT = 296,
     LTE = 297,
     GTE = 298,
     SEMICOLON = 299,
     COLON = 300,
     COMMA = 301,
     L_PAREN = 302,
     R_PAREN = 303,
     L_SQUARE_BRACKET = 304,
     R_SQUARE_BRACKET = 305,
     ASSIGN = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 81 "mini_l.y"

  char* ident_str;
  int num_val;

  struct attributes {
    char name[255];
    char index[255];
    int type; //0 = int, 1 = int array, 2 = function
    int val;
    int size_attr;
  } attr;


/* Line 387 of yacc.c  */
#line 246 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 274 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    10,    11,    28,    29,
      33,    34,    38,    43,    53,    54,    58,    62,    63,    73,
      74,    83,    84,    94,    98,   102,   104,   107,   108,   109,
     115,   116,   120,   124,   126,   130,   132,   134,   137,   141,
     143,   145,   149,   151,   153,   155,   157,   159,   161,   165,
     169,   171,   175,   179,   183,   185,   188,   190,   193,   195,
     200,   204,   210,   214,   218,   219,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    -1,    55,    54,    -1,    -1,
      -1,     3,    31,    56,    44,     4,    58,    57,     5,     6,
      58,     7,     8,    62,    44,    59,     9,    -1,    -1,    60,
      44,    58,    -1,    -1,    62,    44,    59,    -1,    31,    61,
      45,    10,    -1,    31,    61,    45,    11,    49,    30,    50,
      12,    10,    -1,    -1,    46,    31,    61,    -1,    78,    51,
      74,    -1,    -1,    13,    69,    14,    63,    62,    44,    59,
      66,    15,    -1,    -1,    17,    69,    19,    64,    62,    44,
      59,    20,    -1,    -1,    18,    19,    65,    62,    44,    59,
      20,    17,    69,    -1,    22,    78,    68,    -1,    23,    78,
      68,    -1,    21,    -1,    29,    74,    -1,    -1,    -1,    16,
      67,    62,    44,    59,    -1,    -1,    46,    78,    68,    -1,
      69,    25,    70,    -1,    70,    -1,    70,    24,    71,    -1,
      71,    -1,    72,    -1,    26,    72,    -1,    74,    73,    74,
      -1,    27,    -1,    28,    -1,    47,    69,    48,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,
      -1,    74,    33,    75,    -1,    74,    32,    75,    -1,    75,
      -1,    75,    34,    76,    -1,    75,    35,    76,    -1,    75,
      36,    76,    -1,    76,    -1,    32,    78,    -1,    78,    -1,
      32,    30,    -1,    30,    -1,    32,    47,    74,    48,    -1,
      47,    74,    48,    -1,    31,    47,    74,    77,    48,    -1,
      31,    47,    48,    -1,    46,    74,    77,    -1,    -1,    31,
      -1,    31,    49,    74,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   131,   132,   135,   136,   135,   157,   158,
     161,   162,   165,   176,   189,   190,   196,   208,   208,   225,
     225,   261,   261,   279,   295,   311,   322,   332,   333,   333,
     342,   343,   348,   354,   359,   365,   370,   373,   380,   386,
     392,   398,   403,   404,   405,   406,   407,   408,   411,   417,
     423,   429,   435,   441,   447,   453,   482,   499,   514,   524,
     535,   538,   550,   559,   562,   565,   576
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "RETURN", "NUMBER", "IDENT", "SUB", "ADD", "MULT", "DIV", "MOD",
  "UMINUS", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON", "COLON",
  "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET",
  "ASSIGN", "$accept", "start", "program", "function", "$@1", "$@2",
  "declaration_block", "statement_block", "declaration", "comma_ident",
  "statement", "$@3", "$@4", "$@5", "else_block", "$@6", "var_block",
  "bool_expr", "relation_and_expr", "relation_expr", "rel_expr", "comp",
  "expression", "multiplicative_expr", "term", "exp_comma_block", "var", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    56,    57,    55,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    63,    62,    64,
      62,    65,    62,    62,    62,    62,    62,    66,    67,    66,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    16,     0,     3,
       0,     3,     4,     9,     0,     3,     3,     0,     9,     0,
       8,     0,     9,     3,     3,     1,     2,     0,     0,     5,
       0,     3,     3,     1,     3,     1,     1,     2,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     1,     2,     1,     4,
       3,     5,     3,     3,     0,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     5,     1,     4,     0,     0,
       8,    14,     6,     0,     0,     0,     0,     8,    14,     0,
       0,     9,    15,    12,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
      65,     0,     0,    13,     0,    39,    40,    58,    65,     0,
       0,     0,    33,    35,    36,     0,    50,    54,    56,     0,
      21,    30,    30,     0,    26,     0,    10,     0,    37,     0,
      57,     0,    55,     0,     0,    17,     0,     0,     0,     0,
      42,    43,    44,    45,    46,    47,     0,     0,     0,     0,
      19,     0,     0,    23,    24,     0,     0,     0,     0,    16,
      62,    64,     0,    41,    60,     0,    32,    34,    49,    48,
      38,    51,    52,    53,     0,     0,    30,    66,     7,    10,
       0,     0,    59,     0,     0,    10,    31,    11,    64,    61,
      10,    10,     0,    63,    27,     0,     0,    28,     0,    20,
       0,     0,    18,    22,     0,    10,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    16,    12,    97,    13,    15,
      98,   105,   114,    91,   138,   141,    93,    51,    52,    53,
      54,    86,    55,    56,    57,   121,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
       5,    -2,    32,  -116,     5,  -116,  -116,  -116,    -7,    35,
      12,    10,  -116,     7,    44,    37,    75,    12,    10,    67,
      78,  -116,  -116,  -116,    43,    12,    79,   101,    80,   109,
     117,    50,   122,    -6,    -6,   123,  -116,   112,   112,    59,
      96,   100,    97,  -116,    18,  -116,  -116,  -116,   -38,    56,
      -6,    41,   125,  -116,  -116,    95,    84,  -116,  -116,    39,
    -116,   104,   104,    59,    69,    59,    50,    59,  -116,    22,
    -116,    59,  -116,   -20,    83,  -116,    -6,    -6,    59,    59,
    -116,  -116,  -116,  -116,  -116,  -116,    59,    59,    59,    59,
    -116,    50,   112,  -116,  -116,    63,   -19,   137,   103,    69,
    -116,     1,    65,  -116,  -116,    50,   125,  -116,    84,    84,
      69,  -116,  -116,  -116,    50,   107,   104,  -116,  -116,    50,
      59,   105,  -116,   108,   110,    50,  -116,  -116,     1,  -116,
      50,    50,   135,  -116,   140,   138,   142,  -116,   145,  -116,
      -6,    50,  -116,   132,   118,    50,  -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   157,  -116,  -116,  -116,     2,  -115,  -116,   146,
     -29,  -116,  -116,  -116,  -116,  -116,   -59,   -33,    87,    88,
     124,  -116,   -27,    26,    52,    38,   -31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    59,    41,    94,   127,    76,    61,    62,     1,    69,
     132,    65,    64,    78,    79,   134,   135,    73,    72,    21,
      44,    45,    46,    74,    47,    48,    49,    27,   103,     5,
     146,   117,     6,    78,    79,    42,    95,     9,    96,    10,
      99,    50,   101,    11,   102,    45,    46,   120,    47,    48,
      49,    17,    47,    48,    49,    75,    14,   126,    90,   110,
      42,   116,   115,    33,    76,    50,    76,    34,    35,    63,
     100,    36,    37,    38,    42,    18,   123,    23,    24,    39,
      20,    40,    19,    42,    25,   124,    70,    40,    42,    47,
      48,    49,    26,   128,    42,    78,    79,    78,    79,    42,
      42,    78,    79,    71,   108,   109,    63,   143,    29,    28,
      42,   104,   144,   122,    42,    78,    79,    31,    87,    88,
      89,    80,    81,    82,    83,    84,    85,    78,    79,    32,
      30,   104,    43,    80,    81,    82,    83,    84,    85,   111,
     112,   113,    60,    40,    66,    65,   118,   119,    67,    77,
      92,   125,   130,   129,   131,   136,   137,    76,   139,   140,
     142,     7,   145,   106,    22,   107,   133,     0,    68
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      31,    34,    31,    62,   119,    25,    37,    38,     3,    47,
     125,    49,    39,    32,    33,   130,   131,    50,    49,    17,
      26,    27,    28,    50,    30,    31,    32,    25,    48,    31,
     145,    50,     0,    32,    33,    66,    63,    44,    65,     4,
      67,    47,    69,    31,    71,    27,    28,    46,    30,    31,
      32,    44,    30,    31,    32,    14,    46,   116,    19,    86,
      91,    92,    91,    13,    25,    47,    25,    17,    18,    47,
      48,    21,    22,    23,   105,    31,   105,    10,    11,    29,
       5,    31,    45,   114,     6,   114,    30,    31,   119,    30,
      31,    32,    49,   120,   125,    32,    33,    32,    33,   130,
     131,    32,    33,    47,    78,    79,    47,   140,     7,    30,
     141,    48,   141,    48,   145,    32,    33,     8,    34,    35,
      36,    38,    39,    40,    41,    42,    43,    32,    33,    12,
      50,    48,    10,    38,    39,    40,    41,    42,    43,    87,
      88,    89,    19,    31,    44,    49,     9,    44,    51,    24,
      46,    44,    44,    48,    44,    20,    16,    25,    20,    17,
      15,     4,    44,    76,    18,    77,   128,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    54,    55,    31,     0,    54,    56,    44,
       4,    31,    58,    60,    46,    61,    57,    44,    31,    45,
       5,    58,    61,    10,    11,     6,    49,    58,    30,     7,
      50,     8,    12,    13,    17,    18,    21,    22,    23,    29,
      31,    62,    78,    10,    26,    27,    28,    30,    31,    32,
      47,    69,    70,    71,    72,    74,    75,    76,    78,    69,
      19,    78,    78,    47,    74,    49,    44,    51,    72,    47,
      30,    47,    78,    69,    74,    14,    25,    24,    32,    33,
      38,    39,    40,    41,    42,    43,    73,    34,    35,    36,
      19,    65,    46,    68,    68,    74,    74,    59,    62,    74,
      48,    74,    74,    48,    48,    63,    70,    71,    75,    75,
      74,    76,    76,    76,    64,    62,    78,    50,     9,    44,
      46,    77,    48,    62,    62,    44,    68,    59,    74,    48,
      44,    44,    59,    77,    59,    59,    20,    16,    66,    20,
      17,    67,    15,    69,    62,    44,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 128 "mini_l.y"
    {if(!main_exists){yyerror("error: main not declared");}}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 135 "mini_l.y"
    {milhouse << "func " << string((yyvsp[(2) - (2)].ident_str)) << endl;}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 136 "mini_l.y"
    { 
            while (!param_stack.empty()){
              milhouse << "= " << param_stack.top() << ", " << "$" << param_cnt++ << endl;
              param_stack.pop();
            }
          }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 142 "mini_l.y"
    {

            out_code << "endfunc\n";
            symbol_table.clear();
            if (strcmp((yyvsp[(2) - (16)].ident_str), "main")==0) {
              main_exists = 1;      
            }
            Func f((yyvsp[(2) - (16)].ident_str));
            add_func(f);
            while (!param_stack.empty()) {
              param_stack.pop();
            }
          }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 165 "mini_l.y"
    {
               ident_stack.push((yyvsp[(1) - (4)].ident_str));
               param_stack.push((yyvsp[(1) - (4)].ident_str));
               while(!ident_stack.empty()) {
                 string temp = ident_stack.top();
                 Sym sym(0,0,temp,INT); 
                 add_symbol(sym);
                 milhouse << ". " << temp << endl;
                 ident_stack.pop(); 
               }
             }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 176 "mini_l.y"
    {
               ident_stack.push((yyvsp[(1) - (9)].ident_str));
               param_stack.push((yyvsp[(1) - (9)].ident_str));
               while(!ident_stack.empty()) {
                 string temp = ident_stack.top();
                 Sym sym(0,(yyvsp[(6) - (9)].num_val),temp,INTARRAY);
                 add_symbol(sym);
                 milhouse << ".[] " << temp << ", " << (yyvsp[(6) - (9)].num_val) << endl;
                 ident_stack.pop(); 
               }
             }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 190 "mini_l.y"
    {
               ident_stack.push((yyvsp[(2) - (3)].ident_str));
               param_stack.push((yyvsp[(2) - (3)].ident_str));
             }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 196 "mini_l.y"
    {
             if ((yyvsp[(1) - (3)].attr).type == 0) { //Check if var is an int
                 milhouse << "= " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
              
             }
             else { //Check if var is an int array
                 milhouse << "[]= " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).index) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
             } 
             out_code << milhouse.rdbuf();
             milhouse.clear();
             milhouse.str(" ");
          }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 208 "mini_l.y"
    {
             string start = make_label();
             string endif = make_label();
             label_stack.push(endif); 
             milhouse << "?:= " << start << ", " << const_cast<char*>((yyvsp[(2) - (3)].attr).name) << endl;
             milhouse << ":= " << endif << endl;
             milhouse << ": " << start << endl;
           }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 216 "mini_l.y"
    {
             milhouse << ": " << label_stack.top() << endl;
             label_stack.pop();
             
             out_code << milhouse.rdbuf();
             milhouse.clear();
             milhouse.str(" ");

           }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 225 "mini_l.y"
    {

              string conditional = make_label();
              string endlabel = make_label();
              string start = make_label();
              out_code << ": " << start << endl;

              out_code << milhouse.rdbuf();
              milhouse.clear();
              milhouse.str(" ");
            
              milhouse << "?:= " << conditional << ", " << const_cast<char*>((yyvsp[(2) - (3)].attr).name) << endl;
              milhouse << ":= " << endlabel << endl;
              milhouse << ": " << conditional << endl;

              label_stack.push(start);
              label_stack.push(endlabel);

            }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 243 "mini_l.y"
    {
                out_code << milhouse.rdbuf();
                milhouse.clear();
                milhouse.str(" ");

                string endlabel = label_stack.top();
                label_stack.pop();
                string start = label_stack.top();
                label_stack.pop();

                milhouse << ":= " << start << endl;
                milhouse << ": " << endlabel << endl;
 

                out_code << milhouse.rdbuf();
                milhouse.clear();
                milhouse.str(" ");
           }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 261 "mini_l.y"
    {
             string start = make_label();
             label_stack.push(start);
             out_code << ": " << start << endl;
             out_code << milhouse.rdbuf();
             milhouse.clear();
             milhouse.str(" ");

            }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 270 "mini_l.y"
    {
             string start = label_stack.top();
             milhouse << "?:= " << start << ", " << const_cast<char*>((yyvsp[(9) - (9)].attr).name) << endl;
             label_stack.pop(); 
             
             out_code << milhouse.rdbuf();
             milhouse.clear();
             milhouse.str(" ");
           }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 279 "mini_l.y"
    {
             var_stack.push((yyvsp[(2) - (3)].attr).name);
             while (!var_stack.empty()) {
                if ((yyvsp[(2) - (3)].attr).type == 0) {
                    milhouse << ".< " << var_stack.top() << endl;
                    var_stack.pop();
                }
                else {
                    milhouse << ".[]< " << var_stack.top() << ", "  <<  const_cast<char*>((yyvsp[(2) - (3)].attr).index) << endl;
                    var_stack.pop();
                }
             }
             out_code << milhouse.rdbuf();
             milhouse.clear();
             milhouse.str(" ");
          }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 295 "mini_l.y"
    {
            var_stack.push((yyvsp[(2) - (3)].attr).name);
            while (!var_stack.empty()) {
                if ((yyvsp[(2) - (3)].attr).type == 0) {
                    milhouse << ".> " << var_stack.top() << endl;
                    var_stack.pop();
                }
                else {
                    milhouse << ".[]> " << var_stack.top() << ", "  <<  const_cast<char*>((yyvsp[(2) - (3)].attr).index) << endl;
                    var_stack.pop();
                }
            }
            out_code << milhouse.rdbuf();
            milhouse.clear();
            milhouse.str(" ");
         }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 311 "mini_l.y"
    {
             if (!label_stack.empty()) {
               milhouse << ":= " << label_stack.top() << endl;
               out_code << milhouse.rdbuf();
               milhouse.clear();
               milhouse.str(" ");
             }
             else {
               yyerror("error: cannot use continue outside a loop");
             }
           }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 322 "mini_l.y"
    {
             (yyval.attr).val = (yyvsp[(2) - (2)].attr).val;
             strcpy((yyval.attr).name,(yyvsp[(2) - (2)].attr).name);
             milhouse << "ret " << const_cast<char*>((yyvsp[(2) - (2)].attr).name) << endl;
             out_code << milhouse.rdbuf();
             milhouse.clear();
             milhouse.str(" ");
         }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 333 "mini_l.y"
    {
              string label = make_label(); 
              milhouse << ":= " << label << endl;
              milhouse << ": " << label_stack.top() << endl;
              label_stack.pop();
              label_stack.push(label);
          }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 343 "mini_l.y"
    {
             var_stack.push((yyvsp[(2) - (3)].attr).name);
           }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 348 "mini_l.y"
    {
             string temp = make_temp();
             strcpy((yyval.attr).name, temp.c_str());
             milhouse << ". " << temp << endl;
             milhouse << "|| " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
           }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 354 "mini_l.y"
    {
             strcpy((yyval.attr).name, (yyvsp[(1) - (1)].attr).name);
           }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 359 "mini_l.y"
    {
                    string temp = make_temp();
                    strcpy((yyval.attr).name, temp.c_str());
                    milhouse << ". " << temp << endl;
                    milhouse << "&& " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " <<  const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
                   }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 365 "mini_l.y"
    {
                       strcpy((yyval.attr).name, (yyvsp[(1) - (1)].attr).name);
                    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 370 "mini_l.y"
    {
                    strcpy((yyval.attr).name, (yyvsp[(1) - (1)].attr).name);
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 373 "mini_l.y"
    {
                    string temp = make_temp();
                    strcpy((yyval.attr).name, temp.c_str());
                    milhouse << "! " << temp << const_cast<char*>((yyvsp[(2) - (2)].attr).name) << endl;
                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 380 "mini_l.y"
    {
          string temp = make_temp();
          strcpy((yyval.attr).name, temp.c_str());
          milhouse << ". " << temp << endl;
          milhouse << (yyvsp[(2) - (3)].ident_str) << " " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 386 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            milhouse << ". " << temp << endl;
            milhouse << "= " << temp << ", " << "1" << endl;
          }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 392 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            milhouse << ". " << temp << endl;
            milhouse << "= " << temp << ", " << "0" << endl;
          }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 398 "mini_l.y"
    {
                strcpy((yyval.attr).name, (yyvsp[(2) - (3)].attr).name);
            }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 403 "mini_l.y"
    { (yyval.ident_str) = const_cast<char*>("=="); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 404 "mini_l.y"
    { (yyval.ident_str) = const_cast<char*>("!="); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 405 "mini_l.y"
    { (yyval.ident_str) = const_cast<char*>("<"); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 406 "mini_l.y"
    { (yyval.ident_str) = const_cast<char*>(">"); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 407 "mini_l.y"
    { (yyval.ident_str) = const_cast<char*>("<="); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 408 "mini_l.y"
    { (yyval.ident_str) = const_cast<char*>(">="); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 411 "mini_l.y"
    {
              string temp = make_temp();
              milhouse << ". " << temp << endl;
              milhouse << "+ " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
              strcpy((yyval.attr).name, temp.c_str());
            }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 417 "mini_l.y"
    {
              string temp = make_temp();
              milhouse << ". " << temp << endl;
              milhouse << "- " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
              strcpy((yyval.attr).name, temp.c_str());
            }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 423 "mini_l.y"
    {
              strcpy((yyval.attr).name,(yyvsp[(1) - (1)].attr).name);
              (yyval.attr).type = (yyvsp[(1) - (1)].attr).type;
             }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 429 "mini_l.y"
    {
                       string temp = make_temp();
                       milhouse << ". " << temp << endl;
                       milhouse << "* " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
                       strcpy((yyval.attr).name, temp.c_str());
                     }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 435 "mini_l.y"
    {
                       string temp = make_temp();
                       milhouse << ". " << temp << endl;
                       milhouse << "/ " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
                       strcpy((yyval.attr).name, temp.c_str());
                    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 441 "mini_l.y"
    {
                       string temp = make_temp();
                       milhouse << ". " << temp << endl;
                       milhouse << "% " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
                       strcpy((yyval.attr).name, temp.c_str());
                    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 447 "mini_l.y"
    {
                       strcpy((yyval.attr).name,(yyvsp[(1) - (1)].attr).name);
                       (yyval.attr).type = (yyvsp[(1) - (1)].attr).type;
                     }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 453 "mini_l.y"
    {
        (yyval.attr).val = (yyvsp[(2) - (2)].attr).val*-1;
        (yyval.attr).type = (yyvsp[(2) - (2)].attr).type;
        if ((yyvsp[(2) - (2)].attr).type != 1) {// if int
          string zero = make_temp();
          string num = make_temp();
          milhouse << ". " << zero << endl;
          milhouse << "= " << zero << ", " << "0" << endl;
          milhouse << ". " << num << endl;
          milhouse << "= " << num << ", " << const_cast<char*>((yyvsp[(2) - (2)].attr).name) << endl;
          strcpy((yyval.attr).name,make_temp().c_str());
          milhouse << ". " << const_cast<char*>((yyval.attr).name) << endl;
          milhouse << "- " << const_cast<char*>((yyval.attr).name) <<  ", " << zero << ", " << num << endl;
         }        
        else if ((yyvsp[(2) - (2)].attr).type == 1) { // if array
          //b = make_temp();
          string zero = make_temp();
          string num = make_temp();
          milhouse << ". " << zero << endl;
          milhouse << "= " << zero << ", " << "0" << endl;
          milhouse << ". " << num << endl;
          milhouse << ". " << num << endl;
          milhouse << "=[] " << num << ", " << const_cast<char*>((yyvsp[(2) - (2)].attr).name) <<  ", " << const_cast<char*>((yyvsp[(2) - (2)].attr).index) << endl;
          strcpy((yyval.attr).name,make_temp().c_str());
          milhouse << ". " <<  const_cast<char*>((yyval.attr).name)<< endl;
          milhouse << "- " << const_cast<char*>((yyval.attr).name) << ", " << zero <<  ", " << num << endl;
        }

      }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 482 "mini_l.y"
    {
        (yyval.attr).val = (yyvsp[(1) - (1)].attr).val;
        (yyval.attr).type = (yyvsp[(1) - (1)].attr).type;
        if ((yyvsp[(1) - (1)].attr).type != 1) {
          strcpy((yyval.attr).name,make_temp().c_str());
          strcpy((yyval.attr).index,(yyval.attr).name);
          milhouse << ". " << const_cast<char*>((yyval.attr).name) << endl;
          milhouse << "= " << const_cast<char*>((yyval.attr).name) <<  ", " << const_cast<char*>((yyvsp[(1) - (1)].attr).name) << endl;
        }
        else if ((yyvsp[(1) - (1)].attr).type == 1) { // if array
          //b = make_temp();
          strcpy((yyval.attr).name,make_temp().c_str());
          milhouse << ". " <<  const_cast<char*>((yyval.attr).name)<< endl;
          milhouse << "=[] " << const_cast<char*>((yyval.attr).name) << ", " << const_cast<char*>((yyvsp[(1) - (1)].attr).name) << ", " << const_cast<char*>((yyvsp[(1) - (1)].attr).index) << endl;
        }

      }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 499 "mini_l.y"
    {
        (yyval.attr).val = (yyvsp[(2) - (2)].num_val)*-1;
        // $$.type = 3;
        (yyval.attr).type = 0;
        string zero = make_temp();
        string num = make_temp();
        milhouse << ". " << zero << endl;
        milhouse << "= " << zero << ", " << "0" << endl;
        milhouse << ". " << num << endl;
        milhouse << "= " << num << ", " << (yyvsp[(2) - (2)].num_val) << endl;

        strcpy((yyval.attr).name, make_temp().c_str());
        milhouse << ". " << const_cast<char*>((yyval.attr).name) << endl;
        milhouse << "- " << const_cast<char*>((yyval.attr).name) <<  ", " << zero << ", "<< num << endl;
     }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 514 "mini_l.y"
    {
        (yyval.attr).val = (yyvsp[(1) - (1)].num_val);
        // $$.type = 3;
        (yyval.attr).type = 0;

        strcpy((yyval.attr).name, make_temp().c_str());
        strcpy((yyval.attr).index,(yyval.attr).name);
        milhouse << ". " << const_cast<char*>((yyval.attr).name) << endl;
        milhouse << "= " << const_cast<char*>((yyval.attr).name) <<  ", " << (yyval.attr).val << endl;
      }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 524 "mini_l.y"
    {

       string zero = make_temp();

       milhouse << ". " << zero << endl;
       milhouse << "= " << zero << ", " << "0"<< endl;
        
       strcpy((yyval.attr).name, make_temp().c_str());
       milhouse << ". " << const_cast<char*>((yyval.attr).name) << endl;
       milhouse << "- " << const_cast<char*>((yyval.attr).name) <<  ", " << zero << ", "<< const_cast<char*>((yyvsp[(3) - (4)].attr).name) << endl;
      }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 535 "mini_l.y"
    {
        strcpy((yyval.attr).name, (yyvsp[(2) - (3)].attr).name);
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 538 "mini_l.y"
    {
        check_func(const_cast<char*>((yyvsp[(1) - (5)].ident_str)));
        exp_stack.push((yyvsp[(3) - (5)].attr).name); 
        while (!exp_stack.empty()){
          milhouse << "param " << exp_stack.top() << endl;
          exp_stack.pop();
        }
        string temp = make_temp();
        milhouse << ". " << temp << endl;
        milhouse << "call " << const_cast<char*>((yyvsp[(1) - (5)].ident_str)) << ", " << temp << endl;
        strcpy((yyval.attr).name,temp.c_str());
      }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 550 "mini_l.y"
    {
        check_func(const_cast<char*>((yyvsp[(1) - (3)].ident_str)));
        string temp = make_temp();
        milhouse << ". " << temp << endl;
        milhouse << "call " << const_cast<char*>((yyvsp[(1) - (3)].ident_str)) << ", " << temp << endl;
        strcpy((yyval.attr).name,temp.c_str());
      }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 559 "mini_l.y"
    {
                   exp_stack.push((yyvsp[(2) - (3)].attr).name); 
                 }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 565 "mini_l.y"
    {
       check_symbol((yyvsp[(1) - (1)].ident_str));
       if(symbol_table[(yyvsp[(1) - (1)].ident_str)].type == INTARRAY) {
         yyerror("Symbol is of type int array");
       }
       else {
         strcpy((yyval.attr).name,(yyvsp[(1) - (1)].ident_str));
         (yyval.attr).type = 0;
         //$$.val = symbol_table[$1].val;
       }
     }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 576 "mini_l.y"
    {
       check_symbol((yyvsp[(1) - (4)].ident_str));
       if(symbol_table[(yyvsp[(1) - (4)].ident_str)].type == INT) {
         yyerror("Symbol is of type int");
       }
       else {
         if ((yyvsp[(3) - (4)].attr).type == 1) {
           string temp = make_temp();
           (yyval.attr).type = 1;
           //strcpy($$.name, temp.c_str());
           strcpy((yyval.attr).index, temp.c_str());
           strcpy((yyval.attr).name, (yyvsp[(1) - (4)].ident_str));

           milhouse << ". " << temp << endl; 
           milhouse << "=[] " << temp << ", " << const_cast<char*>((yyvsp[(3) - (4)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (4)].attr).index) << endl;
         }
         else {
           strcpy((yyval.attr).name, (yyvsp[(1) - (4)].ident_str));
           (yyval.attr).type = 1;
           //$$.val = symbol_table[$1].val;
           strcpy((yyval.attr).index, (yyvsp[(3) - (4)].attr).name);
         }
       }
     }
    break;


/* Line 1792 of yacc.c  */
#line 2288 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 602 "mini_l.y"


int main (int argc, char **argv) {
  if (argc > 1) {
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
      printf("syntax: %s filename\n", argv[0]);
    }
  }
  yyparse();
  ofstream file;
  file.open("mil_code.mil");
  file << out_code.str();
  file.close();
  return 0;
}

void yyerror(const char *message) {
  printf("Syntax error on line %d: \"%s\" \n", currLine, message);
}

void yyerror(string message) {
  cout << "Syntax error on line " << currLine << ": " << message << endl;
}

void add_symbol(Sym s) {
  if (symbol_table.find(s.name) == symbol_table.end()) {
    symbol_table[s.name] = s;
  }
  else {
    string error = "Symbol already declared: " + s.name;
    yyerror(error);
  }
}

void add_func(Func f) {
  if (func_table.find(f.name) == func_table.end()) {
    func_table[f.name] = f;
  }
  else {
    string error = "error: function already declared: " + f.name;
    yyerror(error);
  }
}

void check_symbol(string name) {
  if(symbol_table.find(name) == symbol_table.end()) {
    string error = "Symbol not declared: " + name;
    yyerror(error);
  }
}

void check_func(string name) {
  if(func_table.find(name) == func_table.end()) {
    string error = "Function not declared: " + name;
    yyerror(error);
  }
}

void print_declarations() {
  for(map<string,Sym>::iterator it = symbol_table.begin(); it!=symbol_table.end();++it){
    if (it->second.type == INT) {
      milhouse << ". " << it->second.name << endl;
    }
    else {
      milhouse << ".[] " << it->second.name << ", " << it->second.size << endl;
    }
  }
}

string make_temp() {
  stringstream ss;
  ss << temp_cnt++;
  string temp = "__temp__" + ss.str();
  return temp;
}

string make_label() {
  stringstream ss;
  ss << label_cnt++;
  string temp = "__label__" + ss.str();
  return temp;
}
