# C语言编译器

lex和yacc编写的c语言编译器

词法分析与语法分析的原始文件来源于：http://www.quut.com/c/ANSI-C-grammar-l-1998.html
和 http://www.quut.com/c/ANSI-C-grammar-l-1998.html

## 运行
windows命令行输入：
```
flex compiler.l
bison -vdty compiler.y
gcc -std=c11 -o compiler tree.c lex.yy.c y.tab.c
compiler.exe test/test.c
```
或者
```
makefile.bat
```
输出在output/output.txt文件中


