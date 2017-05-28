flex compiler.l
bison -vdty compiler.y
gcc -std=c11 -o compiler tree.c lex.yy.c y.tab.c
compiler.exe test/test.c


# compiler:  tree.o	yacc.o  lex.o
# 	gcc -std=c11 -o compiler  tree.o yacc.o lex.o

# yacc.o:y.tab.c
# 	gcc -std=c11 -c y.tab.c

# lex.o :lex.yy.c
# 	gcc -std=c11 -c lex.yy.c

# tree.o: tree.c 
# 	gcc -std=c11 -c tree.c


