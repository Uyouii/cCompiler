#include"Praser.h"
#include"block.h"
#include "tools.h"
#include<map>
using namespace std;



Praser::Praser() {
	praserInit();
}

Praser::~Praser() {
	//print_map();
	print_code();
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


//分析变量初始化
void Praser::praser_init_declarator(string vartype, struct gramTree* node) {
	//cout << "at " << node->name << endl;
	struct gramTree* declarator = node->left;

	if (!declarator->right) {
		//获取变量的名字
		if (declarator->left->name == "IDENTIFIER") {
			struct gramTree* id = declarator->left;
			string var = id->content;
			if (lookupVar(var).size() == 0) {
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
			if (lookupVar(var).size() == 0) {
				varNode newvar;
				newvar.name = var;
				newvar.type = vartype;
				blockStack.back().varMap.insert({ var,newvar });
			}
			else error(declarator->left->line, "Variable multiple declaration.");
		}
		else error(declarator->left->line, "It's not a variable!");


		gramTree* initializer = declarator->right->right;
		if (initializer == NULL) {
			error(declarator->line, "Lack the initializer for variable.");
		}
		else {
			if (initializer->left->name == "assignment_expression") {
				string rvar = praser_assignment_expression(initializer->left);
				innerCode.addCode(declarator->left->content + " := " + rvar);
				string rtype = lookupVar(rvar);
				if (rtype != vartype)
					error(initializer->left->line, "Wrong type to variable " + declarator->left->content + ": " + 
					rtype + " to " + vartype);
			}
		}
	}
	else error(declarator->right->line, "Wrong value to variable");
}

string Praser::praser_assignment_expression(struct gramTree* assign_exp) {	//返回表达式的类型

	struct gramTree* logical_or_exp = assign_exp->left;
	
	return praser_logical_or_expression(logical_or_exp);
}

string Praser::praser_logical_or_expression(struct gramTree* logical_or_exp) {

	if(logical_or_exp->left->name == "logical_and_expression"){
		struct gramTree* logical_and_exp = logical_or_exp->left;
		return praser_logical_and_expression(logical_and_exp);
	}
	else if (logical_or_exp->left->name == "logical_or_expression") {
		//logical_or_expression -> logical_or_expression OR_OP logical_and_expression
		string temp1 = praser_logical_or_expression(logical_or_exp->left);
		string temp2 = praser_logical_and_expression(logical_or_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != "bool" || type2 != "bool") {
			error(logical_or_exp->left->right->line, "Logical Or operation should only used to bool. ");
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " || " + temp2);
		return tempname;

	}

}

string Praser::praser_logical_and_expression(struct gramTree* logical_and_exp) {
	
	if (logical_and_exp->left->name == "inclusive_or_expression") {
		gramTree* inclusive_or_exp = logical_and_exp->left;
		return praser_inclusive_or_expression(inclusive_or_exp);
	}
	else if (logical_and_exp->left->name == "logical_and_expression") {
		string temp1 = praser_exclusive_or_expression(logical_and_exp->left);
		string temp2 = praser_logical_and_expression(logical_and_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != "bool" || type2 != "bool") {
			error(logical_and_exp->left->right->line, "Logical And operation should only used to bool. ");
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " && " + temp2);
		return tempname;

	}
}

string Praser::praser_inclusive_or_expression(struct gramTree* inclusive_or_exp) {
	
	if (inclusive_or_exp->left->name == "exclusive_or_expression") {
		gramTree* exclusive_or_exp = inclusive_or_exp->left;
		return praser_exclusive_or_expression(exclusive_or_exp);
	}
	else if (inclusive_or_exp->left->name == "inclusive_or_expression") {
		string temp1 = praser_inclusive_or_expression(inclusive_or_exp->left);
		string temp2 = praser_exclusive_or_expression(inclusive_or_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != "int" || type2 != "int") {
			error(inclusive_or_exp->left->right->line, "Inclusive Or operation should only used to int. ");
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " | " + temp2);
		return tempname;
	}
}

string Praser::praser_exclusive_or_expression(struct gramTree *exclusive_or_exp) {
	
	if (exclusive_or_exp->left->name == "and_expression") {
		gramTree* and_exp = exclusive_or_exp->left;
		return praser_and_expression(and_exp);
	}
	else if (exclusive_or_exp->left->name == "exclusive_or_expression") {
		string temp1 = praser_exclusive_or_expression(exclusive_or_exp->left);
		string temp2 = praser_and_expression(exclusive_or_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != "int" || type2 != "int") {
			error(exclusive_or_exp->left->right->line, "Exclusive Or operation should only used to int. ");
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " ^ " + temp2);
		return tempname;
	}
}

string Praser::praser_and_expression(struct gramTree* and_exp) {
	if (and_exp->left->name == "equality_expression") {
		gramTree* equality_exp = and_exp->left;
		return praser_equality_expression(equality_exp);
	}
	else if (and_exp->left->name == "and_expression") {
		string temp1 = praser_and_expression(and_exp->left);
		string temp2 = praser_equality_expression(and_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != "int" || type2 != "int") {
			error(and_exp->left->right->line, "And operation should only used to int. ");
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " & " + temp2);
		return tempname;
	}
}

string Praser::praser_equality_expression(struct gramTree* equality_exp) {
	
	if (equality_exp->left->name == "relational_expression") {
		gramTree* relational_exp = equality_exp->left;
		return praser_relational_expression(relational_exp);
	}
	else if (equality_exp->left->right->name == "EQ_OP" || equality_exp->left->right->name == "NE_OP") {
		string op;
		if (equality_exp->left->right->name == "EQ_OP")
			op = "==";
		else op = "!=";

		string temp1 = praser_equality_expression(equality_exp->left);
		string temp2 = praser_relational_expression(equality_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != type2) {
			error(equality_exp->left->right->line, "Different type for " + temp1 + " and " + temp2);
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,"bool") });
		innerCode.addCode(tempname + " := " + temp1 + " " + op + " " + temp2);
		return tempname;
	}
}

string Praser::praser_relational_expression(struct gramTree* relational_exp) {
	if (relational_exp->left->name == "shift_expression") {
		gramTree* shift_exp = relational_exp->left;
		return praser_shift_expression(shift_exp);
	}
	else {
		string op = relational_exp->left->right->name;
		if (op == "LE_OP")
			op = "<=";
		else if (op == "GE_OP")
			op = ">=";
		if (op == ">" || op == "<" || op == ">=" || op == "<=") {
			string temp1 = praser_relational_expression(relational_exp->left);
			string temp2 = praser_shift_expression(relational_exp->left->right->right);

			string type1 = lookupVar(temp1);
			string type2 = lookupVar(temp2);

			if (type1 != type2) {
				error(relational_exp->left->right->line, "Different type for " + temp1 + " and " + temp2);
			}

			string tempname = "_temp" + inttostr(innerCode.tempNum);
			++innerCode.tempNum;

			blockStack.back().varMap.insert({ tempname,createVar(tempname,"bool") });
			innerCode.addCode(tempname + " := " + temp1 + " " + op + " " + temp2);
			return tempname;
		}
	}
}

string Praser::praser_shift_expression(struct gramTree*shift_exp) {
	if (shift_exp->left->name == "additive_expression") {
		gramTree* additive_exp = shift_exp->left;
		return praser_additive_expression(additive_exp);
	}
	else if (shift_exp->left->right->name == "LEFT_OP" || shift_exp->left->right->name == "RIGHT_OP") {
		string op;
		if (shift_exp->left->right->name == "LEFT_OP") {
			op = "<<";
		}
		else op = ">>";

		string temp1 = praser_shift_expression(shift_exp->left);
		string temp2 = praser_additive_expression(shift_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != "int" || type2 != "int" ) {
			error(shift_exp->left->right->line, "Shift operation should only used to int. ");
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " " + op + " " + temp2);
		return tempname;
	}
}

string Praser::praser_additive_expression(struct gramTree* additive_exp) {
	if (additive_exp->left->name == "multiplicative_expression") {
		gramTree* mult_exp = additive_exp->left;
		return praser_multiplicative_expression(mult_exp);
	}
	else if (additive_exp->left->right->name == "+" || additive_exp->left->right->name == "-") {
		string temp1 = praser_additive_expression(additive_exp->left);
		string temp2 = praser_multiplicative_expression(additive_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != type2) {
			error(additive_exp->left->right->line, "Different type for " + temp1 + " and " + temp2);
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " " + additive_exp->left->right->name + " " + temp2);
		return tempname;
	}
}

string Praser::praser_multiplicative_expression(struct gramTree* mult_exp) {

	if (mult_exp->left->name == "unary_expression") {
		gramTree* unary_exp = mult_exp->left;
		return praser_unary_expression(unary_exp);
	}
	else if (mult_exp->left->right->name == "*" || mult_exp->left->right->name == "/" || 
		mult_exp->left->right->name == "%") {
		string temp1 = praser_multiplicative_expression(mult_exp->left);
		string temp2 = praser_unary_expression(mult_exp->left->right->right);

		string type1 = lookupVar(temp1);
		string type2 = lookupVar(temp2);

		if (type1 != type2) {
			error(mult_exp->left->right->line, "Different type for " + temp1 + " and " + temp2);
		}

		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;

		blockStack.back().varMap.insert({ tempname,createVar(tempname,type1) });
		innerCode.addCode(tempname + " := " + temp1 + " " + mult_exp->left->right->name + " " + temp2);
		return tempname;

	}
}

string Praser::praser_unary_expression(struct gramTree*unary_exp) {
	if (unary_exp->left->name == "postfix_expression") {
		gramTree* post_exp = unary_exp->left;
		return praser_postfix_expression(post_exp);
	}
	else if (unary_exp->left->name == "INC_OP") {

	}
	else if (unary_exp->left->name == "DEC_OP") {

	}
	else if (unary_exp->left->name == "unary_operator") {

	}
}

string Praser::praser_postfix_expression(struct gramTree* post_exp) {
	if (post_exp->left->name == "primary_expression") {
		gramTree* primary_exp = post_exp->left;
		return praser_primary_expression(primary_exp);
	}
	else if (post_exp->left->right->name == "[") {
		//数组调用
	}
	else if (post_exp->left->right->name == "(") {
		//函数调用
	}
	else if (post_exp->left->right->name == "INC_OP") {

	}
	else if (post_exp->left->right->name == "DEC_OP") {

	}
}


string Praser::praser_primary_expression(struct gramTree* primary_exp) {
	if (primary_exp->left->name == "IDENTIFIER") {
		string content = primary_exp->left->content;
		string rtype = lookupVar(content);
		if (rtype.size() == 0) {
			error(primary_exp->left->line, "Undefined variable " + content);
		}
		return content;
	}
	else if (primary_exp->left->name == "TRUE" || primary_exp->left->name == "FALSE") {
		string content = primary_exp->left->content;
		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;
		
		blockStack.back().varMap.insert({ tempname,createVar(tempname,"bool") });
		innerCode.addCode(tempname + " := " + content);
		return tempname;
	}
	else if (primary_exp->left->name == "CONSTANT_INT") {
		string content = primary_exp->left->content;
		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;
	
		blockStack.back().varMap.insert({ tempname,createVar(tempname,"int") });
		innerCode.addCode(tempname + " := "  + content);
		return tempname;
	}
	else if (primary_exp->left->name == "CONSTANT_DOUBLE") {
		string content = primary_exp->left->content;
		string tempname = "_temp" + inttostr(innerCode.tempNum);
		++innerCode.tempNum;
		blockStack.back().varMap.insert({ tempname,createVar(tempname,"double")});
		innerCode.addCode(tempname + " := " + content);
		return tempname;
	}
	else if (primary_exp->left->name == "(") {

	}
}




//查找该变量在作用域内能不能访问的到，还没有找函数的形参
string Praser::lookupVar(string name) {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].varMap.find(name) != blockStack[i].varMap.end())
			return blockStack[i].varMap[name].type;
	}
	return "";
}


void Praser::error(int line, string error) {

	print_code();

	cout << "Error! line " << line << ": ";
	cout << error << endl;
	exit(1);
}

struct varNode Praser::createVar(string name, string type) {
	varNode var;
	var.name = name;
	var.type = type;
	return var;
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

void Praser::print_code() {
	innerCode.printCode();
}

