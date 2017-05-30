#include "innerCode.h"

InnerCode::InnerCode() {

}

void InnerCode::addCode(string str) {
	codeList.push_back(str);
}

void InnerCode::printCode() {
	cout << "\n===============INNERCODE===============" << endl;
	for (string s : codeList) {
		cout << s << endl;
	}
}