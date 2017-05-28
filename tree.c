#include"tree.h"


gramTree* create_tree(string name, int num,...) {
    va_list valist;
    gramTree* head = new gramTree();
    if(!head) {
        printf("Out of space \n");
        exit(0);
    }   
    head->left = NULL;
    head->right = NULL;
    head->content = "";
    gramTree* temp = NULL;
    head->name = name;
    va_start(valist,num);
    if(num > 0) {
        temp = va_arg(valist,gramTree*);
        head->left = temp;
        head->line = temp->line;
        if(num == 1) {
            //head->content = temp->content;
            if(temp->content.size() > 0) {
                head->content = temp->content;
            }
            else head->content = "";
        }
        else {
            for(int i = 1; i < num; ++i ) {
                temp->right = va_arg(valist,gramTree*);
                temp = temp->right;
            }
        }
    }
    else {
        int line = va_arg(valist,int);
        head->line = line;
        if(head->name == "CONSTANT_INT") {
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
        else if(head->name == "CONSTANT_DOUBLE") {
            head->double_value=atof(yytext);
        }
        else if(head->name == "TRUE") {
            head->int_value = 1;
        }
        else if(head->name == "FALSE") {
            head->int_value = 0;
        }
        else if(head->name == "STRING_LITERAL") {
            head->string_value = my_substring(yytext,1,strlen(yytext) - 1);
        }
        else {
            head->content = yytext;
        }
    }
    return head;
}

void eval(gramTree *head,int leavel) {
    if(head!=NULL) {
        string Name = head->name;
        if(head->line!=-1) {
            for(int i=0;i<leavel;++i) {
                cout << "| ";
            }
           cout << head->name;
        
            if(head->name == "IDENTIFIER"||head->name == "BOOL"|| head->name == "INT" || 
            head->name == "CHAR" || head->name == "DOUBLE") {
                cout << ":" << head->content;
            }
            else if(head->name == "CONSTANT_INT" || head->name == "TRUE" || head->name == "FALSE") {
                cout << ":" << head->int_value << " ";
            }
            else if(head->name == "CONSTANT_DOUBLE") {
                cout << ":" << head->double_value << " ";
            }
            else if(head->name=="STRING_LITERAL") {
                cout << ":" << head->string_value;
            }
            else {
                cout << " <" << head->line << ">";
            }
            cout << endl;
        }
        eval(head->left,leavel+1);
        eval(head->right,leavel);
    }
}
char* my_substring(char* s, int begin, int end) {
    char* result = (char*)malloc(end - begin + 1);
    int i;
    for(i = begin; i < end; i++) {
        result[i - begin] = s[i];
    }
    result[i - begin] = 0;
    return result;
}
