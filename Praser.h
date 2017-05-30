#ifndef _PRASER_H_
#define _PRASER_H_
#include "block.h"
#include "tree.h"
#include "innerCode.h"
#include <vector>

extern struct gramTree* root;


using namespace std;

class Praser {
public:

	Praser();	//构造函数
	~Praser();	//析构函数

private:
	map<string, funcNode> funcPool;			//函数池
	vector<Block> blockStack;				//维护的栈
	InnerCode innerCode;

	void praserInit();
	void praserGramTree(struct gramTree* node);

	struct gramTree* praser_declaration(struct gramTree* node);		//分析praser_declaration的节点
	void praser_init_declarator(string, struct gramTree* );			//分析praser_init_declarator的节点,返回该变量

	string praser_assignment_expression(struct gramTree*);			//赋值表达式
	string praser_logical_or_expression(struct gramTree*);			//逻辑或表达式
	string praser_logical_and_expression(struct gramTree*);			//逻辑或表达式
	string praser_inclusive_or_expression(struct gramTree*);	
	string praser_exclusive_or_expression(struct gramTree*);
	string praser_and_expression(struct gramTree*);
	string praser_equality_expression(struct gramTree*);
	string praser_relational_expression(struct gramTree*);
	string praser_shift_expression(struct gramTree*);
	string praser_additive_expression(struct gramTree*);
	string praser_multiplicative_expression(struct gramTree*);
	string praser_unary_expression(struct gramTree*);
	string praser_postfix_expression(struct gramTree*);
	string praser_primary_expression(struct gramTree*);


	string lookupVar(string name);			//返回变量类型，找不到返回""s

	struct varNode createVar(string name, string type);


	void error(int line, string error);

	void print_map();
	void print_code();
};




#endif // !_PRASER_H_