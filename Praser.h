#ifndef _PRASER_H_
#define _PRASER_H_
#include "block.h"
#include "tree.h"
#include "innerCode.h"
#include <vector>
#include <set>

extern struct gramTree* root;


using namespace std;

class Praser {
public:

	Praser();	//构造函数
	~Praser();	//析构函数

private:
	map<string, funcNode> funcPool;			//函数池
	vector<Block> blockStack;				//维护的栈
	InnerCode innerCode;					//中间代码生成工具
	//set<string> build_in_function;

	void praserInit();
	void praserGramTree(struct gramTree* node);

	
	struct gramTree* praser_declaration(struct gramTree* node);		//分析praser_declaration的节点
	void praser_init_declarator_list(string, struct gramTree*);
	void praser_init_declarator(string, struct gramTree* );			//分析praser_init_declarator的节点

	struct gramTree* praser_function_definition(struct gramTree*);
	void praser_parameter_list(struct gramTree*,string,bool);			//获取函数形参列表
	void praser_parameter_declaration(struct gramTree*, string,bool);	//获取函数单个形参

	struct gramTree* praser_statement(struct gramTree*);

	void praser_expression_statement(struct gramTree*);
	varNode praser_expression(struct gramTree*);

	void praser_argument_expression_list(struct gramTree*,string);

	void praser_jump_statement(struct gramTree*);
	void praser_compound_statement(struct gramTree*);
	void praser_selection_statement(struct gramTree*);
	void praser_iteration_statement(struct gramTree*);

	varNode praser_assignment_expression(struct gramTree*);			//赋值表达式
	varNode praser_logical_or_expression(struct gramTree*);			//逻辑或表达式
	varNode praser_logical_and_expression(struct gramTree*);		//逻辑或表达式
	varNode praser_inclusive_or_expression(struct gramTree*);
	varNode praser_exclusive_or_expression(struct gramTree*);
	varNode praser_and_expression(struct gramTree*);
	varNode praser_equality_expression(struct gramTree*);
	varNode praser_relational_expression(struct gramTree*);
	varNode praser_shift_expression(struct gramTree*);
	varNode praser_additive_expression(struct gramTree*);
	varNode praser_multiplicative_expression(struct gramTree*);
	varNode praser_unary_expression(struct gramTree*);
	varNode praser_postfix_expression(struct gramTree*);
	varNode praser_primary_expression(struct gramTree*);


	string lookupVar(string name);			//返回变量类型，找不到返回""
	bool lookupCurruntVar(string name);		//查找当前块的var
	struct varNode lookupNode(string name);	//返回变量节点
	string getFuncRType();
	string getArrayType(string);
	struct arrayNode getArrayNode(string);

	int getBreakBlockNumber();

	struct varNode createTempVar(string name, string type);

	void error(int line, string error);

	void print_map();
	void print_code();
};




#endif // !_PRASER_H_