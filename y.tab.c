
/*  A Bison parser, made from compiler.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	IDENTIFIER	257
#define	CONSTANT	258
#define	STRING_LITERAL	259
#define	SIZEOF	260
#define	CONSTANT_INT	261
#define	CONSTANT_DOUBLE	262
#define	PTR_OP	263
#define	INC_OP	264
#define	DEC_OP	265
#define	LEFT_OP	266
#define	RIGHT_OP	267
#define	LE_OP	268
#define	GE_OP	269
#define	EQ_OP	270
#define	NE_OP	271
#define	AND_OP	272
#define	OR_OP	273
#define	MUL_ASSIGN	274
#define	DIV_ASSIGN	275
#define	MOD_ASSIGN	276
#define	ADD_ASSIGN	277
#define	SUB_ASSIGN	278
#define	LEFT_ASSIGN	279
#define	RIGHT_ASSIGN	280
#define	AND_ASSIGN	281
#define	XOR_ASSIGN	282
#define	OR_ASSIGN	283
#define	TYPE_NAME	284
#define	CHAR	285
#define	INT	286
#define	DOUBLE	287
#define	VOID	288
#define	BOOL	289
#define	CASE	290
#define	IF	291
#define	ELSE	292
#define	SWITCH	293
#define	WHILE	294
#define	DO	295
#define	FOR	296
#define	GOTO	297
#define	CONTINUE	298
#define	BREAK	299
#define	RETURN	300
#define	TRUE	301
#define	FALSE	302
#define	LOWER_THAN_ELSE	303

#line 1 "compiler.y"

#include <cstdlib>
#include <cstdio>
#include <string>
#include "tree.h"
#include "block.h"
#include "Praser.h"
using namespace std;

extern char *yytext;
extern int column;
extern FILE * yyin;
extern FILE * yyout;
gramTree *root;
extern int yylineno;

int yylex(void);
void yyerror(const char*); 

#line 21 "compiler.y"
typedef union{
	struct gramTree* gt;
} YYSTYPE;
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		269
#define	YYFLAG		-32768
#define	YYNTBASE	74

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 120)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    57,     2,     2,     2,    63,    56,     2,    71,
    72,    61,    60,    50,    59,    55,    62,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    51,    49,    64,
    52,    65,    68,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    53,     2,    54,    66,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    69,    67,    70,    58,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    73
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,     8,    10,    12,    16,    18,    23,
    27,    32,    35,    38,    40,    44,    46,    49,    52,    55,
    57,    59,    61,    63,    65,    69,    73,    77,    79,    83,
    87,    89,    93,    97,    99,   103,   107,   111,   115,   117,
   121,   125,   127,   131,   133,   137,   139,   143,   145,   149,
   151,   155,   157,   161,   163,   165,   167,   169,   171,   173,
   175,   177,   179,   181,   183,   185,   189,   192,   196,   198,
   202,   204,   208,   210,   212,   214,   216,   218,   220,   224,
   229,   234,   238,   243,   248,   252,   254,   258,   261,   264,
   266,   268,   272,   276,   279,   283,   287,   292,   296,   301,
   304,   308,   312,   317,   319,   323,   328,   330,   333,   337,
   342,   345,   347,   350,   354,   357,   359,   361,   363,   365,
   367,   369,   373,   378,   381,   385,   387,   390,   392,   394,
   396,   399,   405,   413,   419,   425,   433,   440,   448,   455,
   463,   467,   470,   473,   476,   480,   482,   485,   487,   489,
   494,   498,   500
};

static const short yyrhs[] = {   116,
     0,     3,     0,    47,     0,    48,     0,     7,     0,     8,
     0,    71,    92,    72,     0,    75,     0,    76,    53,    92,
    54,     0,    76,    71,    72,     0,    76,    71,    77,    72,
     0,    76,    10,     0,    76,    11,     0,    90,     0,    77,
    50,    90,     0,    76,     0,    10,    78,     0,    11,    78,
     0,    79,    78,     0,    60,     0,    59,     0,    58,     0,
    57,     0,    78,     0,    80,    61,    78,     0,    80,    62,
    78,     0,    80,    63,    78,     0,    80,     0,    81,    60,
    80,     0,    81,    59,    80,     0,    81,     0,    82,    12,
    81,     0,    82,    13,    81,     0,    82,     0,    83,    64,
    82,     0,    83,    65,    82,     0,    83,    14,    82,     0,
    83,    15,    82,     0,    83,     0,    84,    16,    83,     0,
    84,    17,    83,     0,    84,     0,    85,    56,    84,     0,
    85,     0,    86,    66,    85,     0,    86,     0,    87,    67,
    86,     0,    87,     0,    88,    18,    87,     0,    88,     0,
    89,    19,    88,     0,    89,     0,    78,    91,    90,     0,
    52,     0,    20,     0,    21,     0,    22,     0,    23,     0,
    24,     0,    25,     0,    26,     0,    27,     0,    28,     0,
    29,     0,    90,     0,    92,    50,    90,     0,    96,    49,
     0,    96,    94,    49,     0,    95,     0,    94,    50,    95,
     0,    97,     0,    97,    52,   102,     0,    34,     0,    31,
     0,    32,     0,    33,     0,    35,     0,     3,     0,    71,
    97,    72,     0,    97,    53,    90,    54,     0,    97,    53,
    61,    54,     0,    97,    53,    54,     0,    97,    71,    98,
    72,     0,    97,    71,   100,    72,     0,    97,    71,    72,
     0,    99,     0,    98,    50,    99,     0,    96,    97,     0,
    96,   101,     0,    96,     0,     3,     0,   100,    50,     3,
     0,    71,   101,    72,     0,    53,    54,     0,    53,    90,
    54,     0,   101,    53,    54,     0,   101,    53,    90,    54,
     0,    53,    61,    54,     0,   101,    53,    61,    54,     0,
    71,    72,     0,    71,    98,    72,     0,   101,    71,    72,
     0,   101,    71,    98,    72,     0,    90,     0,    69,   103,
    70,     0,    69,   103,    50,    70,     0,   102,     0,   104,
   102,     0,   103,    50,   102,     0,   103,    50,   104,   102,
     0,   105,    52,     0,   106,     0,   105,   106,     0,    53,
    89,    54,     0,    55,     3,     0,   108,     0,   109,     0,
   112,     0,   113,     0,   114,     0,   115,     0,     3,    51,
   107,     0,    36,    89,    51,   107,     0,    69,    70,     0,
    69,   110,    70,     0,   111,     0,   110,   111,     0,    93,
     0,   107,     0,    49,     0,    92,    49,     0,    37,    71,
    92,    72,   107,     0,    37,    71,    92,    72,   107,    38,
   107,     0,    39,    71,    92,    72,   107,     0,    40,    71,
    92,    72,   107,     0,    41,   107,    40,    71,    92,    72,
    49,     0,    42,    71,   112,   112,    72,   107,     0,    42,
    71,   112,   112,    92,    72,   107,     0,    42,    71,    93,
   112,    72,   107,     0,    42,    71,    93,   112,    92,    72,
   107,     0,    43,     3,    49,     0,    44,    49,     0,    45,
    49,     0,    46,    49,     0,    46,    92,    49,     0,   117,
     0,   116,   117,     0,   118,     0,    93,     0,    96,    97,
   119,   109,     0,    96,    97,   109,     0,    93,     0,   119,
    93,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    60,    67,    71,    77,    83,    90,    95,   101,   105,   109,
   113,   117,   121,   127,   131,   137,   142,   146,   150,   156,
   160,   163,   166,   172,   176,   179,   182,   188,   192,   195,
   201,   205,   209,   216,   220,   223,   226,   230,   237,   241,
   245,   251,   255,   261,   265,   271,   275,   281,   285,   292,
   296,   303,   308,   314,   318,   322,   326,   330,   334,   338,
   342,   346,   350,   354,   361,   366,   373,   377,   383,   387,
   392,   396,   403,   407,   410,   413,   416,   423,   428,   432,
   437,   441,   445,   449,   453,   461,   465,   470,   474,   477,
   482,   486,   491,   495,   498,   501,   504,   507,   510,   513,
   516,   519,   522,   528,   532,   536,   542,   546,   549,   552,
   557,   563,   567,   572,   576,   582,   586,   589,   592,   595,
   598,   604,   608,   614,   618,   623,   627,   632,   636,   641,
   645,   651,   655,   658,   664,   668,   671,   674,   677,   680,
   686,   690,   693,   696,   699,   704,   708,   713,   719,   726,
   730,   735,   739
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","IDENTIFIER",
"CONSTANT","STRING_LITERAL","SIZEOF","CONSTANT_INT","CONSTANT_DOUBLE","PTR_OP",
"INC_OP","DEC_OP","LEFT_OP","RIGHT_OP","LE_OP","GE_OP","EQ_OP","NE_OP","AND_OP",
"OR_OP","MUL_ASSIGN","DIV_ASSIGN","MOD_ASSIGN","ADD_ASSIGN","SUB_ASSIGN","LEFT_ASSIGN",
"RIGHT_ASSIGN","AND_ASSIGN","XOR_ASSIGN","OR_ASSIGN","TYPE_NAME","CHAR","INT",
"DOUBLE","VOID","BOOL","CASE","IF","ELSE","SWITCH","WHILE","DO","FOR","GOTO",
"CONTINUE","BREAK","RETURN","TRUE","FALSE","';'","','","':'","'='","'['","']'",
"'.'","'&'","'!'","'~'","'-'","'+'","'*'","'/'","'%'","'<'","'>'","'^'","'|'",
"'?'","'{'","'}'","'('","')'","LOWER_THAN_ELSE","Program","primary_expression",
"postfix_expression","argument_expression_list","unary_expression","unary_operator",
"multiplicative_expression","additive_expression","shift_expression","relational_expression",
"equality_expression","and_expression","exclusive_or_expression","inclusive_or_expression",
"logical_and_expression","logical_or_expression","assignment_expression","assignment_operator",
"expression","declaration","init_declarator_list","init_declarator","type_specifier",
"declarator","parameter_list","parameter_declaration","identifier_list","abstract_declarator",
"initializer","initializer_list","designation","designator_list","designator",
"statement","labeled_statement","compound_statement","block_item_list","block_item",
"expression_statement","selection_statement","iteration_statement","jump_statement",
"translation_unit","external_declaration","function_definition","declaration_list", NULL
};
#endif

static const short yyr1[] = {     0,
    74,    75,    75,    75,    75,    75,    75,    76,    76,    76,
    76,    76,    76,    77,    77,    78,    78,    78,    78,    79,
    79,    79,    79,    80,    80,    80,    80,    81,    81,    81,
    82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
    84,    85,    85,    86,    86,    87,    87,    88,    88,    89,
    89,    90,    90,    91,    91,    91,    91,    91,    91,    91,
    91,    91,    91,    91,    92,    92,    93,    93,    94,    94,
    95,    95,    96,    96,    96,    96,    96,    97,    97,    97,
    97,    97,    97,    97,    97,    98,    98,    99,    99,    99,
   100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
   101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
   104,   105,   105,   106,   106,   107,   107,   107,   107,   107,
   107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
   112,   113,   113,   113,   114,   114,   114,   114,   114,   114,
   115,   115,   115,   115,   115,   116,   116,   117,   117,   118,
   118,   119,   119
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     1,     1,     3,     1,     4,     3,
     4,     2,     2,     1,     3,     1,     2,     2,     2,     1,
     1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
     3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
     3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     3,     2,     3,     1,     3,
     1,     3,     1,     1,     1,     1,     1,     1,     3,     4,
     4,     3,     4,     4,     3,     1,     3,     2,     2,     1,
     1,     3,     3,     2,     3,     3,     4,     3,     4,     2,
     3,     3,     4,     1,     3,     4,     1,     2,     3,     4,
     2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
     1,     3,     4,     2,     3,     1,     2,     1,     1,     1,
     2,     5,     7,     5,     5,     7,     6,     7,     6,     7,
     3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
     3,     1,     2
};

static const short yydefact[] = {     0,
    74,    75,    76,    73,    77,   149,     0,     1,   146,   148,
    78,    67,     0,     0,    69,    71,   147,     0,    68,     0,
     0,     0,     0,     0,   152,     0,   151,     0,    79,    70,
    71,     2,     5,     6,     0,     0,     3,     4,    23,    22,
    21,    20,     0,     0,     8,    16,    24,     0,    28,    31,
    34,    39,    42,    44,    46,    48,    50,    52,   104,    72,
    82,     0,     0,     2,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   130,   124,    65,     0,   128,   129,
   116,   117,     0,   126,   118,   119,   120,   121,    91,    85,
    90,     0,    86,     0,   153,   150,    17,    18,     0,     0,
   107,     0,     0,     0,   112,     0,    12,    13,     0,     0,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    54,     0,    19,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    81,    80,     0,    24,     0,     0,     0,     0,     0,
     0,     0,   142,   143,   144,     0,   131,     0,   125,   127,
     0,     0,    88,    89,     0,    83,     0,    84,     0,   115,
     0,   105,   108,   111,   113,     7,     0,    10,     0,    14,
    53,    25,    26,    27,    30,    29,    32,    33,    37,    38,
    35,    36,    40,    41,    43,    45,    47,    49,    51,   122,
     0,     0,     0,     0,     0,     0,     0,   141,   145,    66,
    94,     0,     0,   100,     0,     0,     0,     0,    87,    92,
   114,   106,   109,     0,     9,     0,    11,   123,     0,     0,
     0,     0,     0,     0,    98,    95,   101,    93,    96,     0,
     0,   102,     0,   110,    15,   132,   134,   135,     0,     0,
     0,     0,     0,    99,    97,   103,     0,     0,   139,     0,
   137,     0,   133,   136,   140,   138,     0,     0,     0
};

static const short yydefgoto[] = {   267,
    45,    46,   179,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    77,   122,    78,     6,    14,
    15,    26,    18,    92,    93,    94,   164,    60,   102,   103,
   104,   105,    80,    81,    82,    83,    84,    85,    86,    87,
    88,     8,     9,    10,    28
};

static const short yypact[] = {   291,
-32768,-32768,-32768,-32768,-32768,-32768,     3,   291,-32768,-32768,
-32768,-32768,    15,    13,-32768,   425,-32768,   159,-32768,    15,
   566,   477,   235,    12,-32768,     3,-32768,    24,-32768,-32768,
    23,-32768,-32768,-32768,   631,   631,-32768,-32768,-32768,-32768,
-32768,-32768,   461,   631,-32768,    17,   233,   631,   202,    74,
   220,    39,   127,   -36,   -30,    14,    55,    58,-32768,-32768,
-32768,    38,    47,    54,   631,    66,    87,   104,   365,   107,
   126,   100,   114,   241,-32768,-32768,-32768,   237,-32768,-32768,
-32768,-32768,   300,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    16,    59,-32768,    78,-32768,-32768,-32768,-32768,   631,   179,
-32768,    30,   566,   326,-32768,    80,-32768,-32768,   631,    88,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   631,-32768,   631,   631,   631,   631,   631,   631,   631,
   631,   631,   631,   631,   631,   631,   631,   631,   631,   631,
   631,-32768,-32768,   365,-32768,    10,   631,   631,   631,   144,
   384,   140,-32768,-32768,-32768,   247,-32768,   631,-32768,-32768,
   536,     7,   -23,    18,   291,-32768,   193,-32768,    -5,-32768,
   442,-32768,-32768,-32768,-32768,-32768,   -19,-32768,    92,-32768,
-32768,-32768,-32768,-32768,   202,   202,    74,    74,   220,   220,
   220,   220,    39,    39,   127,   -36,   -30,    14,    55,-32768,
   365,   111,   131,   136,   128,   306,   306,-32768,-32768,-32768,
-32768,   147,   151,-32768,   137,   249,   551,   122,-32768,-32768,
-32768,-32768,-32768,   566,-32768,   631,-32768,-32768,   365,   365,
   365,   631,   163,   169,-32768,-32768,-32768,-32768,-32768,   153,
   185,-32768,   152,-32768,-32768,   181,-32768,-32768,   164,   365,
   165,   365,   175,-32768,-32768,-32768,   365,   201,-32768,   365,
-32768,   365,-32768,-32768,-32768,-32768,   213,   273,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,   -14,-32768,   191,   221,   196,   226,   154,
   177,   199,   212,   215,   -49,   -20,-32768,   -41,   -11,-32768,
   347,     0,     6,  -153,   209,-32768,   218,   -39,-32768,   211,
-32768,   279,   -62,-32768,     9,-32768,   301,  -140,-32768,-32768,
-32768,-32768,   377,-32768,-32768
};


#define	YYLAST		702


static const short yytable[] = {     7,
    59,    63,   106,   101,    25,    11,   150,     7,   215,    11,
   207,    79,    16,   141,    89,   146,    95,    11,    11,   137,
    97,    98,    59,    91,    27,    31,   107,   108,   141,    22,
   158,    31,   156,   123,   225,   138,    96,     1,     2,     3,
     4,     5,     1,     2,     3,     4,     5,    24,   221,   169,
   145,    12,   131,   132,     1,     2,     3,     4,     5,   161,
   201,    19,    20,   173,   243,   233,   234,   177,   161,   109,
   217,    79,   140,    13,    21,    22,   141,   162,   214,   171,
   139,   200,    59,    90,   145,    13,   162,   110,   218,   180,
    32,   142,    23,    24,    33,    34,   163,    35,    36,   172,
   143,   181,   133,   134,   144,   202,   203,   204,   165,   182,
   183,   184,   145,   145,   145,   145,   145,   145,   145,   145,
   145,   145,   145,   145,   145,   145,   145,   167,   152,   158,
   166,   223,   127,   128,    37,    38,   147,   210,   228,   206,
   213,   226,   135,   136,    39,    40,    41,    42,   153,   168,
    59,   176,     1,     2,     3,     4,     5,   148,    44,   178,
   158,    91,   154,   227,    91,    32,   246,   247,   248,    33,
    34,    32,    35,    36,   149,    33,    34,   151,    35,    36,
   158,   170,   229,   205,   244,   158,   165,   259,   208,   261,
   249,   251,   253,   242,   263,   220,   241,   265,   232,   266,
   235,   165,   230,    59,   236,   245,   254,   231,   237,    37,
    38,    22,   268,   158,   158,    37,    38,    91,   257,    39,
    40,    41,    42,   256,   158,    39,    40,    41,    42,    24,
    29,   129,   130,    44,   250,   258,   260,    64,   255,    44,
   252,    33,    34,    32,    35,    36,   262,    33,    34,   264,
    35,    36,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   124,   125,   126,     1,     2,     3,     4,     5,
    65,    66,   269,    67,    68,    69,    70,    71,    72,    73,
    74,    37,    38,    75,   121,   157,   158,    37,    38,   155,
   195,    39,    40,    41,    42,   209,   158,    39,    40,    41,
    42,   217,    64,    23,    76,    44,    33,    34,    32,    35,
    36,    44,    33,    34,   196,    35,    36,   185,   186,   218,
   238,     1,     2,     3,     4,     5,   189,   190,   191,   192,
     1,     2,     3,     4,     5,    65,    66,   197,    67,    68,
    69,    70,    71,    72,    73,    74,    37,    38,    75,   187,
   188,   198,    37,    38,    75,   199,    39,    40,    41,    42,
   193,   194,    39,    40,    41,    42,    30,    64,    23,   159,
    44,    33,    34,   219,    35,    36,    44,   174,    99,   216,
   100,   224,   175,   160,    17,     0,    32,     0,     0,     0,
    33,    34,     0,    35,    36,     0,     0,     0,     0,     0,
    65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
    74,    37,    38,    75,     1,     2,     3,     4,     5,     0,
     0,    39,    40,    41,    42,     0,     0,     0,     0,     0,
    37,    38,    75,    23,     0,    44,     0,     0,     0,     0,
    39,    40,    41,    42,    32,     0,     0,     0,    33,    34,
     0,    35,    36,     0,    44,     1,     2,     3,     4,     5,
     0,     0,     0,    32,     0,     0,     0,    33,    34,     0,
    35,    36,     0,     0,     0,     0,    21,    22,     0,    32,
     0,     0,     0,    33,    34,     0,    35,    36,    37,    38,
     0,     0,     0,    23,    99,    24,   100,     0,    39,    40,
    41,    42,     0,     0,     0,     0,     0,    37,    38,     0,
    43,   222,    44,    99,     0,   100,     0,    39,    40,    41,
    42,     0,     0,    37,    38,     0,     0,     0,     0,    43,
    61,    44,     0,    39,    40,    41,    42,    62,    32,     0,
     0,     0,    33,    34,     0,    35,    36,    44,     0,     0,
     0,     0,     0,    32,     0,     0,     0,    33,    34,     0,
    35,    36,     0,     0,     0,     0,     0,     0,    32,     0,
     0,     0,    33,    34,     0,    35,    36,     0,     0,     0,
     0,     0,    37,    38,     0,     0,     0,     0,     0,   211,
     0,     0,    39,    40,    41,    42,   212,    37,    38,     0,
     0,     0,     0,     0,   239,     0,    44,    39,    40,    41,
    42,   240,    37,    38,     0,     0,     0,     0,     0,     0,
     0,    44,    39,    40,    41,    42,     0,     0,     0,     0,
     0,     0,     0,    32,    43,     0,    44,    33,    34,     0,
    35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    37,    38,     0,
     0,     0,     0,     0,     0,     0,     0,    39,    40,    41,
    42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    44
};

static const short yycheck[] = {     0,
    21,    22,    44,    43,    16,     3,    69,     8,   162,     3,
   151,    23,     7,    19,     3,    65,    28,     3,     3,    56,
    35,    36,    43,    24,    16,    20,    10,    11,    19,    53,
    50,    26,    74,    48,    54,    66,    28,    31,    32,    33,
    34,    35,    31,    32,    33,    34,    35,    71,    54,    99,
    65,    49,    14,    15,    31,    32,    33,    34,    35,    53,
    51,    49,    50,   103,   218,   206,   207,   109,    53,    53,
    53,    83,    18,    71,    52,    53,    19,    71,    72,    50,
    67,   144,   103,    72,    99,    71,    71,    71,    71,   110,
     3,    54,    69,    71,     7,     8,    91,    10,    11,    70,
    54,   122,    64,    65,    51,   147,   148,   149,    50,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,    50,     3,    50,
    72,   171,    59,    60,    47,    48,    71,   158,   201,   151,
   161,    50,    16,    17,    57,    58,    59,    60,    49,    72,
   171,    72,    31,    32,    33,    34,    35,    71,    71,    72,
    50,   162,    49,    72,   165,     3,   229,   230,   231,     7,
     8,     3,    10,    11,    71,     7,     8,    71,    10,    11,
    50,     3,    72,    40,   224,    50,    50,   250,    49,   252,
   232,   233,   234,    72,   257,     3,   217,   260,    71,   262,
    54,    50,    72,   224,    54,   226,    54,    72,    72,    47,
    48,    53,     0,    50,    50,    47,    48,   218,    38,    57,
    58,    59,    60,    72,    50,    57,    58,    59,    60,    71,
    72,    12,    13,    71,    72,    72,    72,     3,    54,    71,
    72,     7,     8,     3,    10,    11,    72,     7,     8,    49,
    10,    11,    20,    21,    22,    23,    24,    25,    26,    27,
    28,    29,    61,    62,    63,    31,    32,    33,    34,    35,
    36,    37,     0,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    52,    49,    50,    47,    48,    49,
   137,    57,    58,    59,    60,    49,    50,    57,    58,    59,
    60,    53,     3,    69,    70,    71,     7,     8,     3,    10,
    11,    71,     7,     8,   138,    10,    11,   127,   128,    71,
    72,    31,    32,    33,    34,    35,   131,   132,   133,   134,
    31,    32,    33,    34,    35,    36,    37,   139,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,   129,
   130,   140,    47,    48,    49,   141,    57,    58,    59,    60,
   135,   136,    57,    58,    59,    60,    20,     3,    69,    70,
    71,     7,     8,   165,    10,    11,    71,    52,    53,   162,
    55,   171,   104,    83,     8,    -1,     3,    -1,    -1,    -1,
     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
    36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    31,    32,    33,    34,    35,    -1,
    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
    47,    48,    49,    69,    -1,    71,    -1,    -1,    -1,    -1,
    57,    58,    59,    60,     3,    -1,    -1,    -1,     7,     8,
    -1,    10,    11,    -1,    71,    31,    32,    33,    34,    35,
    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,    -1,
    10,    11,    -1,    -1,    -1,    -1,    52,    53,    -1,     3,
    -1,    -1,    -1,     7,     8,    -1,    10,    11,    47,    48,
    -1,    -1,    -1,    69,    53,    71,    55,    -1,    57,    58,
    59,    60,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
    69,    70,    71,    53,    -1,    55,    -1,    57,    58,    59,
    60,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    69,
    54,    71,    -1,    57,    58,    59,    60,    61,     3,    -1,
    -1,    -1,     7,     8,    -1,    10,    11,    71,    -1,    -1,
    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,    -1,
    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
    -1,    -1,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    54,
    -1,    -1,    57,    58,    59,    60,    61,    47,    48,    -1,
    -1,    -1,    -1,    -1,    54,    -1,    71,    57,    58,    59,
    60,    61,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    71,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,     3,    69,    -1,    71,     7,     8,    -1,
    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    71
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 61 "compiler.y"
{
		root = create_tree("Program",1,yyvsp[0].gt);
	;
    break;}
case 2:
#line 68 "compiler.y"
{
		yyval.gt = create_tree("primary_expression",1,yyvsp[0].gt);
	;
    break;}
case 3:
#line 72 "compiler.y"
{
		yyval.gt = create_tree("primary_expression",1,yyvsp[0].gt);
		yyval.gt->type = "bool";
		yyval.gt->int_value = yyvsp[0].gt->int_value;
	;
    break;}
case 4:
#line 78 "compiler.y"
{
		yyval.gt = create_tree("primary_expression",1,yyvsp[0].gt);
		yyval.gt->type = "bool";
		yyval.gt->int_value = yyvsp[0].gt->int_value;
	;
    break;}
case 5:
#line 83 "compiler.y"
{
		//printf("%d",$1->int_value);
		yyval.gt = create_tree("primary_expression",1,yyvsp[0].gt);
		yyval.gt->type = "int";
		yyval.gt->int_value = yyvsp[0].gt->int_value;
		
	;
    break;}
case 6:
#line 90 "compiler.y"
{
		yyval.gt = create_tree("primary_expression",1,yyvsp[0].gt);
		yyval.gt->type = "double";
		yyval.gt->double_value = yyvsp[0].gt->double_value;
	;
    break;}
case 7:
#line 95 "compiler.y"
{
		yyval.gt = create_tree("primary_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 8:
#line 102 "compiler.y"
{
		yyval.gt = create_tree("postfix_expression",1,yyvsp[0].gt);
	;
    break;}
case 9:
#line 105 "compiler.y"
{
		yyval.gt = create_tree("postfix_expression",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
		//数组调用
	;
    break;}
case 10:
#line 109 "compiler.y"
{
		yyval.gt = create_tree("postfix_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
		//函数调用
	;
    break;}
case 11:
#line 113 "compiler.y"
{
		yyval.gt = create_tree("postfix_expression",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
		//函数调用
	;
    break;}
case 12:
#line 117 "compiler.y"
{
		//++
		yyval.gt = create_tree("postfix_expression",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 13:
#line 121 "compiler.y"
{
		//--
		yyval.gt = create_tree("postfix_expression",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 14:
#line 128 "compiler.y"
{
		yyval.gt = create_tree("argument_expression_list",1,yyvsp[0].gt);
	;
    break;}
case 15:
#line 131 "compiler.y"
{
		yyval.gt = create_tree("argument_expression_list",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 16:
#line 138 "compiler.y"
{
		//printf("postfix");
		yyval.gt = create_tree("unary_expression",1,yyvsp[0].gt);
	;
    break;}
case 17:
#line 142 "compiler.y"
{
		//++
		yyval.gt = create_tree("unary_expression",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 18:
#line 146 "compiler.y"
{
		//--
		yyval.gt = create_tree("unary_expression",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 19:
#line 150 "compiler.y"
{
		yyval.gt = create_tree("unary_expression",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 20:
#line 157 "compiler.y"
{
		yyval.gt = create_tree("unary_operator",1,yyvsp[0].gt);
	;
    break;}
case 21:
#line 160 "compiler.y"
{
		yyval.gt = create_tree("unary_operator",1,yyvsp[0].gt);
	;
    break;}
case 22:
#line 163 "compiler.y"
{
		yyval.gt = create_tree("unary_operator",1,yyvsp[0].gt);
	;
    break;}
case 23:
#line 166 "compiler.y"
{
		yyval.gt = create_tree("unary_operator",1,yyvsp[0].gt);
	;
    break;}
case 24:
#line 173 "compiler.y"
{
		yyval.gt = create_tree("multiplicative_expression",1,yyvsp[0].gt);
	;
    break;}
case 25:
#line 176 "compiler.y"
{
		yyval.gt = create_tree("multiplicative_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 26:
#line 179 "compiler.y"
{
		yyval.gt = create_tree("multiplicative_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 27:
#line 182 "compiler.y"
{
		yyval.gt = create_tree("multiplicative_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 28:
#line 189 "compiler.y"
{
		yyval.gt = create_tree("additive_expression",1,yyvsp[0].gt);
	;
    break;}
case 29:
#line 192 "compiler.y"
{
		yyval.gt = create_tree("additive_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 30:
#line 195 "compiler.y"
{
		yyval.gt = create_tree("additive_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 31:
#line 202 "compiler.y"
{
		yyval.gt = create_tree("shift_expression",1,yyvsp[0].gt);
	;
    break;}
case 32:
#line 205 "compiler.y"
{
		//<<
		yyval.gt = create_tree("shift_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 33:
#line 209 "compiler.y"
{
		//<<
		yyval.gt = create_tree("shift_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 34:
#line 217 "compiler.y"
{
		yyval.gt = create_tree("relational_expression",1,yyvsp[0].gt);
	;
    break;}
case 35:
#line 220 "compiler.y"
{
		yyval.gt = create_tree("relational_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 36:
#line 223 "compiler.y"
{
		yyval.gt = create_tree("relational_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 37:
#line 226 "compiler.y"
{
		// <= 
		yyval.gt = create_tree("relational_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 38:
#line 230 "compiler.y"
{
		// >=
		yyval.gt = create_tree("relational_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 39:
#line 238 "compiler.y"
{
		yyval.gt = create_tree("equality_expression",1,yyvsp[0].gt);
	;
    break;}
case 40:
#line 241 "compiler.y"
{
		// ==
		yyval.gt = create_tree("equality_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 41:
#line 245 "compiler.y"
{
		// !=
		yyval.gt = create_tree("equality_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 42:
#line 252 "compiler.y"
{
		yyval.gt = create_tree("and_expression",1,yyvsp[0].gt);
	;
    break;}
case 43:
#line 255 "compiler.y"
{
		yyval.gt = create_tree("and_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 44:
#line 262 "compiler.y"
{
		yyval.gt = create_tree("exclusive_or_expression",1,yyvsp[0].gt);
	;
    break;}
case 45:
#line 265 "compiler.y"
{
		yyval.gt = create_tree("exclusive_or_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 46:
#line 272 "compiler.y"
{
		yyval.gt = create_tree("inclusive_or_expression",1,yyvsp[0].gt);
	;
    break;}
case 47:
#line 275 "compiler.y"
{
		yyval.gt = create_tree("inclusive_or_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 48:
#line 282 "compiler.y"
{
		yyval.gt = create_tree("logical_and_expression",1,yyvsp[0].gt);
	;
    break;}
case 49:
#line 285 "compiler.y"
{
		//&&
		yyval.gt = create_tree("logical_and_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 50:
#line 293 "compiler.y"
{
		yyval.gt = create_tree("logical_or_expression",1,yyvsp[0].gt);
	;
    break;}
case 51:
#line 296 "compiler.y"
{
		//||
		yyval.gt = create_tree("logical_or_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 52:
#line 304 "compiler.y"
{
		//条件表达式
		yyval.gt = create_tree("assignment_expression",1,yyvsp[0].gt);
	;
    break;}
case 53:
#line 308 "compiler.y"
{
		yyval.gt = create_tree("assignment_expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 54:
#line 315 "compiler.y"
{
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 55:
#line 318 "compiler.y"
{
		//*=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 56:
#line 322 "compiler.y"
{
		// /=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 57:
#line 326 "compiler.y"
{
		// %=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 58:
#line 330 "compiler.y"
{
		// += 
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 59:
#line 334 "compiler.y"
{
		// -=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 60:
#line 338 "compiler.y"
{
		// <<=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 61:
#line 342 "compiler.y"
{
		// >>=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 62:
#line 346 "compiler.y"
{
		// &=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 63:
#line 350 "compiler.y"
{
		// ^=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 64:
#line 354 "compiler.y"
{
		// |=
		yyval.gt = create_tree("assignment_operator",1,yyvsp[0].gt);
	;
    break;}
case 65:
#line 362 "compiler.y"
{
		//赋值表达式
		yyval.gt = create_tree("expression",1,yyvsp[0].gt);
	;
    break;}
case 66:
#line 366 "compiler.y"
{
		//逗号表达式
		yyval.gt = create_tree("expression",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 67:
#line 374 "compiler.y"
{
		yyval.gt = create_tree("declaration",2,yyvsp[-1].gt,yyvsp[0].gt); //?
	;
    break;}
case 68:
#line 377 "compiler.y"
{
		yyval.gt = create_tree("declaration",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 69:
#line 384 "compiler.y"
{
		yyval.gt = create_tree("init_declarator_list",1,yyvsp[0].gt);
	;
    break;}
case 70:
#line 387 "compiler.y"
{
		yyval.gt = create_tree("init_declarator_list",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 71:
#line 393 "compiler.y"
{
		yyval.gt = create_tree("init_declarator",1,yyvsp[0].gt);
	;
    break;}
case 72:
#line 396 "compiler.y"
{
		yyval.gt = create_tree("init_declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 73:
#line 404 "compiler.y"
{
		yyval.gt = create_tree("type_specifier",1,yyvsp[0].gt);
	;
    break;}
case 74:
#line 407 "compiler.y"
{
		yyval.gt = create_tree("type_specifier",1,yyvsp[0].gt);
	;
    break;}
case 75:
#line 410 "compiler.y"
{
		yyval.gt = create_tree("type_specifier",1,yyvsp[0].gt);
	;
    break;}
case 76:
#line 413 "compiler.y"
{
		yyval.gt = create_tree("type_specifier",1,yyvsp[0].gt);	
	;
    break;}
case 77:
#line 416 "compiler.y"
{
		yyval.gt = create_tree("type_specifier",1,yyvsp[0].gt);
	;
    break;}
case 78:
#line 424 "compiler.y"
{
		//变量
		yyval.gt = create_tree("declarator",1,yyvsp[0].gt);
	;
    break;}
case 79:
#line 428 "compiler.y"
{
		//.....
		yyval.gt = create_tree("declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 80:
#line 432 "compiler.y"
{
		//数组
		//printf("assignment_expression");
		yyval.gt = create_tree("declarator",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 81:
#line 437 "compiler.y"
{
		//....
		yyval.gt = create_tree("declarator",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 82:
#line 441 "compiler.y"
{
		//数组
		yyval.gt = create_tree("declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 83:
#line 445 "compiler.y"
{
		//函数
		yyval.gt = create_tree("declarator",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 84:
#line 449 "compiler.y"
{
		//函数
		yyval.gt = create_tree("declarator",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 85:
#line 453 "compiler.y"
{
		//函数
		yyval.gt = create_tree("declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 86:
#line 462 "compiler.y"
{
		yyval.gt = create_tree("parameter_list",1,yyvsp[0].gt);
	;
    break;}
case 87:
#line 465 "compiler.y"
{
		yyval.gt = create_tree("parameter_list",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 88:
#line 471 "compiler.y"
{
		yyval.gt = create_tree("parameter_declaration",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 89:
#line 474 "compiler.y"
{
		yyval.gt = create_tree("parameter_declaration",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 90:
#line 477 "compiler.y"
{
		yyval.gt = create_tree("parameter_declaration",1,yyvsp[0].gt);
	;
    break;}
case 91:
#line 483 "compiler.y"
{
		yyval.gt = create_tree("identifier_list",1,yyvsp[0].gt);
	;
    break;}
case 92:
#line 486 "compiler.y"
{
		yyval.gt = create_tree("identifier_list",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 93:
#line 492 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 94:
#line 495 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 95:
#line 498 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 96:
#line 501 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 97:
#line 504 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 98:
#line 507 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 99:
#line 510 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 100:
#line 513 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 101:
#line 516 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 102:
#line 519 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 103:
#line 522 "compiler.y"
{
		yyval.gt = create_tree("abstract_declarator",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 104:
#line 529 "compiler.y"
{
		yyval.gt = create_tree("initializer",1,yyvsp[0].gt);
	;
    break;}
case 105:
#line 532 "compiler.y"
{
		//列表初始化 {1,1,1}
		yyval.gt = create_tree("initializer",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 106:
#line 536 "compiler.y"
{
		//列表初始化 {1,1,1,}
		yyval.gt = create_tree("initializer",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 107:
#line 543 "compiler.y"
{
		yyval.gt = create_tree("initializer_list",1,yyvsp[0].gt);
	;
    break;}
case 108:
#line 546 "compiler.y"
{
		yyval.gt = create_tree("initializer_list",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 109:
#line 549 "compiler.y"
{
		yyval.gt = create_tree("initializer_list",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 110:
#line 552 "compiler.y"
{
		yyval.gt = create_tree("initializer_list",3,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt);
	;
    break;}
case 111:
#line 558 "compiler.y"
{
		yyval.gt = create_tree("designation",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 112:
#line 564 "compiler.y"
{
		yyval.gt = create_tree("designator_list",1,yyvsp[0].gt);
	;
    break;}
case 113:
#line 567 "compiler.y"
{
		yyval.gt = create_tree("designator_list",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 114:
#line 573 "compiler.y"
{
		yyval.gt = create_tree("designator",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 115:
#line 576 "compiler.y"
{
		yyval.gt = create_tree("designator",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 116:
#line 583 "compiler.y"
{
		yyval.gt = create_tree("statement",1,yyvsp[0].gt);
	;
    break;}
case 117:
#line 586 "compiler.y"
{
		yyval.gt = create_tree("statement",1,yyvsp[0].gt);
	;
    break;}
case 118:
#line 589 "compiler.y"
{
		yyval.gt = create_tree("statement",1,yyvsp[0].gt);
	;
    break;}
case 119:
#line 592 "compiler.y"
{
		yyval.gt = create_tree("statement",1,yyvsp[0].gt);
	;
    break;}
case 120:
#line 595 "compiler.y"
{
		yyval.gt = create_tree("statement",1,yyvsp[0].gt);
	;
    break;}
case 121:
#line 598 "compiler.y"
{
		yyval.gt = create_tree("statement",1,yyvsp[0].gt);
	;
    break;}
case 122:
#line 605 "compiler.y"
{
		yyval.gt = create_tree("labeled_statement",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 123:
#line 608 "compiler.y"
{
		yyval.gt = create_tree("labeled_statement",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 124:
#line 615 "compiler.y"
{
		yyval.gt = create_tree("compound_statement",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 125:
#line 618 "compiler.y"
{
		yyval.gt = create_tree("compound_statement",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 126:
#line 624 "compiler.y"
{
		yyval.gt = create_tree("block_item_list",1,yyvsp[0].gt);
	;
    break;}
case 127:
#line 627 "compiler.y"
{
		yyval.gt = create_tree("block_item_list",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 128:
#line 633 "compiler.y"
{
		yyval.gt = create_tree("block_item",1,yyvsp[0].gt);
	;
    break;}
case 129:
#line 636 "compiler.y"
{
		yyval.gt = create_tree("block_item",1,yyvsp[0].gt);
	;
    break;}
case 130:
#line 642 "compiler.y"
{
		yyval.gt = create_tree("expression_statement",1,yyvsp[0].gt);
	;
    break;}
case 131:
#line 645 "compiler.y"
{
		yyval.gt = create_tree("expression_statement",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 132:
#line 652 "compiler.y"
{
		yyval.gt = create_tree("selection_statement",5,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 133:
#line 655 "compiler.y"
{
		yyval.gt = create_tree("selection_statement",7,yyvsp[-6].gt,yyvsp[-5].gt,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 134:
#line 658 "compiler.y"
{
		yyval.gt = create_tree("selection_statement",5,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 135:
#line 665 "compiler.y"
{
		yyval.gt = create_tree("iteration_statement",5,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 136:
#line 668 "compiler.y"
{
		yyval.gt = create_tree("iteration_statement",7,yyvsp[-6].gt,yyvsp[-5].gt,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 137:
#line 671 "compiler.y"
{
		yyval.gt = create_tree("iteration_statement",6,yyvsp[-5].gt,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 138:
#line 674 "compiler.y"
{
		yyval.gt = create_tree("iteration_statement",7,yyvsp[-6].gt,yyvsp[-5].gt,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 139:
#line 677 "compiler.y"
{
		yyval.gt = create_tree("iteration_statement",6,yyvsp[-5].gt,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 140:
#line 680 "compiler.y"
{
		yyval.gt = create_tree("iteration_statement",7,yyvsp[-6].gt,yyvsp[-5].gt,yyvsp[-4].gt,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 141:
#line 687 "compiler.y"
{
		yyval.gt = create_tree("jump_statement",2,yyvsp[-2].gt,yyvsp[-1].gt);
	;
    break;}
case 142:
#line 690 "compiler.y"
{
		yyval.gt = create_tree("jump_statement",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 143:
#line 693 "compiler.y"
{
		yyval.gt = create_tree("jump_statement",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 144:
#line 696 "compiler.y"
{
		yyval.gt = create_tree("jump_statement",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 145:
#line 699 "compiler.y"
{
		yyval.gt = create_tree("jump_statement",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 146:
#line 705 "compiler.y"
{
		yyval.gt = create_tree("translation_unit",1,yyvsp[0].gt);
	;
    break;}
case 147:
#line 708 "compiler.y"
{
		yyval.gt = create_tree("translation_unit",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 148:
#line 714 "compiler.y"
{
		yyval.gt = create_tree("external_declaration",1,yyvsp[0].gt);
		//函数定义
		//printf("function_definition");
	;
    break;}
case 149:
#line 719 "compiler.y"
{
		yyval.gt = create_tree("external_declaration",1,yyvsp[0].gt);
		//变量声明
		//printf("declaration");
	;
    break;}
case 150:
#line 727 "compiler.y"
{
		yyval.gt = create_tree("function_definition",4,yyvsp[-3].gt,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 151:
#line 730 "compiler.y"
{
		yyval.gt = create_tree("function_definition",3,yyvsp[-2].gt,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
case 152:
#line 736 "compiler.y"
{
		yyval.gt = create_tree("declaration_list",1,yyvsp[0].gt);
	;
    break;}
case 153:
#line 739 "compiler.y"
{
		yyval.gt = create_tree("declaration_list",2,yyvsp[-1].gt,yyvsp[0].gt);
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 744 "compiler.y"



void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {

	yyin = fopen(argv[1],"r");
	
	//freopen("output/output.txt","w", stdout);
	yyparse();
	printf("\n");
	eval(root,0);	//输出语法分析树

	Praser praser;

	fclose(yyin);
	return 0;
}