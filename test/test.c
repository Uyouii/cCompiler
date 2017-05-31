
int f(int a,int b) {
    return a + b;
}

int main(int arg) {
    int a , b ,c;
    arg = (f(a,b) + f(a,c)) / (b - c) ;
    return arg;
}