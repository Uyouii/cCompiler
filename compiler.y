%{
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
%}

%union{
	struct gramTree* gt;
}

%token <gt> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_DOUBLE
%token <gt> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <gt> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <gt> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <gt> XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token <gt> CHAR INT DOUBLE VOID BOOL 

%token <gt> CASE IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token <gt> TRUE FALSE

%token <gt> ';' ',' ':' '=' '[' ']' '.' '&' '!' '~' '-' '+' '*' '/' '%' '<' '>' '^' '|' '?' '{' '}' '(' ')'

%type <gt> primary_expression postfix_expression argument_expression_list unary_expression unary_operator
%type <gt> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type <gt> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <gt> assignment_expression assignment_operator expression

%type <gt> declaration init_declarator_list init_declarator type_specifier

%type <gt> declarator 

%type <gt> parameter_list parameter_declaration identifier_list
%type <gt> abstract_declarator initializer initializer_list designation designator_list
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
	|
	TRUE {
		$$ = create_tree("primary_expression",1,$1);
		// $$->type = "bool";
		// $$->int_value = $1->int_value;
	}
	|
	FALSE {
		$$ = create_tree("primary_expression",1,$1);
		// $$->type = "bool";
		// $$->int_value = $1->int_value;
	}
	| CONSTANT_INT {
		//printf("%d",$1->int_value);
		$$ = create_tree("primary_expression",1,$1);
		// $$->type = "int";
		// $$->int_value = $1->int_value;
		
	}
	| CONSTANT_DOUBLE {
		$$ = create_tree("primary_expression",1,$1);
		// $$->type = "double";
		// $$->double_value = $1->double_value;
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
		//数组调用
	}
	| 	postfix_expression '(' ')'{
		$$ = create_tree("postfix_expression",3,$1,$2,$3);
		//函数调用
	}
	| 	postfix_expression '(' argument_expression_list ')'{
		$$ = create_tree("postfix_expression",4,$1,$2,$3,$4);
		//函数调用
	}
	| 	postfix_expression INC_OP{
		//++
		$$ = create_tree("postfix_expression",2,$1,$2);
	}
	| 	postfix_expression DEC_OP{
		//--
		$$ = create_tree("postfix_expression",2,$1,$2);
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
	| 	unary_operator unary_expression{
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	;

/*单目运算符*/
unary_operator:
	'+' {
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

/*可乘表达式*/
multiplicative_expression:
	unary_expression {
		$$ = create_tree("multiplicative_expression",1,$1);
	}
	| multiplicative_expression '*' unary_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '/' unary_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '%' unary_expression {
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

/*赋值表达式*/
assignment_expression:
	logical_or_expression {
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


declaration:
	type_specifier ';' {
		$$ = create_tree("declaration",2,$1,$2); //?
	}
	| type_specifier init_declarator_list ';' {
		$$ = create_tree("declaration",3,$1,$2,$3);
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
	;



declarator:
	IDENTIFIER {
		//变量
		$$ = create_tree("declarator",1,$1);
	}
	| '(' declarator ')' {
		//.....
		$$ = create_tree("declarator",3,$1,$2,$3);
	}
	| declarator '[' assignment_expression ']' {
		//数组
		//printf("assignment_expression");
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '[' '*' ']' {
		//....
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '[' ']' {
		//数组
		$$ = create_tree("declarator",3,$1,$2,$3);
	}
	| declarator '(' parameter_list ')' {
		//函数
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '(' identifier_list ')' {
		//函数
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '(' ')' {
		//函数
		$$ = create_tree("declarator",3,$1,$2,$3);
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
	type_specifier declarator {
		$$ = create_tree("parameter_declaration",2,$1,$2);
	}
	| type_specifier abstract_declarator {
		$$ = create_tree("parameter_declaration",2,$1,$2);
	}
	| type_specifier {
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

abstract_declarator:
	'(' abstract_declarator ')' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| '[' ']' {
		$$ = create_tree("abstract_declarator",2,$1,$2);
	}
	| '[' assignment_expression ']' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '[' ']' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '[' assignment_expression ']' {
		$$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);
	}
	| '[' '*' ']' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '[' '*' ']' {
		$$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);
	}
	| '(' ')' {
		$$ = create_tree("abstract_declarator",2,$1,$2);
	}
	| '(' parameter_list ')' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '(' ')' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '(' parameter_list ')' {
		$$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);
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
	'[' logical_or_expression ']' {
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
	| CASE logical_or_expression ':' statement {
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
		$$ = create_tree("translation_unit",1,$1);
	}
	| translation_unit external_declaration {
		$$ = create_tree("translation_unit",2,$1,$2);
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
	type_specifier declarator declaration_list compound_statement {
		$$ = create_tree("function_definition",4,$1,$2,$3,$4);
	}
	| type_specifier declarator compound_statement {
		$$ = create_tree("function_definition",3,$1,$2,$3);
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
	
	//freopen("output/output.txt","w", stdout);
	yyparse();
	printf("\n");
	//eval(root,0);	//输出语法分析树

	Praser praser;

	freeGramTree(root);

	fclose(yyin);
	return 0;
}