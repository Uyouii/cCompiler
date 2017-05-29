flex compiler.l
bison -vdty compiler.y
g++ -std=c++11 -o compiler tree.cpp lex.yy.c y.tab.c
compiler.exe test/test.c
