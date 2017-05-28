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


class gramTree {
public:
    string content;
    string type;
    string name;
    int line;       //所在代码行数
    gramTree *left;
    gramTree *right;
    double double_value;
    int int_value;
    string string_value;
};

extern gramTree *root;

gramTree* create_tree(string name, int num,...);
void eval(gramTree *head,int leavel);
char* my_substring(char* s, int begin, int end);

#endif