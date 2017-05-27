%{
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern int column;
extern FILE * yyin;
extern struct gramTree	*root;

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

%type <gt> primary_expression postfix_expression argument_expression_list unary_expression cast_expression
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
		
	}
	| CONSTANT{
		
	}
	| CONSTANT_INT {
		
	}
	| CONSTANT_DOUBLE {
	
	}
	| STRING_LITERAL{
	
	}
	| '(' expression ')'{
		
	}
	;

/*后缀表达式*/
postfix_expression:
	primary_expression{
	
	}
	| 	postfix_expression '[' expression ']'{
		
	}
	| 	postfix_expression '(' ')'{
			
	}
	| 	postfix_expression '(' argument_expression_list ')'{
			
	}
	| 	postfix_expression '.' IDENTIFIER{

	}
	| 	postfix_expression PTR_OP IDENTIFIER{
		//->
	}
	| 	postfix_expression INC_OP{
		//++
	}
	| 	postfix_expression DEC_OP{
		//--
	}
	| 	'(' type_name ')' '{' initializer_list '}'{
		
	}
	| 	'(' type_name ')' '{' initializer_list ',' '}'{
		
	}
	;

argument_expression_list:
	assignment_expression{

	}
	| 	argument_expression_list ',' assignment_expression {

	}
	;

/*一元表达式*/
unary_expression:
	postfix_expression{
		//printf("postfix");
	}
	| 	INC_OP unary_expression{
		//++
	}
	| 	DEC_OP unary_expression{
		//--
	}
	| 	unary_operator cast_expression{
		
	}
	| 	SIZEOF unary_expression{

	}
	| 	SIZEOF '(' type_name ')'{

	}
	;

/*单目运算符*/
unary_operator:
		'&'
	| 	'*'
	| 	'+'
	| 	'-'
	| 	'~'
	| 	'!'
	;

/*转换表达式*/
cast_expression:
	unary_expression {
		//一元表达式
	}
	|'(' type_name ')' cast_expression {
		//强制类型转换
	}
	;

/*可乘表达式*/
multiplicative_expression:
	cast_expression {

	}
	| multiplicative_expression '*' cast_expression {
		//
	}
	| multiplicative_expression '/' cast_expression {

	}
	| multiplicative_expression '%' cast_expression {

	}
	;

/*可加表达式*/
additive_expression:
	multiplicative_expression  {
		//可加的一定可乘
	}
	| additive_expression '+' multiplicative_expression {
		
	}
	| additive_expression '-' multiplicative_expression {

	}
	;

/*左移右移*/
shift_expression:
	additive_expression {

	}
	| shift_expression LEFT_OP additive_expression {
		//<<
	}
	| shift_expression RIGHT_OP additive_expression {
		//<<
	}
	;

/*关系表达式*/
relational_expression:
	shift_expression {

	}
	| relational_expression '<' shift_expression {
		
	}
	| relational_expression '>' shift_expression {

	}
	| relational_expression LE_OP shift_expression {
		// <= 
	}
	| relational_expression GE_OP shift_expression {
		// >=
	}
	;

/*相等表达式*/
equality_expression:
	relational_expression {

	}
	| equality_expression EQ_OP relational_expression {
		// ==
	}
	| equality_expression NE_OP relational_expression {
		// !=
	}
	;

and_expression:
	equality_expression {

	}
	| and_expression '&' equality_expression {

	}
	;

/*异或*/
exclusive_or_expression:
	and_expression {

	}
	| exclusive_or_expression '^' and_expression {

	}
	;

/*或*/
inclusive_or_expression:
	exclusive_or_expression {

	}
	| inclusive_or_expression '|' exclusive_or_expression {

	}
	;

/*and逻辑表达式*/
logical_and_expression:
	inclusive_or_expression {

	}
	| logical_and_expression AND_OP inclusive_or_expression {
		//&&
	}
	;

/*or 逻辑表达式*/
logical_or_expression:
	logical_and_expression {

	}
	| logical_or_expression OR_OP logical_and_expression {
		//||
	}
	;

/*条件表达式*/
conditional_expression:
	logical_or_expression {

	}
	| logical_or_expression '?' expression ':' conditional_expression {

	}
	;

/*赋值表达式*/
assignment_expression:
	conditional_expression {
		//条件表达式
	}
	| unary_expression assignment_operator assignment_expression {

	}
	;

/*赋值运算符*/
assignment_operator:
	'=' {

	}
	| MUL_ASSIGN {
		//*=
	}
	| DIV_ASSIGN {
		// /=
	}
	| MOD_ASSIGN {
		// %=
	}
	| ADD_ASSIGN {
		// += 
	}
	| SUB_ASSIGN {
		// -=
	}
	| LEFT_ASSIGN {
		// <<=
	}
	| RIGHT_ASSIGN {
		// >>=
	}
	| AND_ASSIGN {
		// &=
	}
	| XOR_ASSIGN {
		// ^=
	}
	| OR_ASSIGN {
		// |=
	}
	;

/*表达式*/
expression:
	assignment_expression {
		//赋值表达式
	}
	| expression ',' assignment_expression {
		//逗号表达式
	}
	;

//常量表达式
constant_expression:
	conditional_expression {
		//条件表达式
	}
	;


declaration:
	declaration_specifiers ';' {
		//printf("declaration_specifiers");
	}
	| declaration_specifiers init_declarator_list ';' {
		//printf("declaration_specifiers init_declarator_list");
	}
	;

//变量、函数声明标识符
declaration_specifiers:
	type_specifier {

	}
	| type_specifier declaration_specifiers {

	}
	;

init_declarator_list:
	init_declarator {
		//printf("init_declarator");
	}
	| init_declarator_list ',' init_declarator {

	}
	;

init_declarator:
	declarator {

	}
	| declarator '=' initializer {

	}
	;


/*类型说明符*/
type_specifier:
	VOID {

	}
	| CHAR {

	}
	| INT {

	}
	| DOUBLE {

	}
	| BOOL {

	}
	| struct_or_union_specifier {
		//struct union
	}
	| enum_specifier {
		//enum
	}
	| TYPE_NAME {
		//暂时没写
	}
	;

/* struct 和 union*/
struct_or_union_specifier:
	struct_or_union IDENTIFIER '{' struct_declaration_list '}' {

	}
	| struct_or_union '{' struct_declaration_list '}' {

	}
	| struct_or_union IDENTIFIER {

	}
	;

struct_or_union:
	STRUCT {

	}
	| UNION {

	}
	;

/*struct 声明列表*/
struct_declaration_list:
	struct_declaration {

	}
	| struct_declaration_list struct_declaration {

	}
	;

struct_declaration:
	specifier_qualifier_list struct_declarator_list ';' {

	}
	;

specifier_qualifier_list:
	type_specifier specifier_qualifier_list {

	}
	| type_specifier {
		//类型说明符
	}
	;

struct_declarator_list:
	struct_declarator {

	}
	| struct_declarator_list ',' struct_declarator {

	}
	;

struct_declarator:
	declarator {

	}
	| ':' constant_expression {

	}
	| declarator ':' constant_expression {

	}
	;

enum_specifier:
	ENUM '{' enumerator_list '}' {

	}
	| ENUM IDENTIFIER '{' enumerator_list '}' {

	}
	| ENUM '{' enumerator_list ',' '}' {

	}
	| ENUM IDENTIFIER '{' enumerator_list ',' '}' {

	}
	| ENUM IDENTIFIER {

	}
	;

enumerator_list:
	enumerator {
		
	}
	| enumerator_list ',' enumerator {

	}
	;

enumerator:
	IDENTIFIER {

	}
	| IDENTIFIER '=' constant_expression {

	}
	;

declarator:
	pointer direct_declarator {

	}
	| direct_declarator {

	}
	;


direct_declarator:
	IDENTIFIER {
		//变量
	}
	| '(' declarator ')' {
		//.....
	}
	| direct_declarator '[' assignment_expression ']' {
		//数组
		//printf("assignment_expression");
	}
	| direct_declarator '[' '*' ']' {
		//....
	}
	| direct_declarator '[' ']' {
		//数组
	}
	| direct_declarator '(' parameter_list ')' {
		//函数
	}
	| direct_declarator '(' identifier_list ')' {
		//函数
	}
	| direct_declarator '(' ')' {
		//函数
	}
	;

pointer:
	'*' {

	}
	| '*' pointer {

	}
	;

//参数列表
parameter_list:
	parameter_declaration {

	}
	| parameter_list ',' parameter_declaration {

	}
	;

parameter_declaration:
	declaration_specifiers declarator {

	}
	| declaration_specifiers abstract_declarator {

	}
	| declaration_specifiers {

	}
	;

identifier_list:
	IDENTIFIER {

	}
	| identifier_list ',' IDENTIFIER {

	}
	;

type_name:
	specifier_qualifier_list {

	}
	| specifier_qualifier_list abstract_declarator {

	}
	;

abstract_declarator:
	pointer {

	}
	| direct_abstract_declarator {

	}
	| pointer direct_abstract_declarator {

	}
	;

direct_abstract_declarator:
	'(' abstract_declarator ')' {

	}
	| '[' ']' {

	}
	| '[' assignment_expression ']' {

	}
	| direct_abstract_declarator '[' ']' {

	}
	| direct_abstract_declarator '[' assignment_expression ']' {

	}
	| '[' '*' ']' {

	}
	| direct_abstract_declarator '[' '*' ']' {

	}
	| '(' ')' {

	}
	| '(' parameter_list ')' {

	}
	| direct_abstract_declarator '(' ')' {

	}
	| direct_abstract_declarator '(' parameter_list ')' {

	}
	;

//初始化
initializer:
	assignment_expression {

	}
	| '{' initializer_list '}' {
		//列表初始化 {1,1,1}
	}
	| '{' initializer_list ',' '}' {
		//列表初始化 {1,1,1,}
	}
	;

initializer_list:
	initializer {

	}
	| designation initializer {

	}
	| initializer_list ',' initializer {

	}
	| initializer_list ',' designation initializer {

	}
	;

designation:
	designator_list '=' {

	}
	;

designator_list:
	designator {

	}
	| designator_list designator {

	}
	;

designator: 
	'[' constant_expression ']' {

	}
	| '.' IDENTIFIER {

	}
	;

//声明
statement:
	labeled_statement {

	}
	| compound_statement {
		 
	}
	| expression_statement{

	}
	| selection_statement {

	}
	| iteration_statement {

	}
	| jump_statement {

	}
	;

//标签声明
labeled_statement:
	IDENTIFIER ':' statement {

	}
	| CASE constant_expression ':' statement {

	}
	;

//复合语句
compound_statement:
	'{' '}' {

	}
	| '{' block_item_list '}' {

	}
	;

block_item_list:
	block_item {

	}
	| block_item_list block_item {

	}
	;

block_item:
	declaration {

	}
	| statement {

	}
	;

expression_statement:
	';' {

	}
	| expression ';' {
		
	}
	;

//条件语句
selection_statement:
	IF '(' expression ')' statement %prec LOWER_THAN_ELSE {

	}
    | IF '(' expression ')' statement ELSE statement {

	}
    | SWITCH '(' expression ')' statement {

	}
    ;

//循环语句
iteration_statement:
	WHILE '(' expression ')' statement {

	}
	| DO statement WHILE '(' expression ')' ';' {

	}
	| FOR '(' expression_statement expression_statement ')' statement {

	}
	| FOR '(' expression_statement expression_statement expression ')' statement {

	}
	| FOR '(' declaration expression_statement ')' statement {

	}
	| FOR '(' declaration expression_statement expression ')' statement {

	}
	;

//跳转指令
jump_statement:
	GOTO IDENTIFIER ';' {

	}
	| CONTINUE ';' {

	}
	| BREAK ';' {

	}
	| RETURN ';' {

	}
	| RETURN expression ';' {

	}
	;

translation_unit:
	external_declaration {
		//外部声明
	}
	| translation_unit external_declaration {
		
	}
	;

external_declaration:
	function_definition {
		//函数定义
		//printf("function_definition");
	}
	| declaration {
		//变量声明
		//printf("declaration");
	}
	;

function_definition:
	declaration_specifiers declarator declaration_list compound_statement {

	}
	| declaration_specifiers declarator compound_statement {

	}
	;

declaration_list:
	declaration {

	}
	| declaration_list declaration {

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

	fclose(yyin);
	return 0;
}