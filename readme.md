# C语言编译器

lex和yacc编写的c语言编译器

词法分析与语法分析的原始文件来源于：http://www.quut.com/c/ANSI-C-grammar-l-1998.html
和 http://www.quut.com/c/ANSI-C-grammar-l-1998.html

实现了C语言除了struct和指针几乎所有的语法。



## 运行

环境要求：flex bison g++11 python3

#### 中间代码生成
windows命令行输入：
```
flex compiler.l
bison -vdty compiler.y
g++ -std=c++11 -o compiler tree.cpp Praser.cpp innerCode.cpp tools.cpp codeOptimize.cpp lex.yy.c y.tab.c
compiler.exe test/test.c
```
或者
```
makefile.bat
```

#### 目标代码生成
进入objectcode文件夹，命令行输入
```
python objectcode.py
```
objectcode.py读取的源文件为inter.txt，生成的mips汇编码在result.asm文件中

## 中间代码格式定义
| 语法  | 描述 |
| :---: | :---- |
| LABEL label1 : | 定义标签 label1  |
| FUNCTION f :  | 定义函数 f  | 
| x := y | 赋值操作，将变量 y 赋值给 x | 
| x := &y |  取地址操作，将 y 的地址赋值给 x | 
| x := *y | 取以 y 值为地址的内存单元的内容赋给 x | 
| *x := y | 将 y 值赋给以 x 值为地址的内存单元 | 
| GOTO label1| 无条件跳转至 lable1 | 
| IF x [relop] y GOTO z | 如果 x 与 y 满足[relop]关系则跳转至标号 z | 
| RETURN x | 退出当前函数并返回 x 值 | 
| DEC x [size] | 内存空间申请，大小为[size] | 
| ARG x | 为函数传入实参 x | 
| x := CALL f | 调用函数 f，并将其返回值赋给 x | 
| CALL f | 调用函数 f | 
| PARAM x | 函数形参声明 | 
| x := y [op] z | 将变量 y 和 z 进行 op 运算的结果传递给 x | 
| x := #10 | 将立即数 10 的值传递给变量 x | 

### 支持运算符
| 类别  |  |
| :---: | :---- |
| 单目运算符 | + - ++ -- |
| 关系运算符 | < > <= >= == != | 
| 算数运算符 | + - * / % \| & ^ | 
| 移位运算符 | << >> | 
| 逻辑运算符 | \|\| && | 
| 赋值运算符 | = += -= *= /= %= >>= <<= &= ^= |= |

### 函数规则
函数名不能重复。函数可以事先声明，也可以直接定义。 

函数定义时会检测函数有无声明过，如果函数事先声明，则检测函数定义的参数个数和类型与函数声明时的参数和类型是否相等。如果不等则报错。 

在调用函数时会检测函数有无定义或者声明，如果函数已经定义或者声明，则检测函数调用时的参数个数和类型是否符合函数定义或者声明的标准，如果不符合则报错。 

PARAM 语句在每个函数开头使用，对于函数中形参的数目和名称进行声明。例如，若一个函数 func 有三个形参 a、b、c，则该函数的函数体内前三条语句为：PARAM a、PARAM b 和 PARAM c。 

CALL 和 ARG 语句负责进行函数调用。在调用一个函数之前，我们先使用ARG 语句传入所有实参，随后使用 CALL 语句调用该函数并存储返回值。仍以函数 func 为例，如果我们需要依次传入三个实参 x、y、z，并将返回值保存临时变量 t1 中，则可分别表述为：ARG z、ARG y、ARG x 和 t1 := CALL func。注意 ARG 传入参数的顺序和 PARAM 声明参数的顺序正好相反。ARG 语句的参数可以是变量、以#开头的常数或以  *  开头的某个地址对应的变量。 

在处理中间代码时内置了两个函数 print 和 read，read 用于用户从控制台读取一个整型变量，无形参，返回值为 int。print 函数用于将一个整形变量打印到控制台上，形参为一个 int 型变量，无返回值。



## 示例：
#### 示例1:计算阶乘
源代码：
```c
int fact(int n){
	int temp;
    if(n==1)
        return n;
    else{
    	temp=(n*fact(n-1));
    	return temp;
    }
}


int main()
{
    int result,times;
    times=read();
    for(int i=0;i<times;i++){
    	int m = read();
    	if( m > 1) {
        	result=fact(m);
        }
        else
            result = 1;
        print(result);
	}
    return 0;
}

```
中间代码：

```
FUNCTION fact :
PARAM var0
temp0 := #1
IF var0 == temp0 GOTO label0
GOTO label1
LABEL label0 :
RETURN var0
GOTO label2
LABEL label1 :
temp2 := #1
temp3 := var0 - temp2
ARG temp3
temp4 := CALL fact
temp5 := var0 * temp4
var1 := temp5
RETURN var1
LABEL label2 :
FUNCTION main :
temp6 := CALL read
var3 := temp6
temp7 := #0
var4 := temp7
LABEL label3 :
IF var4 < var3 GOTO label4
GOTO label5
LABEL label4 :
temp9 := CALL read
var5 := temp9
temp10 := #1
IF var5 > temp10 GOTO label6
GOTO label7
LABEL label6 :
ARG var5
temp12 := CALL fact
var2 := temp12
GOTO label8
LABEL label7 :
temp13 := #1
var2 := temp13
LABEL label8 :
ARG var2
CALL print
temp15 := #1
var4 := var4 + temp15
GOTO label3
LABEL label5 :
temp16 := #0
RETURN temp16
```

mips汇编码：
```mips
.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
    li $v0,4
    la $a0,_prompt
    syscall
    li $v0,5
    syscall
    jr $ra

print:
    li $v0,1
    syscall
    li $v0,4
    la $a0,_ret
    syscall
    move $v0,$0
    jr $ra
fact:
	li $t1,1
	beq $a0,$t1,label0
	j label1
label0:
	move $v0,$a0
	jr $ra
	j label2
label1:
	li $t1,1
	sub $t2,$a0,$t1
	move $t0,$a0
	move $a0,$t2
	addi $sp,$sp,-24
	sw $t0,0($sp)
	sw $ra,4($sp)
	sw $t1,8($sp)
	sw $t2,12($sp)
	sw $t3,16($sp)
	sw $t4,20($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	lw $t1,8($sp)
	lw $t2,12($sp)
	lw $t3,16($sp)
	lw $t4,20($sp)
	addi $sp,$sp,24
	move $t1 $v0
	mul $t2,$a0,$t1
	move $t1,$t2
	move $v0,$t1
	jr $ra
label2:
main:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	move $t2,$v0
	addi $sp,$sp,4
	move $t3,$t2
	li $t2,0
	move $t4,$t2
label3:
	blt $t4,$t3,label4
	j label5
label4:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	move $t2,$v0
	addi $sp,$sp,4
	move $t5,$t2
	li $t2,1
	bgt $t5,$t2,label6
	j label7
label6:
	move $t0,$a0
	move $a0,$t5
	addi $sp,$sp,-24
	sw $t0,0($sp)
	sw $ra,4($sp)
	sw $t1,8($sp)
	sw $t2,12($sp)
	sw $t3,16($sp)
	sw $t4,20($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	lw $t1,8($sp)
	lw $t2,12($sp)
	lw $t3,16($sp)
	lw $t4,20($sp)
	addi $sp,$sp,24
	move $t2 $v0
	move $t6,$t2
	j label8
label7:
	li $t2,1
	move $t6,$t2
label8:
	move $t0,$a0
	move $a0,$t6
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal print
	lw $ra,0($sp)
	addi $sp,$sp,4
	li $t2,1
	add $t4,$t4,$t2
	j label3
label5:
	li $t2,0
	move $v0,$t2
	jr $ra
```


