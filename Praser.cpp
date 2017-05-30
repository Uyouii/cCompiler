#include"Praser.h"
#include"block.h"
#include<map>
using namespace std;



Praser::Praser() {
	praserInit();
}

Praser::~Praser() {
	print_map();
}

void Praser::praserInit() {
	Block wholeBlock;
	blockStack.push_back(wholeBlock);
	praserGramTree(root);		//开始分析语法树
}

void Praser::praserGramTree(struct gramTree* node) {
	//cout << "at " << node->name << endl;
	if (node == NULL || node->line == -1)
		return;

	if (node->name == "declaration") {
		node = praser_declaration(node);
	}

	if (node != NULL) {

		praserGramTree(node->left);
		praserGramTree(node->right);
	}
}

struct gramTree* Praser::praser_declaration(struct gramTree *node) {
	//cout << "at " << node->name << endl;
	//node = declaration
	struct gramTree* begin = node->left;	//begin:type_specifier
	if (begin->right->name == ";")
		return node->right;
	
	string vartype = begin->left->content;

	if (vartype == "void") {
		error(begin->left->line,"void type can't assign to variable");	//报错
 	}
	struct gramTree* decl = begin->right->left;	//init_declarator_list


	while (decl->right) {
		praser_init_declarator(vartype, decl->right->right);
		decl = decl->left;
	}
	praser_init_declarator(vartype, decl);
	return node->right;

}
void Praser::praser_init_declarator(string vartype, struct gramTree* node) {
	//cout << "at " << node->name << endl;
	struct gramTree* declarator = node->left;

	if (!declarator->right) {
		//获取变量的名字
		if (declarator->left->name == "IDENTIFIER") {
			struct gramTree* id = declarator->left;
			string var = id->content;
			if (blockStack.back().varMap.find(var) == blockStack.back().varMap.end()) {
				varNode newvar;
				newvar.name = var;
				newvar.type = vartype;
				blockStack.back().varMap.insert({ var,newvar });
			}
			else error(declarator->left->line, "Variable multiple declaration.");
		}
		else error(declarator->left->line, "It's not a variable!");
	}
	else if (declarator->right->name == "=") {	//有初始化
		//获取变量的名字
		if (declarator->left->name == "IDENTIFIER") {
			struct gramTree* id = declarator->left;
			string var = id->content;
			if (!lookupVar(var)) {
				varNode newvar;
				newvar.name = var;
				newvar.type = vartype;
				blockStack.back().varMap.insert({ var,newvar });
			}
			else error(declarator->left->line, "Variable multiple declaration.");
		}
		else error(declarator->left->line, "It's not a variable!");
	}
	else error(declarator->right->line, "Wrong value to variable");
}

void Praser::error(int line, string error) {
	cout << "Error! line " << line << ": ";
	cout << error << endl;
	exit(1);
}

bool Praser::lookupVar(string name) {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].varMap.find(name) != blockStack[i].varMap.end())
			return true;
	}
	return false;
}

void Praser::print_map() {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		cout << "Block " << i << endl;
		for (auto it = blockStack[i].varMap.begin(); it != blockStack[i].varMap.end(); it++) {
			cout << "     " << it->first << " " << it->second.type << endl;
		}
	}
}

