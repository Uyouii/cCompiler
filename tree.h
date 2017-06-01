#ifndef _TREE_H_

#define _TREE_H_

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cstdarg>
#include<iostream>
#include<string>
extern char *yytext;
extern int yylineno;//提供当前行数信息
using namespace std;


struct gramTree {
    string content;
    //string type;
    string name;
    int line;       //所在代码行数
    struct gramTree *left;
    struct gramTree *right;
   /* double double_value;
    int int_value;
    string string_value;*/
};

extern struct gramTree *root;

struct gramTree* create_tree(string name, int num,...);
void eval(struct gramTree *head,int leavel);
char* my_substring(char* s, int begin, int end);
void freeGramTree(gramTree* node);

#endif