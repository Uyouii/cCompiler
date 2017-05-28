#ifndef _TREE_H_

#define _TREE_H_

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cstdarg>
#include<iostream>
#include<string>
using namespace std;
extern char *yytext;
extern int yylineno;//提供当前行数信息
extern struct gramTree *root;


struct gramTree {
    char* content;
    char* type;
    char* name;
    int line;       //所在代码行数
    struct gramTree *left;
    struct gramTree *right;
    double double_value;
    int    int_value;
    char *string_value;
};

struct gramTree* create_tree(string name, int num,...);
void eval(struct gramTree *head,int leavel);
char* my_substring(char* s, int begin, int end);

#endif