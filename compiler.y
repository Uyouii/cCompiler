%{
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern int column;
extern FILE * yyin;
extern struct gramTree	*root;
extern int yylineno;

int yylex(void);
void yyerror(const char*); 
%}

%union{
	struct gramTree* gt;
}

%token <gt> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_DOUBLE
%token <gt> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <gt> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <gt> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <gt> XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token <gt> CHAR INT DOUBLE CONST VOID
%token <gt> BOOL 
%token <gt> STRUCT UNION ENUM ELLIPSIS

%token <gt> CASE IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token <gt> ';' ',' ':' '=' '[' ']' '.' '&' '!' '~' '-' '+' '*' '/' '%' '<' '>' '^' '|' '?' '{' '}' '(' ')'

%type <gt> primary_expression postfix_expression argument_expression_list unary_expression cast_expression unary_operator
%type <gt> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type <gt> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <gt> conditional_expression assignment_expression assignment_operator expression constant_expression

%type <gt> declaration declaration_specifiers init_declarator_list init_declarator type_specifier
%type <gt> struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration
%type <gt> specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier enumerator_list enumerator 
%type <gt> declarator direct_declarator 

%type <gt> pointer parameter_list parameter_declaration identifier_list
%type <gt> type_name abstract_declarator direct_abstract_declarator initializer initializer_list designation designator_list
%type <gt> designator statement labeled_statement compound_statement block_item_list block_item expression_statement
%type <gt> selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition
%type <gt> declaration_list

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

Program: 
	translation_unit {
		root = create_tree("Program",1,$1);
	}
	;

/*基本表达式*/
primary_expression: 
	IDENTIFIER {
		$$ = create_tree("primary_expression",1,$1);
	}
	| CONSTANT{
		
	}
	| CONSTANT_INT {
		//printf("%d",$1->int_value);
		$$ = create_tree("primary_expression",1,$1);
		$$->type = (char*)malloc(sizeof("int"));
		strcpy($$->type,"int");
		$$->int_value = $1->int_value;
		
	}
	| CONSTANT_DOUBLE {
		$$ = create_tree("primary_expression",1,$1);
		$$->type = (char*)malloc(sizeof("double"));
		strcpy($$->type,"double");
		$$->double_value = $1->double_value;
	}
	| STRING_LITERAL{
		$$ = create_tree("primary_expression",1,$1);
		$$->type = (char*)malloc(sizeof("string"));
		strcpy($$->type,"string");
		$$->string_value = (char*)malloc(strlen($1->content) + 1);	//储存起来字符串常量
		strcpy($$->string_value,$1->content);
		//printf("%s",$$->string_value);
	}
	| '(' expression ')'{
		$$ = create_tree("primary_expression",3,$1,$2,$3);
	}
	;

/*后缀表达式*/
postfix_expression:
	primary_expression{
		$$ = create_tree("postfix_expression",1,$1);
	}
	| 	postfix_expression '[' expression ']'{
		$$ = create_tree("postfix_expression",4,$1,$2,$3,$4);
	}
	| 	postfix_expression '(' ')'{
		$$ = create_tree("postfix_expression",3,$1,$2,$3);
	}
	| 	postfix_expression '(' argument_expression_list ')'{
		$$ = create_tree("postfix_expression",4,$1,$2,$3,$4);
	}
	| 	postfix_expression '.' IDENTIFIER{
		$$ = create_tree("postfix_expression",3,$1,$2,$3);
	}
	| 	postfix_expression PTR_OP IDENTIFIER{
		$$ = create_tree("postfix_expression",3,$1,$2,$3);
		//->
	}
	| 	postfix_expression INC_OP{
		//++
		$$ = create_tree("postfix_expression",2,$1,$2);
	}
	| 	postfix_expression DEC_OP{
		//--
		$$ = create_tree("postfix_expression",2,$1,$2);
	}
	| 	'(' type_name ')' '{' initializer_list '}'{
		$$ = create_tree("postfix_expression",6,$1,$2,$3,$4,$5,$6);
	}
	| 	'(' type_name ')' '{' initializer_list ',' '}'{
		$$ = create_tree("postfix_expression",7,$1,$2,$3,$4,$5,$6,$7);
	}
	;

argument_expression_list:
	assignment_expression{
		$$ = create_tree("argument_expression_list",1,$1);
	}
	| 	argument_expression_list ',' assignment_expression {
		$$ = create_tree("argument_expression_list",3,$1,$2,$3);
	}
	;

/*一元表达式*/
unary_expression:
	postfix_expression{
		//printf("postfix");
		$$ = create_tree("unary_expression",1,$1);
	}
	| 	INC_OP unary_expression{
		//++
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	| 	DEC_OP unary_expression{
		//--
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	| 	unary_operator cast_expression{
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	| 	SIZEOF unary_expression{
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	| 	SIZEOF '(' type_name ')'{
		$$ = create_tree("unary_expression",4,$1,$2,$3,$4);
	}
	;

/*单目运算符*/
unary_operator:
	'&' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '*' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '+' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '-' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '~' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '!' {
		$$ = create_tree("unary_operator",1,$1);
	}
	;

/*转换表达式*/
cast_expression:
	unary_expression {
		//一元表达式
		$$ = create_tree("cast_expression",1,$1);
	}
	|'(' type_name ')' cast_expression {
		//强制类型转换
		$$ = create_tree("cast_expression",4,$1,$2,$3,$4);
	}
	;

/*可乘表达式*/
multiplicative_expression:
	cast_expression {
		$$ = create_tree("multiplicative_expression",1,$1);
	}
	| multiplicative_expression '*' cast_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '/' cast_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '%' cast_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	;

/*可加表达式*/
additive_expression:
	multiplicative_expression  {
		$$ = create_tree("additive_expression",1,$1);
	}
	| additive_expression '+' multiplicative_expression {
		$$ = create_tree("additive_expression",3,$1,$2,$3);
	}
	| additive_expression '-' multiplicative_expression {
		$$ = create_tree("additive_expression",3,$1,$2,$3);
	}
	;

/*左移右移*/
shift_expression:
	additive_expression {
		$$ = create_tree("shift_expression",1,$1);
	}
	| shift_expression LEFT_OP additive_expression {
		//<<
		$$ = create_tree("shift_expression",3,$1,$2,$3);
	}
	| shift_expression RIGHT_OP additive_expression {
		//<<
		$$ = create_tree("shift_expression",3,$1,$2,$3);
	}
	;

/*关系表达式*/
relational_expression:
	shift_expression {
		$$ = create_tree("relational_expression",1,$1);
	}
	| relational_expression '<' shift_expression {
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	| relational_expression '>' shift_expression {
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	| relational_expression LE_OP shift_expression {
		// <= 
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	| relational_expression GE_OP shift_expression {
		// >=
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	;

/*相等表达式*/
equality_expression:
	relational_expression {
		$$ = create_tree("equality_expression",1,$1);
	}
	| equality_expression EQ_OP relational_expression {
		// ==
		$$ = create_tree("equality_expression",3,$1,$2,$3);
	}
	| equality_expression NE_OP relational_expression {
		// !=
		$$ = create_tree("equality_expression",3,$1,$2,$3);
	}
	;

and_expression:
	equality_expression {
		$$ = create_tree("and_expression",1,$1);
	}
	| and_expression '&' equality_expression {
		$$ = create_tree("and_expression",3,$1,$2,$3);
	}
	;

/*异或*/
exclusive_or_expression:
	and_expression {
		$$ = create_tree("exclusive_or_expression",1,$1);
	}
	| exclusive_or_expression '^' and_expression {
		$$ = create_tree("exclusive_or_expression",3,$1,$2,$3);
	}
	;

/*或*/
inclusive_or_expression:
	exclusive_or_expression {
		$$ = create_tree("inclusive_or_expression",1,$1);
	}
	| inclusive_or_expression '|' exclusive_or_expression {
		$$ = create_tree("inclusive_or_expression",3,$1,$2,$3);
	}
	;

/*and逻辑表达式*/
logical_and_expression:
	inclusive_or_expression {
		$$ = create_tree("logical_and_expression",1,$1);
	}
	| logical_and_expression AND_OP inclusive_or_expression {
		//&&
		$$ = create_tree("logical_and_expression",3,$1,$2,$3);
	}
	;

/*or 逻辑表达式*/
logical_or_expression:
	logical_and_expression {
		$$ = create_tree("logical_or_expression",1,$1);
	}
	| logical_or_expression OR_OP logical_and_expression {
		//||
		$$ = create_tree("logical_or_expression",3,$1,$2,$3);
	}
	;

/*条件表达式*/
conditional_expression:
	logical_or_expression {
		$$ = create_tree("conditional_expression",1,$1);
	}
	| logical_or_expression '?' expression ':' conditional_expression {
		$$ = create_tree("conditional_expression",3,$1,$2,$3);
	}
	;

/*赋值表达式*/
assignment_expression:
	conditional_expression {
		//条件表达式
		$$ = create_tree("assignment_expression",1,$1);
	}
	| unary_expression assignment_operator assignment_expression {
		$$ = create_tree("assignment_expression",3,$1,$2,$3);
	}
	;

/*赋值运算符*/
assignment_operator:
	'=' {
		$$ = create_tree("assignment_operator",1,$1);
	}
	| MUL_ASSIGN {
		//*=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| DIV_ASSIGN {
		// /=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| MOD_ASSIGN {
		// %=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| ADD_ASSIGN {
		// += 
		$$ = create_tree("assignment_operator",1,$1);
	}
	| SUB_ASSIGN {
		// -=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| LEFT_ASSIGN {
		// <<=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| RIGHT_ASSIGN {
		// >>=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| AND_ASSIGN {
		// &=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| XOR_ASSIGN {
		// ^=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| OR_ASSIGN {
		// |=
		$$ = create_tree("assignment_operator",1,$1);
	}
	;

/*表达式*/
expression:
	assignment_expression {
		//赋值表达式
		$$ = create_tree("expression",1,$1);
	}
	| expression ',' assignment_expression {
		//逗号表达式
		$$ = create_tree("expression",3,$1,$2,$3);
	}
	;

//常量表达式
constant_expression:
	conditional_expression {
		//条件表达式
		$$ = create_tree("constant_expression",1,$1);
	}
	;


declaration:
	declaration_specifiers ';' {
		$$ = create_tree("declaration",2,$1,$2);
	}
	| declaration_specifiers init_declarator_list ';' {
		//printf("declaration_specifiers init_declarator_list");
		$$ = create_tree("declaration",3,$1,$2,$3);
	}
	;

//变量、函数声明标识符
declaration_specifiers:
	type_specifier {	
		$$ = create_tree("declaration_specifiers",1,$1);
	}
	| type_specifier declaration_specifiers {
		$$ = create_tree("declaration_specifiers",2,$1,$2);
	}	
	;

init_declarator_list:
	init_declarator {
		$$ = create_tree("init_declarator_list",1,$1);
	}
	| init_declarator_list ',' init_declarator {
		$$ = create_tree("init_declarator_list",3,$1,$2,$3);
	}
	;

init_declarator:
	declarator {
		$$ = create_tree("init_declarator",1,$1);
	}
	| declarator '=' initializer {
		$$ = create_tree("init_declarator",3,$1,$2,$3);
	}
	;


/*类型说明符*/
type_specifier:
	VOID {
		$$ = create_tree("type_specifier",1,$1);
	}
	| CHAR {
		$$ = create_tree("type_specifier",1,$1);
	}
	| INT {
		$$ = create_tree("type_specifier",1,$1);
	}
	| DOUBLE {
		$$ = create_tree("type_specifier",1,$1);	
	}
	| BOOL {
		$$ = create_tree("type_specifier",1,$1);
	}
	| struct_or_union_specifier {
		$$ = create_tree("type_specifier",1,$1);
	}
	| enum_specifier {
		//enum
		$$ = create_tree("type_specifier",1,$1);
	}
	| TYPE_NAME {
		//暂时没写
		$$ = create_tree("type_specifier",1,$1);
	}
	;

/* struct 和 union*/
struct_or_union_specifier:
	struct_or_union IDENTIFIER '{' struct_declaration_list '}' {
		$$ = create_tree("struct_or_union_specifier",4,$1,$2,$3,$4);
	}
	| struct_or_union '{' struct_declaration_list '}' {
		$$ = create_tree("struct_or_union_specifier",4,$1,$2,$3,$4);
	}
	| struct_or_union IDENTIFIER {
		$$ = create_tree("struct_or_union_specifier",2,$1,$2);
	}
	;

struct_or_union:
	STRUCT {
		$$ = create_tree("struct_or_union",1,$1);
	}
	| UNION {
		$$ = create_tree("struct_or_union",1,$1);
	}
	;

/*struct 声明列表*/
struct_declaration_list:
	struct_declaration {
		$$ = create_tree("struct_declaration_list",1,$1);
	}
	| struct_declaration_list struct_declaration {
		$$ = create_tree("struct_declaration_list",2,$1,$2);
	}
	;

struct_declaration:
	specifier_qualifier_list struct_declarator_list ';' {
		$$ = create_tree("struct_declaration",3,$1,$2,$3);
	}
	;

specifier_qualifier_list:
	type_specifier specifier_qualifier_list {
		$$ = create_tree("specifier_qualifier_list",2,$1,$2);
	}
	| type_specifier {
		//类型说明符
		$$ = create_tree("specifier_qualifier_list",1,$1);
	}
	;

struct_declarator_list:
	struct_declarator {
		$$ = create_tree("struct_declarator_list",1,$1);
	}
	| struct_declarator_list ',' struct_declarator {
		$$ = create_tree("struct_declarator_list",3,$1,$2,$3);
	}
	;

struct_declarator:
	declarator {
		$$ = create_tree("struct_declarator",1,$1);
	}
	| ':' constant_expression {
		$$ = create_tree("struct_declarator",2,$1,$2);
	}
	| declarator ':' constant_expression {
		$$ = create_tree("struct_declarator",3,$1,$2,$3);
	}
	;

enum_specifier:
	ENUM '{' enumerator_list '}' {
		$$ = create_tree("enum_specifier",4,$1,$2,$3,$4);
	}
	| ENUM IDENTIFIER '{' enumerator_list '}' {
		$$ = create_tree("enum_specifier",4,$1,$2,$3,$4);
	}
	| ENUM '{' enumerator_list ',' '}' {
		$$ = create_tree("enum_specifier",5,$1,$2,$3,$4,$5);
	}
	| ENUM IDENTIFIER '{' enumerator_list ',' '}' {
		$$ = create_tree("enum_specifier",6,$1,$2,$3,$4,$5,$6);
	}
	| ENUM IDENTIFIER {
		$$ = create_tree("enum_specifier",2,$1,$2);
	}
	;

enumerator_list:
	enumerator {
		$$ = create_tree("enumerator_list",1,$1);
	}
	| enumerator_list ',' enumerator {
		$$ = create_tree("enumerator_list",3,$1,$2,$3);
	}
	;

enumerator:
	IDENTIFIER {
		$$ = create_tree("enumerator",1,$1);
	}
	| IDENTIFIER '=' constant_expression {
		$$ = create_tree("enumerator",3,$1,$2,$3);
	}
	;

declarator:
	pointer direct_declarator {
		$$ = create_tree("declarator",2,$1,$2);
	}
	| direct_declarator {
		$$ = create_tree("declarator",1,$1);
	}
	;


direct_declarator:
	IDENTIFIER {
		//变量
		$$ = create_tree("direct_declarator",1,$1);
	}
	| '(' declarator ')' {
		//.....
		$$ = create_tree("direct_declarator",3,$1,$2,$3);
	}
	| direct_declarator '[' assignment_expression ']' {
		//数组
		//printf("assignment_expression");
		$$ = create_tree("direct_declarator",4,$1,$2,$3,$4);
	}
	| direct_declarator '[' '*' ']' {
		//....
		$$ = create_tree("direct_declarator",4,$1,$2,$3,$4);
	}
	| direct_declarator '[' ']' {
		//数组
		$$ = create_tree("direct_declarator",3,$1,$2,$3);
	}
	| direct_declarator '(' parameter_list ')' {
		//函数
		$$ = create_tree("direct_declarator",4,$1,$2,$3,$4);
	}
	| direct_declarator '(' identifier_list ')' {
		//函数
		$$ = create_tree("direct_declarator",4,$1,$2,$3,$4);
	}
	| direct_declarator '(' ')' {
		//函数
		$$ = create_tree("direct_declarator",3,$1,$2,$3);
	}
	;

pointer:
	'*' {
		$$ = create_tree("pointer",1,$1);
	}
	| '*' pointer {
		$$ = create_tree("pointer",2,$1,$2);
	}
	;

//参数列表
parameter_list:
	parameter_declaration {
		$$ = create_tree("parameter_list",1,$1);
	}
	| parameter_list ',' parameter_declaration {
		$$ = create_tree("parameter_list",3,$1,$2,$3);
	}
	;

parameter_declaration:
	declaration_specifiers declarator {
		$$ = create_tree("parameter_declaration",2,$1,$2);
	}
	| declaration_specifiers abstract_declarator {
		$$ = create_tree("parameter_declaration",2,$1,$2);
	}
	| declaration_specifiers {
		$$ = create_tree("parameter_declaration",1,$1);
	}
	;

identifier_list:
	IDENTIFIER {
		$$ = create_tree("identifier_list",1,$1);
	}
	| identifier_list ',' IDENTIFIER {
		$$ = create_tree("identifier_list",3,$1,$2,$3);
	}
	;

type_name:
	specifier_qualifier_list {
		$$ = create_tree("type_name",1,$1);
	}
	| specifier_qualifier_list abstract_declarator {
		$$ = create_tree("type_name",2,$1,$2);
	}
	;

abstract_declarator:
	pointer {
		$$ = create_tree("abstract_declarator",1,$1);
	}
	| direct_abstract_declarator {
		$$ = create_tree("abstract_declarator",1,$1);
	}
	| pointer direct_abstract_declarator {
		$$ = create_tree("abstract_declarator",2,$1,$2);
	}
	;

direct_abstract_declarator:
	'(' abstract_declarator ')' {
		$$ = create_tree("direct_abstract_declarator",3,$1,$2,$3);
	}
	| '[' ']' {
		$$ = create_tree("direct_abstract_declarator",2,$1,$2);
	}
	| '[' assignment_expression ']' {
		$$ = create_tree("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '[' ']' {
		$$ = create_tree("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '[' assignment_expression ']' {
		$$ = create_tree("direct_abstract_declarator",4,$1,$2,$3,$4);
	}
	| '[' '*' ']' {
		$$ = create_tree("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '[' '*' ']' {
		$$ = create_tree("direct_abstract_declarator",4,$1,$2,$3,$4);
	}
	| '(' ')' {
		$$ = create_tree("direct_abstract_declarator",2,$1,$2);
	}
	| '(' parameter_list ')' {
		$$ = create_tree("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '(' ')' {
		$$ = create_tree("direct_abstract_declarator",3,$1,$2,$3);
	}
	| direct_abstract_declarator '(' parameter_list ')' {
		$$ = create_tree("direct_abstract_declarator",4,$1,$2,$3,$4);
	}
	;

//初始化
initializer:
	assignment_expression {
		$$ = create_tree("initializer",1,$1);
	}
	| '{' initializer_list '}' {
		//列表初始化 {1,1,1}
		$$ = create_tree("initializer",3,$1,$2,$3);
	}
	| '{' initializer_list ',' '}' {
		//列表初始化 {1,1,1,}
		$$ = create_tree("initializer",4,$1,$2,$3,$4);
	}
	;

initializer_list:
	initializer {
		$$ = create_tree("initializer_list",1,$1);
	}
	| designation initializer {
		$$ = create_tree("initializer_list",2,$1,$2);
	}
	| initializer_list ',' initializer {
		$$ = create_tree("initializer_list",3,$1,$2,$3);
	}
	| initializer_list ',' designation initializer {
		$$ = create_tree("initializer_list",3,$1,$2,$3);
	}
	;

designation:
	designator_list '=' {
		$$ = create_tree("designation",2,$1,$2);
	}
	;

designator_list:
	designator {
		$$ = create_tree("designator_list",1,$1);
	}
	| designator_list designator {
		$$ = create_tree("designator_list",2,$1,$2);
	}
	;

designator: 
	'[' constant_expression ']' {
		$$ = create_tree("designator",3,$1,$2,$3);
	}
	| '.' IDENTIFIER {
		$$ = create_tree("designator",2,$1,$2);
	}
	;

//声明
statement:
	labeled_statement {
		$$ = create_tree("statement",1,$1);
	}
	| compound_statement {
		$$ = create_tree("statement",1,$1);
	}
	| expression_statement{
		$$ = create_tree("statement",1,$1);
	}
	| selection_statement {
		$$ = create_tree("statement",1,$1);
	}
	| iteration_statement {
		$$ = create_tree("statement",1,$1);
	}
	| jump_statement {
		$$ = create_tree("statement",1,$1);
	}
	;

//标签声明
labeled_statement:
	IDENTIFIER ':' statement {
		$$ = create_tree("labeled_statement",3,$1,$2,$3);
	}
	| CASE constant_expression ':' statement {
		$$ = create_tree("labeled_statement",4,$1,$2,$3,$4);
	}
	;

//复合语句
compound_statement:
	'{' '}' {
		$$ = create_tree("compound_statement",2,$1,$2);
	}
	| '{' block_item_list '}' {
		$$ = create_tree("compound_statement",3,$1,$2,$3);
	}
	;

block_item_list:
	block_item {
		$$ = create_tree("block_item_list",1,$1);
	}
	| block_item_list block_item {
		$$ = create_tree("block_item_list",2,$1,$2);
	}
	;

block_item:
	declaration {
		$$ = create_tree("block_item",1,$1);
	}
	| statement {
		$$ = create_tree("block_item",1,$1);
	}
	;

expression_statement:
	';' {
		$$ = create_tree("expression_statement",1,$1);
	}
	| expression ';' {
		$$ = create_tree("expression_statement",2,$1,$2);
	}
	;

//条件语句
selection_statement:
	IF '(' expression ')' statement %prec LOWER_THAN_ELSE {
		$$ = create_tree("selection_statement",5,$1,$2,$3,$4,$5);
	}
    | IF '(' expression ')' statement ELSE statement {
		$$ = create_tree("selection_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
    | SWITCH '(' expression ')' statement {
		$$ = create_tree("selection_statement",5,$1,$2,$3,$4,$5);
	}
    ;

//循环语句
iteration_statement:
	WHILE '(' expression ')' statement {
		$$ = create_tree("iteration_statement",5,$1,$2,$3,$4,$5);
	}
	| DO statement WHILE '(' expression ')' ';' {
		$$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	| FOR '(' expression_statement expression_statement ')' statement {
		$$ = create_tree("iteration_statement",6,$1,$2,$3,$4,$5,$6);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement {
		$$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	| FOR '(' declaration expression_statement ')' statement {
		$$ = create_tree("iteration_statement",6,$1,$2,$3,$4,$5,$6);
	}
	| FOR '(' declaration expression_statement expression ')' statement {
		$$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	;

//跳转指令
jump_statement:
	GOTO IDENTIFIER ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| CONTINUE ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| BREAK ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| RETURN ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| RETURN expression ';' {
		$$ = create_tree("jump_statement",3,$1,$2,$3);
	}
	;

translation_unit:
	external_declaration {
		$$ = create_tree("translation",1,$1);
	}
	| translation_unit external_declaration {
		$$ = create_tree("translation",2,$1,$2);
	}
	;

external_declaration:
	function_definition {
		$$ = create_tree("external_declaration",1,$1);
		//函数定义
		//printf("function_definition");
	}
	| declaration {
		$$ = create_tree("external_declaration",1,$1);
		//变量声明
		//printf("declaration");
	}
	;

function_definition:
	declaration_specifiers declarator declaration_list compound_statement {
		$$ = create_tree("external_declaration",4,$1,$2,$3,$4);
	}
	| declaration_specifiers declarator compound_statement {
		$$ = create_tree("external_declaration",3,$1,$2,$3);
	}
	;

declaration_list:
	declaration {
		$$ = create_tree("declaration_list",1,$1);
	}
	| declaration_list declaration {
		$$ = create_tree("declaration_list",2,$1,$2);
	}
	;

%%


void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {

	yyin = fopen(argv[1],"r");

	yyparse();
	printf("\n");
	eval(root,0);
	fclose(yyin);
	return 0;
}