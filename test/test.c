int f(int a,int b);

int main() {
    int x = read();
    if(x > 0) {
        x = f(x,2 * x);
    }
    else if( x < 0) {
        x = 0 - f(x,2*x);
    }
    else x = 0;
    write(x);
    return 0;
}

int f(int a,int b) {
    int result = 0;
    for(int i = 0; i < 10; i++) {
        result += (a & b) * (a | b) + result;
    }
    return result++;
}