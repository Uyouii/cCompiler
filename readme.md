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


