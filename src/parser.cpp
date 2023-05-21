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
#line 1 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"

#include "AbstractSyntaxTree.h"
#include <cstring>
#include <cstdio>

void yyerror(const char *s) { 
    printf("Error: %s\n", s);
    exit(1); 
}

int yylex(void);

Program* syntax_root;


#line 87 "/home/freesia/spl_run/src/parser.cpp"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LP = 3,                         /* LP  */
  YYSYMBOL_RP = 4,                         /* RP  */
  YYSYMBOL_LB = 5,                         /* LB  */
  YYSYMBOL_RB = 6,                         /* RB  */
  YYSYMBOL_DOT = 7,                        /* DOT  */
  YYSYMBOL_COMMA = 8,                      /* COMMA  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_MUL = 10,                       /* MUL  */
  YYSYMBOL_UNEQUAL = 11,                   /* UNEQUAL  */
  YYSYMBOL_NOT = 12,                       /* NOT  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_MINUS = 14,                     /* MINUS  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_EQUAL = 19,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_MOD = 21,                       /* MOD  */
  YYSYMBOL_DOTDOT = 22,                    /* DOTDOT  */
  YYSYMBOL_SEMI = 23,                      /* SEMI  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_ARRAY = 25,                     /* ARRAY  */
  YYSYMBOL_SPL_BEGIN = 26,                 /* SPL_BEGIN  */
  YYSYMBOL_CASE = 27,                      /* CASE  */
  YYSYMBOL_CONST = 28,                     /* CONST  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_DO = 30,                        /* DO  */
  YYSYMBOL_DOWNTO = 31,                    /* DOWNTO  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_END = 33,                       /* END  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_FUNCTION = 35,                  /* FUNCTION  */
  YYSYMBOL_GOTO = 36,                      /* GOTO  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_OF = 38,                        /* OF  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_ENDIF = 40,                     /* ENDIF  */
  YYSYMBOL_PROCEDURE = 41,                 /* PROCEDURE  */
  YYSYMBOL_PROGRAM = 42,                   /* PROGRAM  */
  YYSYMBOL_RECORD = 43,                    /* RECORD  */
  YYSYMBOL_REPEAT = 44,                    /* REPEAT  */
  YYSYMBOL_THEN = 45,                      /* THEN  */
  YYSYMBOL_TO = 46,                        /* TO  */
  YYSYMBOL_TYPE = 47,                      /* TYPE  */
  YYSYMBOL_UNTIL = 48,                     /* UNTIL  */
  YYSYMBOL_VAR = 49,                       /* VAR  */
  YYSYMBOL_WHILE = 50,                     /* WHILE  */
  YYSYMBOL_INTEGER = 51,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 52,                /* IDENTIFIER  */
  YYSYMBOL_SYS_CON = 53,                   /* SYS_CON  */
  YYSYMBOL_SYS_FUNCT = 54,                 /* SYS_FUNCT  */
  YYSYMBOL_SYS_PROC = 55,                  /* SYS_PROC  */
  YYSYMBOL_SYS_TYPE = 56,                  /* SYS_TYPE  */
  YYSYMBOL_READ = 57,                      /* READ  */
  YYSYMBOL_REAL = 58,                      /* REAL  */
  YYSYMBOL_CHAR = 59,                      /* CHAR  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_program_head = 62,              /* program_head  */
  YYSYMBOL_routine = 63,                   /* routine  */
  YYSYMBOL_routine_head = 64,              /* routine_head  */
  YYSYMBOL_const_part = 65,                /* const_part  */
  YYSYMBOL_const_expr_list = 66,           /* const_expr_list  */
  YYSYMBOL_const_value = 67,               /* const_value  */
  YYSYMBOL_type_part = 68,                 /* type_part  */
  YYSYMBOL_type_decl_list = 69,            /* type_decl_list  */
  YYSYMBOL_type_definition = 70,           /* type_definition  */
  YYSYMBOL_type_decl = 71,                 /* type_decl  */
  YYSYMBOL_simple_type_decl = 72,          /* simple_type_decl  */
  YYSYMBOL_array_type_decl = 73,           /* array_type_decl  */
  YYSYMBOL_record_type_decl = 74,          /* record_type_decl  */
  YYSYMBOL_field_decl_list = 75,           /* field_decl_list  */
  YYSYMBOL_field_decl = 76,                /* field_decl  */
  YYSYMBOL_name_list = 77,                 /* name_list  */
  YYSYMBOL_var_part = 78,                  /* var_part  */
  YYSYMBOL_var_decl_list = 79,             /* var_decl_list  */
  YYSYMBOL_var_decl = 80,                  /* var_decl  */
  YYSYMBOL_routine_part = 81,              /* routine_part  */
  YYSYMBOL_function_decl = 82,             /* function_decl  */
  YYSYMBOL_function_head = 83,             /* function_head  */
  YYSYMBOL_procedure_decl = 84,            /* procedure_decl  */
  YYSYMBOL_procedure_head = 85,            /* procedure_head  */
  YYSYMBOL_parameters = 86,                /* parameters  */
  YYSYMBOL_para_decl_list = 87,            /* para_decl_list  */
  YYSYMBOL_para_type_list = 88,            /* para_type_list  */
  YYSYMBOL_var_para_list = 89,             /* var_para_list  */
  YYSYMBOL_val_para_list = 90,             /* val_para_list  */
  YYSYMBOL_sub_routine = 91,               /* sub_routine  */
  YYSYMBOL_routine_body = 92,              /* routine_body  */
  YYSYMBOL_compound_stmt = 93,             /* compound_stmt  */
  YYSYMBOL_stmt_list = 94,                 /* stmt_list  */
  YYSYMBOL_stmt = 95,                      /* stmt  */
  YYSYMBOL_non_label_stmt = 96,            /* non_label_stmt  */
  YYSYMBOL_assign_stmt = 97,               /* assign_stmt  */
  YYSYMBOL_proc_stmt = 98,                 /* proc_stmt  */
  YYSYMBOL_if_stmt = 99,                   /* if_stmt  */
  YYSYMBOL_else_clause = 100,              /* else_clause  */
  YYSYMBOL_repeat_stmt = 101,              /* repeat_stmt  */
  YYSYMBOL_while_stmt = 102,               /* while_stmt  */
  YYSYMBOL_for_stmt = 103,                 /* for_stmt  */
  YYSYMBOL_direction = 104,                /* direction  */
  YYSYMBOL_case_stmt = 105,                /* case_stmt  */
  YYSYMBOL_case_expr_list = 106,           /* case_expr_list  */
  YYSYMBOL_case_expr = 107,                /* case_expr  */
  YYSYMBOL_goto_stmt = 108,                /* goto_stmt  */
  YYSYMBOL_expression_list = 109,          /* expression_list  */
  YYSYMBOL_expression = 110,               /* expression  */
  YYSYMBOL_expr = 111,                     /* expr  */
  YYSYMBOL_term = 112,                     /* term  */
  YYSYMBOL_factor = 113,                   /* factor  */
  YYSYMBOL_args_list = 114,                /* args_list  */
  YYSYMBOL_name = 115                      /* name  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  259

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   122,   125,   128,   132,   133,   137,   138,
     142,   147,   152,   157,   172,   173,   177,   178,   182,   186,
     187,   188,   192,   206,   211,   216,   226,   236,   246,   258,
     261,   265,   266,   269,   273,   274,   278,   279,   283,   284,
     287,   291,   297,   303,   306,   309,   312,   315,   319,   320,
     324,   325,   329,   335,   343,   346,   349,   352,   355,   359,
     360,   364,   365,   369,   374,   379,   384,   389,   394,   399,
     404,   409,   417,   422,   427,   435,   440,   445,   458,   471,
     478,   482,   483,   486,   489,   493,   497,   498,   501,   505,
     506,   510,   511,   514,   518,   519,   523,   524,   525,   526,
     527,   528,   529,   533,   534,   535,   536,   540,   541,   542,
     543,   544,   548,   549,   550,   581,   612,   613,   614,   615,
     616,   621,   629,   630,   634
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
  "\"end of file\"", "error", "\"invalid token\"", "LP", "RP", "LB", "RB",
  "DOT", "COMMA", "COLON", "MUL", "UNEQUAL", "NOT", "PLUS", "MINUS", "GE",
  "GT", "LE", "LT", "EQUAL", "ASSIGN", "MOD", "DOTDOT", "SEMI", "AND",
  "ARRAY", "SPL_BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO", "ELSE",
  "END", "FOR", "FUNCTION", "GOTO", "IF", "OF", "OR", "ENDIF", "PROCEDURE",
  "PROGRAM", "RECORD", "REPEAT", "THEN", "TO", "TYPE", "UNTIL", "VAR",
  "WHILE", "INTEGER", "IDENTIFIER", "SYS_CON", "SYS_FUNCT", "SYS_PROC",
  "SYS_TYPE", "READ", "REAL", "CHAR", "$accept", "program", "program_head",
  "routine", "routine_head", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "simple_type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "sub_routine", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "proc_stmt", "if_stmt", "else_clause",
  "repeat_stmt", "while_stmt", "for_stmt", "direction", "case_stmt",
  "case_expr_list", "case_expr", "goto_stmt", "expression_list",
  "expression", "expr", "term", "factor", "args_list", "name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -23,    44,    58,    79,  -141,    31,   104,    80,    87,
    -141,  -141,    31,   128,  -141,  -141,  -141,  -141,    31,   111,
     143,    85,   132,    31,  -141,   145,    31,  -141,    85,  -141,
    -141,  -141,  -141,   144,    98,  -141,    31,   119,    98,  -141,
      98,   162,   169,   171,  -141,   152,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,   112,  -141,   197,    49,    31,
    -141,  -141,   -17,   163,  -141,    98,    98,    98,   182,  -141,
     216,     0,    21,  -141,    84,   172,  -141,    60,   225,   307,
     264,    98,    98,  -141,    98,    98,    31,    98,    31,    85,
     190,    31,  -141,   175,   176,  -141,  -141,  -141,   180,    31,
     197,  -141,    31,    31,  -141,   183,  -141,   189,  -141,   325,
    -141,  -141,    98,    98,    98,    98,    98,    98,    98,   156,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    31,
      98,   252,    98,   252,  -141,    48,   362,   194,   362,    65,
     339,   185,   362,    99,   195,     8,   -25,  -141,   120,    85,
    -141,    31,  -141,   193,   218,   218,    58,    58,  -141,   110,
       0,     0,     0,     0,     0,     0,   210,   212,  -141,   219,
      21,    21,    21,  -141,  -141,  -141,  -141,   116,   353,  -141,
      17,   204,   362,  -141,  -141,    98,  -141,  -141,    98,   205,
      98,  -141,    -4,   232,  -141,  -141,   197,  -141,  -141,  -141,
     -26,   230,  -141,    80,   221,   223,  -141,   252,  -141,  -141,
     252,  -141,  -141,  -141,  -141,    98,   252,   217,   362,   362,
      98,   362,    85,  -141,   220,   237,    31,   258,    42,  -141,
     259,   263,     8,  -141,  -141,  -141,   244,   251,   316,  -141,
    -141,   362,  -141,   197,  -141,   258,  -141,   -26,     8,     8,
    -141,  -141,  -141,   252,  -141,  -141,  -141,  -141,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     0,    15,
       3,   124,     6,     0,     2,    60,     4,    57,     0,    37,
       0,     0,     0,    14,    17,     0,     0,    43,     0,    10,
      13,    11,    12,     0,     0,    58,     0,     0,     0,    60,
       0,     0,    77,     0,    65,     0,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    75,    16,     0,     0,    36,
      39,    35,     5,     0,     9,     0,     0,     0,   114,   116,
       0,   102,   106,   111,   112,     0,    93,     0,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,    19,    20,    21,    23,     0,
       0,    38,     0,     0,    41,     0,    42,     0,     8,     0,
     118,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,    95,     0,   123,     0,
       0,     0,    72,     0,     0,     0,     0,    32,     0,     0,
      18,     0,    34,     0,    49,    49,     7,     7,   117,     0,
     101,    96,    97,    98,    99,   100,     0,     0,    90,     0,
     103,   104,   105,   107,   109,   110,   108,     0,     0,   121,
       0,    82,    83,    84,    78,     0,    79,    76,     0,     0,
       0,    24,     0,     0,    30,    31,     0,    25,    28,    40,
       0,     0,    47,     0,     0,     0,   115,     0,    88,    89,
       0,   113,   120,    87,    86,     0,     0,     0,    94,   122,
       0,    74,     0,    26,     0,     0,     0,    55,     0,    51,
       0,     0,     0,    56,    44,    46,     0,     0,     0,    81,
      80,    73,    27,     0,    33,    54,    48,     0,     0,     0,
      45,    91,    92,     0,    29,    50,    52,    53,    85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,   278,  -141,  -141,   -19,  -141,  -141,
     260,   -97,  -140,  -141,  -141,  -141,   138,   -84,  -141,  -141,
     226,  -141,  -141,  -141,  -141,  -141,   137,  -141,    40,  -141,
    -141,   136,    91,    -7,   256,  -112,   231,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,   130,  -141,  -141,
       3,   269,    33,    55,   -87,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,   203,     9,    12,    69,    19,    23,
      24,    94,    95,    96,    97,   146,   147,    58,    27,    59,
      60,    62,   104,   105,   106,   107,   201,   228,   229,   230,
     231,   204,    16,    44,    22,    45,    46,    47,    48,    49,
     217,    50,    51,    52,   215,    53,   167,   168,    54,   135,
     138,    71,    72,    73,   139,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    17,    33,   153,   143,   193,    20,   148,   194,    63,
     222,    88,    25,   120,   121,     1,    55,    25,   102,   181,
      61,   183,    89,   226,   103,   159,    11,    11,   113,     4,
      75,   123,   114,   115,   116,   117,   118,    70,    93,   122,
     177,    77,   124,    79,     5,   125,   246,    29,   213,    30,
     126,    98,   184,    61,    31,    32,   185,    99,   100,    29,
      11,    30,   148,   214,    92,   247,    31,    32,   109,   187,
     144,   113,    55,   188,    55,   114,   115,   116,   117,   118,
     141,    93,    61,    11,   136,    61,     6,   127,   140,   128,
     142,   129,   250,   152,    98,   236,   154,   155,   237,   225,
     166,    65,    10,   191,   239,   131,    15,    99,   256,   257,
      66,    14,    67,   169,   206,    84,   227,    85,   188,    86,
     211,   110,   111,   179,   188,    55,    93,    55,    99,   196,
     197,   178,    87,   180,    18,   182,    29,   137,    30,    98,
      61,   258,   245,    31,    32,   198,   254,    21,   166,    29,
      11,    30,    68,   170,   171,   172,    31,    32,    15,    34,
      26,   169,    28,   227,    57,    35,    36,    64,    37,    38,
      76,    80,    81,   223,    82,    83,    39,    93,   173,   174,
     175,   176,    40,    41,    11,   112,   108,    42,   218,    43,
      98,   219,   130,   221,    61,   145,    17,   149,   186,   150,
      88,    55,   151,   242,    55,   190,   156,    29,    11,    30,
      55,    89,   157,    93,    31,    32,   199,   192,   238,   207,
      61,   200,    90,   241,    93,   220,    98,   113,   210,    93,
      93,   114,   115,   116,   117,   118,   216,    98,   224,   232,
      91,    61,    98,    98,   234,   208,   235,    55,    29,    11,
      30,    15,    34,    92,   119,    31,    32,   240,   243,    36,
     244,    37,    38,    29,    11,    30,    99,   251,   248,    39,
      31,    32,   249,   132,   252,    40,    41,    11,    15,    34,
      42,     8,    43,    56,   195,   101,    36,   255,    37,    38,
      15,    34,   202,   205,   233,    78,    39,   209,    36,     0,
      37,    38,    40,    41,    11,     0,     0,    42,    39,    43,
       0,   134,     0,     0,    40,     0,    11,     0,   113,    42,
       0,    43,   114,   115,   116,   117,   118,   113,     0,   158,
       0,   114,   115,   116,   117,   118,   113,   133,     0,     0,
     114,   115,   116,   117,   118,   189,   253,     0,     0,     0,
     113,     0,     0,     0,   114,   115,   116,   117,   118,   212,
       0,     0,     0,     0,   113,     0,     0,     0,   114,   115,
     116,   117,   118,   113,     0,     0,     0,   114,   115,   116,
     117,   118,   160,   161,   162,   163,   164,   165
};

static const yytype_int16 yycheck[] =
{
       6,     8,    21,   100,    88,   145,    12,    91,    33,    28,
      14,     3,    18,    13,    14,    42,    22,    23,    35,   131,
      26,   133,    14,    49,    41,   112,    52,    52,    11,    52,
      36,    10,    15,    16,    17,    18,    19,    34,    57,    39,
     127,    38,    21,    40,     0,    24,     4,    51,    31,    53,
      29,    57,     4,    59,    58,    59,     8,     8,     9,    51,
      52,    53,   146,    46,    56,    23,    58,    59,    65,     4,
      89,    11,    78,     8,    80,    15,    16,    17,    18,    19,
      86,   100,    88,    52,    81,    91,    28,     3,    85,     5,
      87,     7,   232,    99,   100,   207,   102,   103,   210,   196,
     119,     3,    23,     4,   216,    45,    26,     8,   248,   249,
      12,     7,    14,   119,     4,     3,   200,     5,     8,     7,
       4,    66,    67,   129,     8,   131,   145,   133,     8,     9,
     149,   128,    20,   130,    47,   132,    51,    82,    53,   145,
     146,   253,   226,    58,    59,   151,   243,    19,   167,    51,
      52,    53,    54,   120,   121,   122,    58,    59,    26,    27,
      49,   167,    19,   247,    19,    33,    34,    23,    36,    37,
      51,     9,     3,   192,     3,    23,    44,   196,   123,   124,
     125,   126,    50,    51,    52,     3,    23,    55,   185,    57,
     196,   188,    20,   190,   200,     5,   203,    22,     4,    23,
       3,   207,    22,   222,   210,    20,    23,    51,    52,    53,
     216,    14,    23,   232,    58,    59,    23,    22,   215,     9,
     226,     3,    25,   220,   243,    20,   232,    11,     9,   248,
     249,    15,    16,    17,    18,    19,    32,   243,     6,     9,
      43,   247,   248,   249,    23,    33,    23,   253,    51,    52,
      53,    26,    27,    56,    38,    58,    59,    40,    38,    34,
      23,    36,    37,    51,    52,    53,     8,    23,     9,    44,
      58,    59,     9,    48,    23,    50,    51,    52,    26,    27,
      55,     3,    57,    23,   146,    59,    34,   247,    36,    37,
      26,    27,   155,   157,   203,    39,    44,   167,    34,    -1,
      36,    37,    50,    51,    52,    -1,    -1,    55,    44,    57,
      -1,    80,    -1,    -1,    50,    -1,    52,    -1,    11,    55,
      -1,    57,    15,    16,    17,    18,    19,    11,    -1,     4,
      -1,    15,    16,    17,    18,    19,    11,    30,    -1,    -1,
      15,    16,    17,    18,    19,     6,    30,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,     6,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,   113,   114,   115,   116,   117,   118
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    61,    62,    52,     0,    28,    63,    64,    65,
      23,    52,    66,   115,     7,    26,    92,    93,    47,    68,
     115,    19,    94,    69,    70,   115,    49,    78,    19,    51,
      53,    58,    59,    67,    27,    33,    34,    36,    37,    44,
      50,    51,    55,    57,    93,    95,    96,    97,    98,    99,
     101,   102,   103,   105,   108,   115,    70,    19,    77,    79,
      80,   115,    81,    67,    23,     3,    12,    14,    54,    67,
     110,   111,   112,   113,   115,   115,    51,   110,    94,   110,
       9,     3,     3,    23,     3,     5,     7,    20,     3,    14,
      25,    43,    56,    67,    71,    72,    73,    74,   115,     8,
       9,    80,    35,    41,    82,    83,    84,    85,    23,   110,
     113,   113,     3,    11,    15,    16,    17,    18,    19,    38,
      13,    14,    39,    10,    21,    24,    29,     3,     5,     7,
      20,    45,    48,    30,    96,   109,   110,   113,   110,   114,
     110,   115,   110,    77,    67,     5,    75,    76,    77,    22,
      23,    22,   115,    71,   115,   115,    23,    23,     4,   114,
     111,   111,   111,   111,   111,   111,    67,   106,   107,   115,
     112,   112,   112,   113,   113,   113,   113,   114,   110,   115,
     110,    95,   110,    95,     4,     8,     4,     4,     8,     6,
      20,     4,    22,    72,    33,    76,     9,    67,   115,    23,
       3,    86,    86,    64,    91,    91,     4,     9,    33,   107,
       9,     4,     6,    31,    46,   104,    32,   100,   110,   110,
      20,   110,    14,    67,     6,    71,    49,    77,    87,    88,
      89,    90,     9,    92,    23,    23,    95,    95,   110,    95,
      40,   110,    67,    38,    23,    77,     4,    23,     9,     9,
      72,    23,    23,    30,    71,    88,    72,    72,    95
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    75,    75,    76,    77,    77,    78,    78,    79,    79,
      80,    81,    81,    81,    82,    83,    84,    85,    86,    86,
      87,    87,    88,    88,    89,    90,    91,    92,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    98,    98,
      99,   100,   100,   101,   102,   103,   104,   104,   105,   106,
     106,   107,   107,   108,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     4,     2,     0,     5,     4,
       1,     1,     1,     1,     2,     0,     2,     1,     4,     1,
       1,     1,     1,     1,     3,     3,     4,     5,     3,     6,
       3,     2,     1,     4,     3,     1,     2,     0,     2,     1,
       4,     2,     2,     0,     4,     5,     4,     3,     3,     0,
       3,     1,     3,     3,     2,     1,     2,     1,     3,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     5,     1,     4,     1,     4,     4,
       6,     2,     0,     4,     4,     8,     1,     1,     5,     2,
       1,     4,     4,     2,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     1,     4,     1,     4,     1,     3,     2,     2,
       4,     3,     3,     1,     1
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
  case 2: /* program: program_head routine DOT  */
#line 119 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.program) = new Program((yyvsp[-2].program_head), (yyvsp[-1].routine)); syntax_root = (yyval.program); }
#line 1666 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 3: /* program_head: PROGRAM IDENTIFIER SEMI  */
#line 122 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.program_head) = new ProgramId(); strcpy((yyval.program_head)->id, (yyvsp[-1].str_value)); }
#line 1672 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 4: /* routine: routine_head routine_body  */
#line 125 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.routine) = new Routine((yyvsp[-1].routine_head), (yyvsp[0].routine_body)); }
#line 1678 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 5: /* routine_head: const_part type_part var_part routine_part  */
#line 128 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                            { (yyval.routine_head) = new RoutineHead(nullptr, (yyvsp[-3].const_expr), (yyvsp[-2].type_definition), (yyvsp[-1].normal_decl), (yyvsp[0].call_decl)); }
#line 1684 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 6: /* const_part: CONST const_expr_list  */
#line 132 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.const_expr) = (yyvsp[0].const_expr); }
#line 1690 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 7: /* const_part: %empty  */
#line 133 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.const_expr) = nullptr; }
#line 1696 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 8: /* const_expr_list: const_expr_list name EQUAL const_value SEMI  */
#line 137 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    {   (yyval.const_expr) = AddElement<ConstExprssion>((yyvsp[-4].const_expr), new ConstExprssion((yyvsp[-3].identifier), (yyvsp[-1].const_value))); }
#line 1702 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 9: /* const_expr_list: name EQUAL const_value SEMI  */
#line 138 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    {   (yyval.const_expr) = new ConstExprssion((yyvsp[-3].identifier), (yyvsp[-1].const_value)); }
#line 1708 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 10: /* const_value: INTEGER  */
#line 142 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                { 
                    (yyval.const_value) = new ConstValue();
                    (yyval.const_value)->flag = ConstValue::INT;
                    (yyval.const_value)->value.int_value = (yyvsp[0].int_value);
                }
#line 1718 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 11: /* const_value: REAL  */
#line 147 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                { 
                    (yyval.const_value) = new ConstValue();
                    (yyval.const_value)->flag = ConstValue::REAL;
                    (yyval.const_value)->value.real_value = (yyvsp[0].real_value);
                }
#line 1728 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 12: /* const_value: CHAR  */
#line 152 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                { 
                    (yyval.const_value) = new ConstValue();
                    (yyval.const_value)->flag = ConstValue::CHAR;
                    (yyval.const_value)->value.char_value = (yyvsp[0].char_value);
                }
#line 1738 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 13: /* const_value: SYS_CON  */
#line 157 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                {
                    (yyval.const_value) = new ConstValue();
                    (yyval.const_value)->flag = ConstValue::SYS_CON;
                    if(!strcmp((yyvsp[0].str_value), "true"))
                        (yyval.const_value)->value.sys_con_value = Sys_Con::TRUE;
                    else if(!strcmp((yyvsp[0].str_value), "false"))
                        (yyval.const_value)->value.sys_con_value = Sys_Con::FALSE;
                    else if(!strcmp((yyvsp[0].str_value), "maxint"))
                        (yyval.const_value)->value.sys_con_value = Sys_Con::MAXINT;
                    else
                        yyerror((yyvsp[0].str_value));
                }
#line 1755 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 14: /* type_part: TYPE type_decl_list  */
#line 172 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                        { (yyval.type_definition) = (yyvsp[0].type_definition); }
#line 1761 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 15: /* type_part: %empty  */
#line 173 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                        { (yyval.type_definition) = nullptr; }
#line 1767 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 16: /* type_decl_list: type_decl_list type_definition  */
#line 177 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.type_definition) = AddElement<TypeDefinition>((yyvsp[-1].type_definition), (yyvsp[0].type_definition)); }
#line 1773 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 17: /* type_decl_list: type_definition  */
#line 178 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.type_definition) = (yyvsp[0].type_definition); }
#line 1779 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 18: /* type_definition: name EQUAL type_decl SEMI  */
#line 182 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.type_definition) = new TypeDefinition((yyvsp[-3].identifier), (yyvsp[-1].type_decl)); }
#line 1785 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 19: /* type_decl: simple_type_decl  */
#line 186 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                        { (yyval.type_decl) = new TypeDecl(); (yyval.type_decl)->flag = TypeDecl::SIMPLE; (yyval.type_decl)->decl.simple_decl = (yyvsp[0].simple_type_decl); }
#line 1791 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 20: /* type_decl: array_type_decl  */
#line 187 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                        { (yyval.type_decl) = new TypeDecl(); (yyval.type_decl)->flag = TypeDecl::ARRAY; (yyval.type_decl)->decl.array_decl = (yyvsp[0].array_type_decl); }
#line 1797 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 21: /* type_decl: record_type_decl  */
#line 188 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                        { (yyval.type_decl) = new TypeDecl(); (yyval.type_decl)->flag = TypeDecl::RECORD; (yyval.type_decl)->decl.record_decl = (yyvsp[0].record_type_decl); }
#line 1803 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 22: /* simple_type_decl: SYS_TYPE  */
#line 192 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        {
                                                            (yyval.simple_type_decl) = new SimpleTypeDecl();
                                                            (yyval.simple_type_decl)->flag = SimpleTypeDecl::SYS_TYPE;
                                                            if(!strcmp((yyvsp[0].str_value), "integer"))
                                                                (yyval.simple_type_decl)->type_decl.sys_type_decl = Sys_Type::SYS_INTEGER;
                                                            else if(!strcmp((yyvsp[0].str_value), "boolean"))
                                                                (yyval.simple_type_decl)->type_decl.sys_type_decl = Sys_Type::SYS_BOOLEAN;
                                                            else if(!strcmp((yyvsp[0].str_value), "real"))
                                                                (yyval.simple_type_decl)->type_decl.sys_type_decl = Sys_Type::SYS_REAL;
                                                            else if(!strcmp((yyvsp[0].str_value), "char"))
                                                                (yyval.simple_type_decl)->type_decl.sys_type_decl = Sys_Type::SYS_CHAR;
                                                            else
                                                                yyerror((yyvsp[0].str_value));
                                                        }
#line 1822 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 23: /* simple_type_decl: name  */
#line 206 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        {   
                                                            (yyval.simple_type_decl) = new SimpleTypeDecl();
                                                            (yyval.simple_type_decl)->flag = SimpleTypeDecl::NAME;
                                                            (yyval.simple_type_decl)->type_decl.name_type_decl = (yyvsp[0].identifier);
                                                        }
#line 1832 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 24: /* simple_type_decl: LP name_list RP  */
#line 211 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        { 
                                                            (yyval.simple_type_decl) = new SimpleTypeDecl();
                                                            (yyval.simple_type_decl)->flag = SimpleTypeDecl::NAME_LIST;
                                                            (yyval.simple_type_decl)->type_decl.name_list_decl = (yyvsp[-1].identifier);
                                                        }
#line 1842 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 25: /* simple_type_decl: const_value DOTDOT const_value  */
#line 216 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        {   
                                                            (yyval.simple_type_decl) = new SimpleTypeDecl();
                                                            (yyval.simple_type_decl)->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::POS_POS;
                                                            tmp->c_lhs = (yyvsp[-2].const_value);
                                                            tmp->c_rhs = (yyvsp[0].const_value);
                                                            (yyval.simple_type_decl)->type_decl.range_type_decl = tmp;
                                                        }
#line 1857 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 26: /* simple_type_decl: MINUS const_value DOTDOT const_value  */
#line 226 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        { 
                                                            (yyval.simple_type_decl) = new SimpleTypeDecl();
                                                            (yyval.simple_type_decl)->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::NEG_POS;
                                                            tmp->c_lhs = (yyvsp[-2].const_value);
                                                            tmp->c_rhs = (yyvsp[0].const_value);
                                                            (yyval.simple_type_decl)->type_decl.range_type_decl = tmp;
                                                        }
#line 1872 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 27: /* simple_type_decl: MINUS const_value DOTDOT MINUS const_value  */
#line 236 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        { 
                                                            (yyval.simple_type_decl) = new SimpleTypeDecl();
                                                            (yyval.simple_type_decl)->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::NEG_NEG;
                                                            tmp->c_lhs = (yyvsp[-3].const_value);
                                                            tmp->c_rhs = (yyvsp[0].const_value);
                                                            (yyval.simple_type_decl)->type_decl.range_type_decl = tmp;
                                                        }
#line 1887 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 28: /* simple_type_decl: name DOTDOT name  */
#line 246 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        { 
                                                            (yyval.simple_type_decl) = new SimpleTypeDecl();
                                                            (yyval.simple_type_decl)->flag = SimpleTypeDecl::RANGE_TYPE;
                                                            
                                                            RangeTypeDecl* tmp = new RangeTypeDecl();
                                                            tmp->type = RangeTypeDecl::NAME_NAME;
                                                            tmp->n_lhs = (yyvsp[-2].identifier);
                                                            tmp->n_rhs = (yyvsp[0].identifier);
                                                            (yyval.simple_type_decl)->type_decl.range_type_decl = tmp;
                                                        }
#line 1902 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 29: /* array_type_decl: ARRAY LB simple_type_decl RB OF type_decl  */
#line 258 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                                     { (yyval.array_type_decl) = new ArrayTypeDecl((yyvsp[-3].simple_type_decl), (yyvsp[0].type_decl)); }
#line 1908 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 30: /* record_type_decl: RECORD field_decl_list END  */
#line 261 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                { (yyval.record_type_decl) = new RecordTypeDecl((yyvsp[-1].normal_decl)); }
#line 1914 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 31: /* field_decl_list: field_decl_list field_decl  */
#line 265 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.normal_decl) = AddElement<NormalDecl>((yyvsp[-1].normal_decl), (yyvsp[0].normal_decl)); }
#line 1920 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 32: /* field_decl_list: field_decl  */
#line 266 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.normal_decl) = (yyvsp[0].normal_decl); }
#line 1926 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 33: /* field_decl: name_list COLON type_decl SEMI  */
#line 269 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                { (yyval.normal_decl) = new NormalDecl((yyvsp[-3].identifier), (yyvsp[-1].type_decl)); }
#line 1932 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 34: /* name_list: name_list COMMA name  */
#line 273 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.identifier) = AddElement<Identifier>((yyvsp[-2].identifier), (yyvsp[0].identifier)); }
#line 1938 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 35: /* name_list: name  */
#line 274 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1944 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 36: /* var_part: VAR var_decl_list  */
#line 278 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                        { (yyval.normal_decl) = (yyvsp[0].normal_decl); }
#line 1950 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 37: /* var_part: %empty  */
#line 279 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                        { (yyval.normal_decl) = nullptr; }
#line 1956 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 38: /* var_decl_list: var_decl_list var_decl  */
#line 283 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.normal_decl) = AddElement<NormalDecl>((yyvsp[-1].normal_decl), (yyvsp[0].normal_decl)); }
#line 1962 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 39: /* var_decl_list: var_decl  */
#line 284 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.normal_decl) = (yyvsp[0].normal_decl); }
#line 1968 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 40: /* var_decl: name_list COLON type_decl SEMI  */
#line 287 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                { (yyval.normal_decl) = new NormalDecl((yyvsp[-3].identifier), (yyvsp[-1].type_decl)); }
#line 1974 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 41: /* routine_part: routine_part function_decl  */
#line 291 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    {   
                                        CallDecl* tmp = new CallDecl();
                                        tmp->flag = CallDecl::FUNC;
                                        tmp->decl.func_decl = (yyvsp[0].function_decl);
                                        (yyval.call_decl) = AddElement<CallDecl>((yyvsp[-1].call_decl), tmp);
                                    }
#line 1985 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 42: /* routine_part: routine_part procedure_decl  */
#line 297 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    {   
                                        CallDecl* tmp = new CallDecl();
                                        tmp->flag = CallDecl::PROC;
                                        tmp->decl.proc_decl = (yyvsp[0].procedure_decl);
                                        (yyval.call_decl) = AddElement<CallDecl>((yyvsp[-1].call_decl), tmp);
                                    }
#line 1996 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 43: /* routine_part: %empty  */
#line 303 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    {   (yyval.call_decl) = nullptr; }
#line 2002 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 44: /* function_decl: function_head SEMI sub_routine SEMI  */
#line 306 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                        { (yyval.function_decl) = new FunctionDecl((yyvsp[-3].function_head), (yyvsp[-1].routine)); }
#line 2008 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 45: /* function_head: FUNCTION name parameters COLON simple_type_decl  */
#line 309 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                                        { (yyval.function_head) = new FunctionHead((yyvsp[-3].identifier), (yyvsp[-2].para_type_list), (yyvsp[0].simple_type_decl)); }
#line 2014 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 46: /* procedure_decl: procedure_head SEMI sub_routine SEMI  */
#line 312 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                            { (yyval.procedure_decl) = new ProcedureDecl((yyvsp[-3].procedure_head), (yyvsp[-1].routine)); }
#line 2020 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 47: /* procedure_head: PROCEDURE name parameters  */
#line 315 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { (yyval.procedure_head) = new ProcedureHead((yyvsp[-1].identifier), (yyvsp[0].para_type_list)); }
#line 2026 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 48: /* parameters: LP para_decl_list RP  */
#line 319 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.para_type_list) = (yyvsp[-1].para_type_list); }
#line 2032 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 49: /* parameters: %empty  */
#line 320 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.para_type_list) = nullptr; }
#line 2038 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 50: /* para_decl_list: para_decl_list SEMI para_type_list  */
#line 324 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { (yyval.para_type_list) = AddElement<ParaTypeList>((yyvsp[-2].para_type_list), (yyvsp[0].para_type_list)); }
#line 2044 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 51: /* para_decl_list: para_type_list  */
#line 325 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { (yyval.para_type_list) = (yyvsp[0].para_type_list); }
#line 2050 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 52: /* para_type_list: var_para_list COLON simple_type_decl  */
#line 329 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                { 
                                                    (yyval.para_type_list) = new ParaTypeList();
                                                    (yyval.para_type_list)->flag = ParaTypeList::VAR;
                                                    (yyval.para_type_list)->type = (yyvsp[0].simple_type_decl);
                                                    (yyval.para_type_list)->para_list = (yyvsp[-2].identifier);
                                                }
#line 2061 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 53: /* para_type_list: val_para_list COLON simple_type_decl  */
#line 335 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                { 
                                                    (yyval.para_type_list) = new ParaTypeList();
                                                    (yyval.para_type_list)->flag = ParaTypeList::VAL;
                                                    (yyval.para_type_list)->type = (yyvsp[0].simple_type_decl);
                                                    (yyval.para_type_list)->para_list = (yyvsp[-2].identifier);
                                                }
#line 2072 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 54: /* var_para_list: VAR name_list  */
#line 343 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.identifier) = (yyvsp[0].identifier); }
#line 2078 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 55: /* val_para_list: name_list  */
#line 346 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.identifier) = (yyvsp[0].identifier); }
#line 2084 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 56: /* sub_routine: routine_head routine_body  */
#line 349 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { (yyval.routine) = new Routine((yyvsp[-1].routine_head), (yyvsp[0].routine_body)); }
#line 2090 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 57: /* routine_body: compound_stmt  */
#line 352 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.routine_body) = (yyvsp[0].compound_stmt); }
#line 2096 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 58: /* compound_stmt: SPL_BEGIN stmt_list END  */
#line 355 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { (yyval.compound_stmt) = new CompoundStatement((yyvsp[-1].statement)); }
#line 2102 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 59: /* stmt_list: stmt_list stmt SEMI  */
#line 359 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.statement) = AddElement<Statement>((yyvsp[-2].statement), (yyvsp[-1].statement)); }
#line 2108 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 60: /* stmt_list: %empty  */
#line 360 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                            { (yyval.statement) = nullptr; }
#line 2114 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 61: /* stmt: INTEGER COLON non_label_stmt  */
#line 364 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.statement) = new Statement((yyvsp[0].non_label_stmt), (yyvsp[-2].int_value)); }
#line 2120 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 62: /* stmt: non_label_stmt  */
#line 365 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.statement) = new Statement((yyvsp[0].non_label_stmt), -1); }
#line 2126 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 63: /* non_label_stmt: assign_stmt  */
#line 369 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    { 
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::ASSIGN;
                        (yyval.non_label_stmt)->statement.assign_statement = (yyvsp[0].assign_stmt); 
                    }
#line 2136 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 64: /* non_label_stmt: proc_stmt  */
#line 374 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    { 
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::PROC;
                        (yyval.non_label_stmt)->statement.proc_statement = (yyvsp[0].proc_stmt); 
                    }
#line 2146 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 65: /* non_label_stmt: compound_stmt  */
#line 379 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    { 
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::COMPOUND;
                        (yyval.non_label_stmt)->statement.compound_statement = (yyvsp[0].compound_stmt); 
                    }
#line 2156 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 66: /* non_label_stmt: if_stmt  */
#line 384 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    { 
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::IF;
                        (yyval.non_label_stmt)->statement.if_statement = (yyvsp[0].if_stmt); 
                    }
#line 2166 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 67: /* non_label_stmt: repeat_stmt  */
#line 389 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    {   
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::REPEAT;
                        (yyval.non_label_stmt)->statement.repeat_statement = (yyvsp[0].repeat_stmt);  
                    }
#line 2176 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 68: /* non_label_stmt: while_stmt  */
#line 394 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    {   
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::WHILE;
                        (yyval.non_label_stmt)->statement.while_statement = (yyvsp[0].while_stmt); 
                    }
#line 2186 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 69: /* non_label_stmt: for_stmt  */
#line 399 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    {   
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::FOR;
                        (yyval.non_label_stmt)->statement.for_statment = (yyvsp[0].for_stmt); 
                    }
#line 2196 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 70: /* non_label_stmt: case_stmt  */
#line 404 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    {   
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::CASE;
                        (yyval.non_label_stmt)->statement.case_statement = (yyvsp[0].case_stmt);  
                    }
#line 2206 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 71: /* non_label_stmt: goto_stmt  */
#line 409 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                    {   
                        (yyval.non_label_stmt) = new NonLabelStatement();
                        (yyval.non_label_stmt)->flag = NonLabelStatement::GOTO;
                        (yyval.non_label_stmt)->statement.goto_statement = (yyvsp[0].goto_stmt); 
                    }
#line 2216 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 72: /* assign_stmt: name ASSIGN expression  */
#line 417 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    {
                                                        (yyval.assign_stmt) = new AssignStatement();
                                                        (yyval.assign_stmt)->flag = AssignStatement::NORMAL;
                                                        (yyval.assign_stmt)->assign.normal_assign = new NormalAssignment((yyvsp[-2].identifier), (yyvsp[0].expression));
                                                    }
#line 2226 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 73: /* assign_stmt: name LB expression RB ASSIGN expression  */
#line 422 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { 
                                                        (yyval.assign_stmt) = new AssignStatement();
                                                        (yyval.assign_stmt)->flag = AssignStatement::ARRAY;
                                                        (yyval.assign_stmt)->assign.array_assign = new ArrayAssignment((yyvsp[-5].identifier), (yyvsp[-3].expression), (yyvsp[0].expression));
                                                    }
#line 2236 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 74: /* assign_stmt: name DOT name ASSIGN expression  */
#line 427 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { 
                                                        (yyval.assign_stmt) = new AssignStatement();
                                                        (yyval.assign_stmt)->flag = AssignStatement::RECORD;
                                                        (yyval.assign_stmt)->assign.record_assign = new RecordAssignment((yyvsp[-4].identifier), (yyvsp[-2].identifier), (yyvsp[0].expression));
                                                    }
#line 2246 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 75: /* proc_stmt: name  */
#line 435 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { 
                                                (yyval.proc_stmt) = new ProcStatement();
                                                (yyval.proc_stmt)->flag = ProcStatement::PROC;
                                                (yyval.proc_stmt)->proc.normal_proc = new Procedure((yyvsp[0].identifier), nullptr);
                                            }
#line 2256 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 76: /* proc_stmt: name LP args_list RP  */
#line 440 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            {   
                                                (yyval.proc_stmt) = new ProcStatement();
                                                (yyval.proc_stmt)->flag = ProcStatement::PROC;
                                                (yyval.proc_stmt)->proc.normal_proc = new Procedure((yyvsp[-3].identifier), (yyvsp[-1].expression));
                                            }
#line 2266 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 77: /* proc_stmt: SYS_PROC  */
#line 445 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            {
                                                (yyval.proc_stmt) = new ProcStatement();
                                                (yyval.proc_stmt)->flag = ProcStatement::SYS_PROC;
                                                if (!strcmp((yyvsp[0].str_value), "write")){
                                                    (yyval.proc_stmt)->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITE, nullptr);
                                                }
                                                else if(!strcmp((yyvsp[0].str_value), "writeln")){
                                                    (yyval.proc_stmt)->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITELN, nullptr); 
                                                }
                                                else{
                                                    yyerror((yyvsp[0].str_value));
                                                }
                                            }
#line 2284 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 78: /* proc_stmt: SYS_PROC LP expression_list RP  */
#line 458 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { 
                                                (yyval.proc_stmt) = new ProcStatement();
                                                (yyval.proc_stmt)->flag = ProcStatement::SYS_PROC;
                                                if (!strcmp((yyvsp[-3].str_value), "write")){
                                                    (yyval.proc_stmt)->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITE, (yyvsp[-1].expression));
                                                }
                                                else if(!strcmp((yyvsp[-3].str_value), "writeln")){
                                                    (yyval.proc_stmt)->proc.sys_proc = new SystemProcedure(Sys_Proc::WRITELN, (yyvsp[-1].expression)); 
                                                }
                                                else{
                                                    yyerror((yyvsp[-3].str_value));
                                                }
                                            }
#line 2302 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 79: /* proc_stmt: READ LP factor RP  */
#line 471 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                            { 
                                                (yyval.proc_stmt) = new ProcStatement();
                                                (yyval.proc_stmt)->flag = ProcStatement::READ_PROC;
                                                (yyval.proc_stmt)->proc.read_proc = new ReadProcedure((yyvsp[-1].factor)); 
                                            }
#line 2312 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 80: /* if_stmt: IF expression THEN stmt else_clause ENDIF  */
#line 478 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                         { (yyval.if_stmt) = new IfStatement((yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[-1].statement)); }
#line 2318 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 81: /* else_clause: ELSE stmt  */
#line 482 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.statement) = (yyvsp[0].statement); }
#line 2324 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 82: /* else_clause: %empty  */
#line 483 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.statement) = nullptr; }
#line 2330 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 83: /* repeat_stmt: REPEAT stmt_list UNTIL expression  */
#line 486 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.repeat_stmt) = new RepeatStatement((yyvsp[-2].statement), (yyvsp[0].expression)); }
#line 2336 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 84: /* while_stmt: WHILE expression DO stmt  */
#line 489 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.while_stmt) = new WhileStatement((yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 2342 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 85: /* for_stmt: FOR name ASSIGN expression direction expression DO stmt  */
#line 493 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                                    { (yyval.for_stmt) = new ForStatement((yyvsp[-6].identifier), (yyvsp[-4].expression), (yyvsp[-3].direction), (yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 2348 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 86: /* direction: TO  */
#line 497 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                { (yyval.direction) = ForStatement::For_Type::TO; }
#line 2354 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 87: /* direction: DOWNTO  */
#line 498 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                { (yyval.direction) = ForStatement::For_Type::DOWNTO; }
#line 2360 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 88: /* case_stmt: CASE expression OF case_expr_list END  */
#line 501 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.case_stmt) = new CaseStatement((yyvsp[-3].expression), (yyvsp[-1].case_expr));}
#line 2366 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 89: /* case_expr_list: case_expr_list case_expr  */
#line 505 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.case_expr) = AddElement<CaseExpression>((yyvsp[-1].case_expr), (yyvsp[0].case_expr)); }
#line 2372 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 90: /* case_expr_list: case_expr  */
#line 506 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.case_expr) = (yyvsp[0].case_expr); }
#line 2378 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 91: /* case_expr: const_value COLON stmt SEMI  */
#line 510 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.case_expr) = new CaseExpression(nullptr, (yyvsp[-3].const_value), (yyvsp[-1].statement), CaseExpression::Type::CONST_CASE); }
#line 2384 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 92: /* case_expr: name COLON stmt SEMI  */
#line 511 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.case_expr) = new CaseExpression((yyvsp[-3].identifier), nullptr, (yyvsp[-1].statement), CaseExpression::Type::ID_CASE); }
#line 2390 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 93: /* goto_stmt: GOTO INTEGER  */
#line 514 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                                    { (yyval.goto_stmt) = new GotoStatement((yyvsp[0].int_value)); }
#line 2396 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 94: /* expression_list: expression_list COMMA expression  */
#line 518 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.expression) = AddElement<Expression>((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2402 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 95: /* expression_list: expression  */
#line 519 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2408 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 96: /* expression: expression GE expr  */
#line 523 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = new Expression((yyvsp[-2].expression), (yyvsp[0].expr), Expression::Type::GE); }
#line 2414 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 97: /* expression: expression GT expr  */
#line 524 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = new Expression((yyvsp[-2].expression), (yyvsp[0].expr), Expression::Type::GT); }
#line 2420 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 98: /* expression: expression LE expr  */
#line 525 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = new Expression((yyvsp[-2].expression), (yyvsp[0].expr), Expression::Type::LE); }
#line 2426 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 99: /* expression: expression LT expr  */
#line 526 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = new Expression((yyvsp[-2].expression), (yyvsp[0].expr), Expression::Type::LT); }
#line 2432 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 100: /* expression: expression EQUAL expr  */
#line 527 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = new Expression((yyvsp[-2].expression), (yyvsp[0].expr), Expression::Type::EQUAL); }
#line 2438 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 101: /* expression: expression UNEQUAL expr  */
#line 528 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = new Expression((yyvsp[-2].expression), (yyvsp[0].expr), Expression::Type::UNEQUAL); }
#line 2444 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 102: /* expression: expr  */
#line 529 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = new Expression(nullptr, (yyvsp[0].expr), Expression::Type::SINGLE); }
#line 2450 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 103: /* expr: expr PLUS term  */
#line 533 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expr) = new Expr((yyvsp[-2].expr), (yyvsp[0].term), Expr::PLUS); }
#line 2456 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 104: /* expr: expr MINUS term  */
#line 534 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expr) = new Expr((yyvsp[-2].expr), (yyvsp[0].term), Expr::MINUS); }
#line 2462 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 105: /* expr: expr OR term  */
#line 535 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expr) = new Expr((yyvsp[-2].expr), (yyvsp[0].term), Expr::OR); }
#line 2468 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 106: /* expr: term  */
#line 536 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expr) = new Expr(nullptr, (yyvsp[0].term), Expr::SINGLE); }
#line 2474 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 107: /* term: term MUL factor  */
#line 540 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.term) = new Term((yyvsp[-2].term), (yyvsp[0].factor), Term::MUL); }
#line 2480 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 108: /* term: term DIV factor  */
#line 541 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.term) = new Term((yyvsp[-2].term), (yyvsp[0].factor), Term::DIV); }
#line 2486 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 109: /* term: term MOD factor  */
#line 542 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.term) = new Term((yyvsp[-2].term), (yyvsp[0].factor), Term::MOD); }
#line 2492 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 110: /* term: term AND factor  */
#line 543 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.term) = new Term((yyvsp[-2].term), (yyvsp[0].factor), Term::AND); }
#line 2498 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 111: /* term: factor  */
#line 544 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                { (yyval.term) = new Term(nullptr, (yyvsp[0].factor), Term::SINGLE); }
#line 2504 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 112: /* factor: name  */
#line 548 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.factor) = new Factor(); (yyval.factor)->factor.name_factor = (yyvsp[0].identifier); (yyval.factor)->flag = Factor::NAME; }
#line 2510 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 113: /* factor: name LP args_list RP  */
#line 549 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.factor) = new Factor(); (yyval.factor)->factor.func_factor = new FunctionCall((yyvsp[-3].identifier), (yyvsp[-1].expression)); (yyval.factor)->flag = Factor::FUNC; }
#line 2516 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 114: /* factor: SYS_FUNCT  */
#line 550 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        {
                                            (yyval.factor) = new Factor(); 
                                            (yyval.factor)->flag = Factor::SYS_FUNC;
                                            if(!strcmp((yyvsp[0].str_value), "abs")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ABS, nullptr); 
                                            }
                                            else if(!strcmp((yyvsp[0].str_value), "chr")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::CHR, nullptr); 
                                            }
                                            else if(!strcmp((yyvsp[0].str_value), "odd")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ODD, nullptr); 
                                            }
                                            else if(!strcmp((yyvsp[0].str_value), "ord")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ORD, nullptr); 
                                            }
                                            else if(!strcmp((yyvsp[0].str_value), "pred")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::PRED, nullptr); 
                                            }
                                            else if(!strcmp((yyvsp[0].str_value), "sqr")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQR, nullptr);  
                                            }
                                            else if(!strcmp((yyvsp[0].str_value), "sqrt")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQRT, nullptr); 
                                            }
                                            else if(!strcmp((yyvsp[0].str_value), "succ")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SUCC, nullptr); 
                                            }
                                            else{
                                                yyerror((yyvsp[0].str_value));
                                            }
                                        }
#line 2552 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 115: /* factor: SYS_FUNCT LP args_list RP  */
#line 581 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { 
                                            (yyval.factor) = new Factor(); 
                                            (yyval.factor)->flag = Factor::SYS_FUNC;
                                            if(!strcmp((yyvsp[-3].str_value), "abs")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ABS, (yyvsp[-1].expression)); 
                                            }
                                            else if(!strcmp((yyvsp[-3].str_value), "chr")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::CHR, (yyvsp[-1].expression)); 
                                            }
                                            else if(!strcmp((yyvsp[-3].str_value), "odd")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ODD, (yyvsp[-1].expression)); 
                                            }
                                            else if(!strcmp((yyvsp[-3].str_value), "ord")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::ORD, (yyvsp[-1].expression)); 
                                            }
                                            else if(!strcmp((yyvsp[-3].str_value), "pred")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::PRED, (yyvsp[-1].expression)); 
                                            }
                                            else if(!strcmp((yyvsp[-3].str_value), "sqr")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQR, (yyvsp[-1].expression));  
                                            }
                                            else if(!strcmp((yyvsp[-3].str_value), "sqrt")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SQRT, (yyvsp[-1].expression)); 
                                            }
                                            else if(!strcmp((yyvsp[-3].str_value), "succ")){
                                                (yyval.factor)->factor.sys_func_factor = new SysFuncCall(Sys_Funct::SUCC, (yyvsp[-1].expression)); 
                                            }
                                            else{
                                                yyerror((yyvsp[-3].str_value));
                                            }
                                        }
#line 2588 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 116: /* factor: const_value  */
#line 612 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.factor) = new Factor(); (yyval.factor)->factor.const_factor = (yyvsp[0].const_value); (yyval.factor)->flag = Factor::CONST; }
#line 2594 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 117: /* factor: LP expression RP  */
#line 613 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.factor) = new Factor(); (yyval.factor)->factor.expr_factor = (yyvsp[-1].expression); (yyval.factor)->flag = Factor::EXPR; }
#line 2600 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 118: /* factor: NOT factor  */
#line 614 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.factor) = new Factor(); (yyval.factor)->factor.not_factor = new NotFactor((yyvsp[0].factor)); (yyval.factor)->flag = Factor::NOT; }
#line 2606 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 119: /* factor: MINUS factor  */
#line 615 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { (yyval.factor) = new Factor(); (yyval.factor)->factor.minus_factor = new MinusFactor((yyvsp[0].factor)); (yyval.factor)->flag = Factor::MINUS; }
#line 2612 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 120: /* factor: name LB expression RB  */
#line 616 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { 
                                            (yyval.factor) = new Factor(); 
                                            (yyval.factor)->factor.at_factor = new AtOperation((yyvsp[-3].identifier), (yyvsp[-1].expression));
                                            (yyval.factor)->flag = Factor::AT; 
                                        }
#line 2622 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 121: /* factor: name DOT name  */
#line 621 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                        { 
                                            (yyval.factor) = new Factor(); 
                                            (yyval.factor)->factor.get_factor = new GetOperation((yyvsp[-2].identifier), (yyvsp[0].identifier)); 
                                            (yyval.factor)->flag = Factor::GET; 
                                        }
#line 2632 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 122: /* args_list: args_list COMMA expression  */
#line 629 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = AddElement<Expression>((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2638 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 123: /* args_list: expression  */
#line 630 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2644 "/home/freesia/spl_run/src/parser.cpp"
    break;

  case 124: /* name: IDENTIFIER  */
#line 634 "/home/freesia/spl_run/parser/SyntaxAnalysis.y"
                { 
                    (yyval.identifier) = new Identifier(); 
                    strcpy((yyval.identifier)->buffer, (yyvsp[0].str_value));
                }
#line 2653 "/home/freesia/spl_run/src/parser.cpp"
    break;


#line 2657 "/home/freesia/spl_run/src/parser.cpp"

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

