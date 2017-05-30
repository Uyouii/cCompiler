#include "tools.h"
#include <cstdlib>

string inttostr(int n) {
	char buf[10];
	sprintf(buf, "%d", n);
	string b = buf;
	return b;
}

int strtoint(string s) {
	int n;
	n = atoi(s.c_str());
	return n;
}