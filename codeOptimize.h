#ifndef _CODEOPTIMIZE_H_
#define _CODEOPTIMIZE_H_
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Message {
	int line = -1;
	int num = 0;
};

class Optimize {
private:
	vector<string> codelist;
	map<string, Message> tempMessage;

	void establishMap(vector<string>&);
	void dropTrumpTemp();			//除去无用的临时变量

public:
	Optimize(vector<string>);
	vector<string> getCodeList();

};

#endif // !_CODEOPTIMIZE_H_