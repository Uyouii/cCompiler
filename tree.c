#include"tree.h"

struct gramTree* create_tree(char* name, int num,...) {
    va_list valist;
    struct gramTree* head = (struct gramTree* )malloc(sizeof(struct gramTree));
    if(!head) {
        printf("Out of space \n");
        exit(0);
    }   
    head->left = NULL;
    head->right = NULL;
    head->content = NULL;
    struct gramTree* temp = NULL;
    head->name = name;
    va_start(valist,num);
    if(num > 0) {
        temp = va_arg(valist,struct gramTree*);
        head->left = temp;
        head->line = temp->line;
        if(num == 1) {
            //head->content = temp->content;
            if(temp->content != NULL) {
                head->content = (char*)malloc(strlen(temp->content) + 1);
                strcpy(head->content,temp->content);
            }
            else head->content = NULL;
        }
        else {
            for(int i = 1; i < num; ++i ) {
                temp->right = va_arg(valist,struct gramTree*);
                temp = temp->right;
            }
        }
    }
    else {
        int line = va_arg(valist,int);
        head->line = line;
        if(strcmp(head->name,"CONSTANT_INT") == 0) {
            int value;
            if(strlen(yytext) > 1 && yytext[0] == '0' && yytext[1] != 'x') {
                sscanf(yytext,"%o",&value); //8进制整数
            }
            else if(strlen(yytext) > 1 && yytext[1] == 'x'){
                sscanf(yytext,"%x",&value); //16进制整数
            }
            else value = atoi(yytext);      //10进制整数
            head->int_value = value;
            //printf("%d",value);
        }
        else if(strcmp(head->name,"CONSTANT_DOUBLE") == 0) {
            head->double_value=atof(yytext);
        }
        else {
            head->content = (char*)malloc(strlen(yytext)+1);
            strcpy(head->content,yytext);
            
        }
    }
    return head;
}

void eval(struct gramTree *head,int leavel) {
    if(head!=NULL) {
        if(head->line!=-1) {
            for(int i=0;i<leavel;++i) {
                printf("|  ");
            }
            printf("%s",head->name);
            if((strcmp(head->name,"IDENTIFIER")==0)||(strcmp(head->name,"BOOL")==0)|| (strcmp(head->name,"INT")==0) || 
            (strcmp(head->name,"CHAR")==0) || (strcmp(head->name,"DOUBLE")==0)) {
                printf(":%s",head->content);
            }
            else if(strcmp(head->name,"CONSTANT_INT")==0) {
                printf(":%d ",head->int_value);
            }
            else if(strcmp(head->name,"CONSTANT_DOUBLE")==0) {
                printf(":%f ",head->double_value);
            }
            else if(strcmp(head->name,"STRING_LITERAL")==0) {
                printf(":%s",head->content);
            }
            else {
                printf("<%d>",head->line);
            }
            printf("\n");
        }
        eval(head->left,leavel+1);
        eval(head->right,leavel);
    }
}
