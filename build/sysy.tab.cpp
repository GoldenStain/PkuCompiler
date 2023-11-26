/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "/share/sysy-make-template/src/sysy.y"


#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BaseAST.hpp"


// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;


#line 87 "/share/sysy-make-template/build/sysy.tab.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SHARE_SYSY_MAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED
# define YY_YY_SHARE_SYSY_MAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "/share/sysy-make-template/src/sysy.y"

  #include <memory>
  #include <string>
  #include "BaseAST.hpp"

#line 136 "/share/sysy-make-template/build/sysy.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RETURN = 258,
    CONST = 259,
    IDENT = 260,
    BTYPE = 261,
    INT_CONST = 262
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "/share/sysy-make-template/src/sysy.y"

  std::string *str_val;
  int int_val;
  BaseAST *ast_val;
  std::vector<std::unique_ptr<BaseAST>> *vec_val;

#line 162 "/share/sysy-make-template/build/sysy.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::unique_ptr<BaseAST> &ast);

#endif /* !YY_YY_SHARE_SYSY_MAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

#define YYUNDEFTOK  2
#define YYMAXUTOK   262


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,     2,     2,    19,    21,     2,
       8,     9,    17,    14,    24,    15,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    12,
      23,    13,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    10,    20,    11,     2,     2,     2,     2,
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
       5,     6,     7
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    79,    90,    98,   106,   110,   118,   122,
     130,   134,   139,   143,   146,   149,   157,   162,   168,   174,
     183,   188,   192,   201,   209,   213,   219,   225,   235,   239,
     245,   256,   260,   269,   273,   282,   286,   292,   303,   307,
     313,   319,   325,   335,   343,   347,   354,   364,   368,   376,
     380,   389,   397,   407,   411,   419,   428,   436
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RETURN", "CONST", "IDENT", "BTYPE",
  "INT_CONST", "'('", "')'", "'{'", "'}'", "';'", "'='", "'+'", "'-'",
  "'!'", "'*'", "'/'", "'%'", "'|'", "'&'", "'>'", "'<'", "','", "$accept",
  "CompUnit", "FuncDef", "FuncType", "Block", "BlockItemList", "BlockItem",
  "Stmt", "UnaryExp", "PrimaryExp", "Exp", "MulExp", "AddExp", "LorExp",
  "LandExp", "EqExp", "RelExp", "Number", "Decl", "VarDecl", "VarDefList",
  "VarDef", "InitVal", "ConstDecl", "ConstDefList", "ConstDef",
  "ConstInitVal", "ConstExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    40,    41,
     123,   125,    59,    61,    43,    45,    33,    42,    47,    37,
     124,    38,    62,    60,    44
};
# endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -57,    14,   -57,    20,   -57,    15,    26,    35,    36,
     -57,    48,    23,    34,    44,   -57,    79,   -57,    79,    79,
      79,   -57,     5,   -57,   -57,   -57,   -57,    42,    55,    18,
      37,    38,    11,    43,   -57,   -57,   -57,   -57,   -57,   -57,
      49,    62,    79,    56,     6,   -57,    72,   -57,   -57,   -57,
     -57,   -57,   -57,    79,    79,    79,    79,    79,    65,    71,
      85,    88,    63,    75,   -57,    89,    10,   -57,    91,    79,
     -57,    44,   -57,   -57,   -57,   -57,    55,    55,    79,    79,
      79,    79,    79,    18,    79,    18,    79,   -57,    62,   -57,
     -57,   -57,   -57,    38,    11,    43,    43,    18,    18,   -57,
     -57,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     2,     0,     1,     0,     0,     0,     0,
       3,     0,     0,    22,     0,    43,     0,    13,     0,     0,
       0,    12,     0,     6,     9,    24,    16,     0,    28,    38,
      23,    31,    33,    35,    21,     8,    45,    44,    22,    14,
       0,     0,     0,    49,     0,    47,     0,    17,    18,    19,
       5,     7,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,    53,     0,     0,
      46,     0,    20,    25,    26,    27,    29,    30,     0,     0,
       0,     0,     0,    39,     0,    40,     0,    52,     0,    11,
      51,    50,    48,    32,    34,    36,    37,    41,    42,    57,
      55,    56,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -57,    96,   -57,    83,   -57,   -17,   -57,
     -11,    40,   -56,   -57,    28,    29,    19,   -57,   -57,   -57,
     -57,    39,   -57,   -57,   -57,    21,   -57,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      44,    45,    91,    37,    66,    67,   100,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      40,    47,    48,    49,     1,    46,    83,    85,    11,    12,
      13,    14,    15,    16,     5,     9,    50,    17,    70,    18,
      19,    20,    87,     7,    60,     6,    97,    61,    98,    41,
      71,    68,    56,    57,    88,     8,    73,    74,    75,    11,
      12,    13,    14,    15,    16,     9,     9,    42,    17,    43,
      18,    19,    20,    38,    52,    15,    16,    58,    90,    59,
      39,    64,    18,    19,    20,    62,    63,    65,    38,    69,
      15,    16,    53,    54,    55,    99,    82,    18,    19,    20,
      38,    72,    15,    16,    38,    78,    15,    16,    84,    18,
      19,    20,    79,    18,    19,    20,    76,    77,    80,    95,
      96,    81,    86,    89,    10,    51,    93,     0,    94,   102,
      92
};

static const yytype_int8 yycheck[] =
{
      11,    18,    19,    20,     6,    16,    62,    63,     3,     4,
       5,     6,     7,     8,     0,    10,    11,    12,    12,    14,
      15,    16,    12,     8,    13,     5,    82,    16,    84,     6,
      24,    42,    14,    15,    24,     9,    53,    54,    55,     3,
       4,     5,     6,     7,     8,    10,    10,    13,    12,     5,
      14,    15,    16,     5,    12,     7,     8,    20,    69,    21,
      12,    12,    14,    15,    16,    22,    23,     5,     5,    13,
       7,     8,    17,    18,    19,    86,    13,    14,    15,    16,
       5,     9,     7,     8,     5,    20,     7,     8,    13,    14,
      15,    16,    21,    14,    15,    16,    56,    57,    13,    80,
      81,    13,    13,    12,     8,    22,    78,    -1,    79,    88,
      71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    26,    27,    28,     0,     5,     8,     9,    10,
      29,     3,     4,     5,     6,     7,     8,    12,    14,    15,
      16,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    48,     5,    12,
      35,     6,    13,     5,    45,    46,    35,    33,    33,    33,
      11,    31,    12,    17,    18,    19,    14,    15,    20,    21,
      13,    16,    22,    23,    12,     5,    49,    50,    35,    13,
      12,    24,     9,    33,    33,    33,    36,    36,    20,    21,
      13,    13,    13,    37,    13,    37,    13,    12,    24,    12,
      35,    47,    46,    39,    40,    41,    41,    37,    37,    35,
      51,    52,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    27,    28,    29,    30,    30,    31,    31,
      32,    32,    32,    32,    32,    32,    33,    33,    33,    33,
      34,    34,    34,    35,    36,    36,    36,    36,    37,    37,
      37,    38,    38,    39,    39,    40,    40,    40,    41,    41,
      41,    41,    41,    42,    43,    43,    44,    45,    45,    46,
      46,    47,    48,    49,    49,    50,    51,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     3,     1,     2,     1,     1,
       3,     4,     1,     1,     2,     2,     1,     2,     2,     2,
       3,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     4,     1,     4,     1,     4,     4,     1,     3,
       3,     4,     4,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     4,     1,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (ast, YY_("syntax error: cannot back up")); \
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
                  Type, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (ast);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, ast);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::unique_ptr<BaseAST> &ast)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYUSE (yyvaluep);
  YYUSE (ast);
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
yyparse (std::unique_ptr<BaseAST> &ast)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 61 "/share/sysy-make-template/src/sysy.y"
            {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->func_def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast = move(comp_unit);
  }
#line 1410 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 3:
#line 79 "/share/sysy-make-template/src/sysy.y"
                                 {
    auto ast = new FuncDefAST();
    ast->func_type = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1422 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 4:
#line 90 "/share/sysy-make-template/src/sysy.y"
          {
    auto ast = new FuncTypeAST();
    ast->mytype = "int";
    (yyval.ast_val) = ast;
  }
#line 1432 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 5:
#line 98 "/share/sysy-make-template/src/sysy.y"
                          {
    auto ast = new BlockAST();
    ast->blockitem = move(*((yyvsp[-1].vec_val)));
    (yyval.ast_val) = ast;
  }
#line 1442 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 6:
#line 106 "/share/sysy-make-template/src/sysy.y"
             {
  auto v = new vector<unique_ptr<BaseAST>>();
  v->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
  (yyval.vec_val) = move(v);
 }
#line 1452 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 7:
#line 110 "/share/sysy-make-template/src/sysy.y"
                             {
  auto v = ((yyvsp[-1].vec_val));
  v->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
  (yyval.vec_val) = move(v);
 }
#line 1462 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 8:
#line 118 "/share/sysy-make-template/src/sysy.y"
        {
  auto ast = new BlockItemAST();
  ast->decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1472 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 9:
#line 122 "/share/sysy-make-template/src/sysy.y"
          {
  auto ast = new BlockItemAST();
  ast->stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1482 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 10:
#line 130 "/share/sysy-make-template/src/sysy.y"
                   {
   auto ast = new StmtAST();
   ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
   (yyval.ast_val) = ast;
  }
#line 1492 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 11:
#line 134 "/share/sysy-make-template/src/sysy.y"
                        {
    auto ast = new StmtAST();
    ast->lval = *unique_ptr<string>((yyvsp[-3].str_val));
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1503 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 12:
#line 139 "/share/sysy-make-template/src/sysy.y"
            {
    auto ast = new StmtAST();
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1513 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 13:
#line 143 "/share/sysy-make-template/src/sysy.y"
         {
    auto ast = new StmtAST();
    (yyval.ast_val) = ast;
  }
#line 1522 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 14:
#line 146 "/share/sysy-make-template/src/sysy.y"
                 {
    auto ast = new StmtAST();
    (yyval.ast_val) = ast;
  }
#line 1531 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 15:
#line 149 "/share/sysy-make-template/src/sysy.y"
              {
    auto ast = new StmtAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1541 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 16:
#line 157 "/share/sysy-make-template/src/sysy.y"
               {
    auto ast = new UnaryExpAST();
    ast->pexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1551 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 17:
#line 162 "/share/sysy-make-template/src/sysy.y"
                 {
    auto ast = new UnaryExpAST();
    ast->uop = '+';
    ast->uexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast; 
  }
#line 1562 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 18:
#line 168 "/share/sysy-make-template/src/sysy.y"
                 {
    auto ast = new UnaryExpAST();
    ast->uop = '-';
    ast->uexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast; 
  }
#line 1573 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 19:
#line 174 "/share/sysy-make-template/src/sysy.y"
                 {
    auto ast = new UnaryExpAST();
    ast->uop = '!';
    ast->uexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast; 
  }
#line 1584 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 20:
#line 183 "/share/sysy-make-template/src/sysy.y"
                {
    auto ast = new PrimaryExpAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1594 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 21:
#line 188 "/share/sysy-make-template/src/sysy.y"
           {
    auto ast = new PrimaryExpAST();
    ast->num = ((yyvsp[0].int_val));
    (yyval.ast_val) = ast;
  }
#line 1604 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 22:
#line 192 "/share/sysy-make-template/src/sysy.y"
            {
    auto ast = new PrimaryExpAST();
    ast->lval = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = ast;
  }
#line 1614 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 23:
#line 201 "/share/sysy-make-template/src/sysy.y"
           {
    auto ast = new ExpAST();
    ast->lorexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1624 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 24:
#line 209 "/share/sysy-make-template/src/sysy.y"
             {
    auto ast = new MulExpAST();
    ast->uexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1634 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 25:
#line 213 "/share/sysy-make-template/src/sysy.y"
                          {
    auto ast = new MulExpAST();
    ast->mexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->mop = '*';
    ast->uexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1646 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 26:
#line 219 "/share/sysy-make-template/src/sysy.y"
                          {
    auto ast = new MulExpAST();
    ast->mexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->mop = '/';
    ast->uexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1658 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 27:
#line 225 "/share/sysy-make-template/src/sysy.y"
                          {
    auto ast = new MulExpAST();
    ast->mexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->mop = '%';
    ast->uexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1670 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 28:
#line 235 "/share/sysy-make-template/src/sysy.y"
           {
    auto ast = new AddExpAST();
    ast->mexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1680 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 29:
#line 239 "/share/sysy-make-template/src/sysy.y"
                        {
    auto ast = new AddExpAST();
    ast->aop = '+';
    ast->mexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast->aexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1692 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 30:
#line 245 "/share/sysy-make-template/src/sysy.y"
                        {
    auto ast = new AddExpAST();
    ast->aop = '-';
    ast->mexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast->aexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1704 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 31:
#line 256 "/share/sysy-make-template/src/sysy.y"
           {
  auto ast = new LorExpAST();
  ast->landexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1714 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 32:
#line 260 "/share/sysy-make-template/src/sysy.y"
                           {
  auto ast = new LorExpAST();
  ast->landexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->lorexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1725 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 33:
#line 269 "/share/sysy-make-template/src/sysy.y"
         {
  auto ast = new LandExpAST();
  ast->eqexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1735 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 34:
#line 273 "/share/sysy-make-template/src/sysy.y"
                          {
  auto ast = new LandExpAST();
  ast->eqexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->landexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1746 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 35:
#line 282 "/share/sysy-make-template/src/sysy.y"
          {
  auto ast = new EqExpAST();
  ast->relexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1756 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 36:
#line 286 "/share/sysy-make-template/src/sysy.y"
                         {
  auto ast = new EqExpAST();
  ast->eqop = string("==");
  ast->relexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->eqexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1768 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 37:
#line 292 "/share/sysy-make-template/src/sysy.y"
                         {
  auto ast = new EqExpAST();
  ast->eqop = string("!=");
  ast->relexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->eqexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1780 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 38:
#line 303 "/share/sysy-make-template/src/sysy.y"
          {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1790 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 39:
#line 307 "/share/sysy-make-template/src/sysy.y"
                       {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->relexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
  ast->relop = string(">");
  (yyval.ast_val) = ast;
 }
#line 1802 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 40:
#line 313 "/share/sysy-make-template/src/sysy.y"
                       {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->relexp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
  ast->relop = string("<");
  (yyval.ast_val) = ast;
 }
#line 1814 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 41:
#line 319 "/share/sysy-make-template/src/sysy.y"
                          {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->relexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
  ast->relop = string(">=");
  (yyval.ast_val) = ast;
 }
#line 1826 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 42:
#line 325 "/share/sysy-make-template/src/sysy.y"
                          {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  ast->relexp = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
  ast->relop = string("<=");
  (yyval.ast_val) = ast;
 }
#line 1838 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 43:
#line 335 "/share/sysy-make-template/src/sysy.y"
              {
   int num;
   num = ((yyvsp[0].int_val));
   (yyval.int_val) = num;
  }
#line 1848 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 44:
#line 343 "/share/sysy-make-template/src/sysy.y"
              {
    auto ast = new DeclAST();
    ast->constdecl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1858 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 45:
#line 347 "/share/sysy-make-template/src/sysy.y"
              {
    auto ast = new DeclAST();
    ast->vardecl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1868 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 46:
#line 354 "/share/sysy-make-template/src/sysy.y"
                         {
    auto ast = new VarDclAST();
    ast->btype = "int";
    auto v_ptr = ((yyvsp[-1].vec_val));
    ast->vardef = move(*v_ptr);
    (yyval.ast_val) = ast;
  }
#line 1880 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 47:
#line 364 "/share/sysy-make-template/src/sysy.y"
           {
    auto v = new vector<unique_ptr<BaseAST>>();
    v->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
    (yyval.vec_val) = move(v);
  }
#line 1890 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 48:
#line 368 "/share/sysy-make-template/src/sysy.y"
                            {
    auto v = ((yyvsp[-2].vec_val));
    v->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
    (yyval.vec_val) = move(v);
  }
#line 1900 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 49:
#line 376 "/share/sysy-make-template/src/sysy.y"
          {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = ast;
  }
#line 1910 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 50:
#line 380 "/share/sysy-make-template/src/sysy.y"
                        {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    ast->initval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1921 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 51:
#line 389 "/share/sysy-make-template/src/sysy.y"
       {
  auto ast = new InitValAST();
  ast->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
  (yyval.ast_val) = ast;
 }
#line 1931 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 52:
#line 397 "/share/sysy-make-template/src/sysy.y"
                                 {
    auto ast = new ConstDeclAST();
    ast->btype = "int";
    auto v_ptr = ((yyvsp[-1].vec_val));
    ast->constdef = move(*v_ptr);
    (yyval.ast_val) = ast;
  }
#line 1943 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 53:
#line 407 "/share/sysy-make-template/src/sysy.y"
              {
    auto v = new vector<unique_ptr<BaseAST>>();
    v->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
    (yyval.vec_val) = move(v);
   }
#line 1953 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 54:
#line 411 "/share/sysy-make-template/src/sysy.y"
                                 {
    auto v = ((yyvsp[-2].vec_val));
    v->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
    (yyval.vec_val) = move(v);
   }
#line 1963 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 55:
#line 419 "/share/sysy-make-template/src/sysy.y"
                             {
      auto ast = new ConstDefAST();
      ast->ident = *unique_ptr<string>((yyvsp[-2].str_val));
      ast->constinitval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = ast;
    }
#line 1974 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 56:
#line 428 "/share/sysy-make-template/src/sysy.y"
               {
      auto ast = new ConstInitValAST();
      ast->constexp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = ast;
    }
#line 1984 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;

  case 57:
#line 436 "/share/sysy-make-template/src/sysy.y"
         {
    auto ast = new ConstExpAST();
    ast->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
   }
#line 1994 "/share/sysy-make-template/build/sysy.tab.cpp"
    break;


#line 1998 "/share/sysy-make-template/build/sysy.tab.cpp"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (ast, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (ast, yymsgp);
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
                      yytoken, &yylval, ast);
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
                  yystos[yystate], yyvsp, ast);
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
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, ast);
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
#line 443 "/share/sysy-make-template/src/sysy.y"


// 定义错误处理函数, 其中第二个参数是错误信息
// parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}
