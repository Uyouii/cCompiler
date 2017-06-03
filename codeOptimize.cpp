#include "codeOptimize.h"
#include <iostream>
#include <set>
using namespace std;

Optimize::Optimize(vector<string> codelist) {
	//this->codelist = codelist;
	establishMap(codelist);
	dropTrumpTemp(codelist);
}

void Optimize::dropTrumpTemp(vector<string>& codelist) {
	set<int> lines;
	for (auto p = tempMessage.begin(); p != tempMessage.end(); p++) {
		//cout << p->first << " " << p->second.num << endl;
		if (p->second.num == 1) {
			int line = p->second.line;
			lines.insert(line);
		}
	}

	for (int i = 0; i < codelist.size(); i++) {
		if (lines.find(i) == lines.end()) {
			this->codelist.push_back(codelist[i]);
		}
	}
}

void Optimize::establishMap(vector<string>& codelist) {
	for (int i = 0; i < codelist.size(); i++) {
		string str = codelist[i];
		int begin = 0;
		int w = str.find("temp", begin);
		while (w != string::npos) {

			int end = str.find(" ", w);
			string name = str.substr(w, end - w);

			if (tempMessage.find(name) != tempMessage.end()) {
				if (str.find("CALL") != string::npos)
					tempMessage[name].num += 1000;
				tempMessage[name].num++;
			}
			else {
				Message m;
				m.line = i;
				m.num = 1;
				if (str.find("CALL") != string::npos)
					m.num += 1000;
				tempMessage.insert({ name,m });
			}
			begin = end;
			w = str.find("temp", begin);



		}
	}
}

vector<string> Optimize::getCodeList() {
	return this->codelist;
}