
%{
#include "y.tab.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "tree.h"
#include <iostream>
using namespace std;

void count(void);
void comment();
int check_type();
int column = 0;

%}

%option yylineno

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			([Ee][+-]?{D}+)
P           ([Pp][+-]?{D}+)
FS			(f|F|l|L)
IS          ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%%

"/*"			{ comment();/*注释*/}
"//"[^\n]*      { /* consume //-comment */ }

"bool"			{ count(); yylval.gt =create_tree("BOOL",0,yylineno); 		return(BOOL);	}
"int"			{ count(); yylval.gt =create_tree("INT",0,yylineno);  		return(INT); }
"char"			{ count(); yylval.gt =create_tree("CHAR",0,yylineno); 		return(CHAR); }
"double"		{ count(); yylval.gt =create_tree("DOUBLE",0,yylineno); 	return(DOUBLE); }
"break"			{ count(); yylval.gt =create_tree("BREAK",0,yylineno); 		return(BREAK); }
"case"			{ count(); yylval.gt =create_tree("CASE",0,yylineno); 		return(CASE); }
"continue"		{ count(); yylval.gt =create_tree("CONTINUE",0,yylineno); 	return(CONTINUE); }
"do"			{ count(); yylval.gt =create_tree("DO",0,yylineno);			return(DO); }
"else"			{ count(); yylval.gt =create_tree("ELSE",0,yylineno);		return(ELSE); }
"enum"			{ count(); yylval.gt =create_tree("ENUM",0,yylineno);		return(ENUM); }
"for"			{ count(); yylval.gt =create_tree("FOR",0,yylineno);		return(FOR); }
"goto"			{ count(); yylval.gt =create_tree("GOTO",0,yylineno);		return(GOTO); }
"if"			{ count(); yylval.gt =create_tree("IF",0,yylineno);			return(IF); }
"return"		{ count(); yylval.gt =create_tree("RETURN",0,yylineno);		return(RETURN); }
"struct"		{ count(); yylval.gt =create_tree("STRUCT",0,yylineno);		return(STRUCT); }
"switch"		{ count(); yylval.gt =create_tree("SWITCH",0,yylineno);		return(SWITCH); }
"union"			{ count(); yylval.gt =create_tree("UNION",0,yylineno);		return(UNION); }
"void"			{ count(); yylval.gt =create_tree("VOID",0,yylineno);		return(VOID); }
"while"			{ count(); yylval.gt =create_tree("WHILE",0,yylineno);		return(WHILE); }

{L}({L}|{D})* 	{count(); yylval.gt =create_tree("IDENTIFIER",0,yylineno);	return(check_type());/*IDENTIFIER*/ }

0[xX]{H}+{IS}?	{ count(); yylval.gt =create_tree("CONSTANT_INT",0,yylineno);	return(CONSTANT_INT); /*16进制*/}
0[0-7]*{IS}?	{ count(); yylval.gt =create_tree("CONSTANT_INT",0,yylineno);	return(CONSTANT_INT); /*8进制*/}
[1-9]{D}*{IS}?	{ count(); yylval.gt =create_tree("CONSTANT_INT",0,yylineno);	return(CONSTANT_INT); /*10进制*/}
L?'(\\.|[^\\'\n])+'		{ count(); return(CONSTANT); }

{D}+{E}{FS}?				{ count(); yylval.gt =create_tree("CONSTANT_DOUBLE",0,yylineno);	return(CONSTANT_DOUBLE); /*浮点数*/}
{D}*"."{D}+{E}?{FS}?		{ count(); yylval.gt =create_tree("CONSTANT_DOUBLE",0,yylineno);	return(CONSTANT_DOUBLE); /*浮点数*/}
{D}+"."{D}*{E}?{FS}?		{ count(); yylval.gt =create_tree("CONSTANT_DOUBLE",0,yylineno);	return(CONSTANT_DOUBLE); /*浮点数*/}
0[xX]{H}+{P}{FS}?			{ count(); return(CONSTANT); }
0[xX]{H}*"."{H}+{P}?{FS}?   { count(); return(CONSTANT); }
0[xX]{H}+"."{H}*{P}?{FS}?   { count(); return(CONSTANT); }


L?\"(\\.|[^\\"\n])*\"	{ count();  yylval.gt =create_tree("STRING_LITERAL",0,yylineno);	return(STRING_LITERAL); /*字符串常量*/}

">>="	{ count(); yylval.gt =create_tree("RIGHT_ASSIGN",0,yylineno);	return(RIGHT_ASSIGN); }
"<<="	{ count(); yylval.gt =create_tree("LEFT_ASSIGN",0,yylineno);	return(LEFT_ASSIGN); }
"+="	{ count(); yylval.gt =create_tree("ADD_ASSIGN",0,yylineno);		return(ADD_ASSIGN); }
"-="	{ count(); yylval.gt =create_tree("SUB_ASSIGN",0,yylineno);		return(SUB_ASSIGN); }
"*="	{ count(); yylval.gt =create_tree("MUL_ASSIGN",0,yylineno);		return(MUL_ASSIGN); }
"/="	{ count(); yylval.gt =create_tree("DIV_ASSIGN",0,yylineno);		return(DIV_ASSIGN); }
"%="	{ count(); yylval.gt =create_tree("MOD_ASSIGN",0,yylineno);		return(MOD_ASSIGN); }
"&="	{ count(); yylval.gt =create_tree("AND_ASSIGN",0,yylineno);		return(AND_ASSIGN); }
"^="	{ count(); yylval.gt =create_tree("XOR_ASSIGN",0,yylineno);		return(XOR_ASSIGN); }
"|="	{ count(); yylval.gt =create_tree("OR_ASSIGN",0,yylineno);		return(OR_ASSIGN); }
">>"	{ count(); yylval.gt =create_tree("RIGHT_OP",0,yylineno);		return(RIGHT_OP); }
"<<"	{ count(); yylval.gt =create_tree("LEFT_OP",0,yylineno);		return(LEFT_OP); }
"++"	{ count(); yylval.gt =create_tree("INC_OP",0,yylineno);			return(INC_OP); }
"--"	{ count(); yylval.gt =create_tree("DEC_OP",0,yylineno);			return(DEC_OP); }
"->"	{ count(); yylval.gt =create_tree("PTR_OP",0,yylineno);			return(PTR_OP); }
"&&"	{ count(); yylval.gt =create_tree("AND_OP",0,yylineno);			return(AND_OP); }
"||"	{ count(); yylval.gt =create_tree("OR_OP",0,yylineno);			return(OR_OP); }
"<="	{ count(); yylval.gt =create_tree("LE_OP",0,yylineno);			return(LE_OP); }
">="	{ count(); yylval.gt =create_tree("GE_OP",0,yylineno);			return(GE_OP); }
"=="	{ count(); yylval.gt =create_tree("EQ_OP",0,yylineno);			return(EQ_OP); }
"!="	{ count(); yylval.gt =create_tree("NE_OP",0,yylineno);			return(NE_OP); }
";"		{ count(); yylval.gt =create_tree(";",0,yylineno);	return(';'); }
","		{ count(); yylval.gt =create_tree(",",0,yylineno);	return(','); }
":"		{ count(); yylval.gt =create_tree(":",0,yylineno);	return(':'); }
"="		{ count(); yylval.gt =create_tree("=",0,yylineno);	return('='); }
"["		{ count(); yylval.gt =create_tree("[",0,yylineno);	return('['); }
"]"		{ count(); yylval.gt =create_tree("]",0,yylineno);	return(']'); }
"."		{ count(); yylval.gt =create_tree(".",0,yylineno);	return('.'); }
"&"		{ count(); yylval.gt =create_tree("&",0,yylineno);	return('&'); }
"!"		{ count(); yylval.gt =create_tree("!",0,yylineno);	return('!'); }
"~"		{ count(); yylval.gt =create_tree("~",0,yylineno);	return('~'); }
"-"		{ count(); yylval.gt =create_tree("-",0,yylineno);	return('-'); }
"+"		{ count(); yylval.gt =create_tree("+",0,yylineno);	return('+'); }
"*"		{ count(); yylval.gt =create_tree("*",0,yylineno);	return('*'); }
"/"		{ count(); yylval.gt =create_tree("/",0,yylineno);	return('/'); }
"%"		{ count(); yylval.gt =create_tree("%",0,yylineno);	return('%'); }
"<"		{ count(); yylval.gt =create_tree("<",0,yylineno);	return('<'); }
">"		{ count(); yylval.gt =create_tree(">",0,yylineno);	return('>'); }
"^"		{ count(); yylval.gt =create_tree("^",0,yylineno);	return('^'); }
"|"		{ count(); yylval.gt =create_tree("|",0,yylineno);	return('|'); }
"?"		{ count(); yylval.gt =create_tree("?",0,yylineno);	return('?'); }
"{"		{ count(); yylval.gt =create_tree("{",0,yylineno);	return('{'); }
"}"		{ count(); yylval.gt =create_tree("}",0,yylineno);	return('}'); }
"("		{ count(); yylval.gt =create_tree("(",0,yylineno);	return('('); }
")"		{ count(); yylval.gt =create_tree(")",0,yylineno);	return(')'); }

[\t\v\n\f ]		{ count();}
.			{ /* Add code to complain about unmatched characters */ }

%%


int yywrap() {
	return 1;
}


void comment() {
	column = 0;
	char c, prev = 0;
	
	while (cin >> c)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	printf("unterminated comment");
}



void count(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 4 - (column % 4);
		else
			column++;
	ECHO;
}


int check_type() {
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return TYPE_NAME;
*
*	return IDENTIFIER;
*/

/*
*	it actually will only return IDENTIFIER
*/

	return IDENTIFIER;
}