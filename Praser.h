#ifndef _PRASER_H_
#define _PRASER_H_
#include "block.h"
#include "tree.h"
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

	void praserInit();
	void praserGramTree(struct gramTree* node);

	struct gramTree* praser_declaration(struct gramTree* node);		//分析praser_declaration的节点
	void praser_init_declarator(string, struct gramTree* );	//分析praser_init_declarator的节点,返回该变量

	bool lookupVar(string name);


	void error(int line, string error);

	void print_map();
};




#endif // !_PRASER_H_