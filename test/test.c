int f(int i);

int main() {
    int N = read();
    while(N-- > 0) {
        int m = read();
        int result = f(m);
        print(result);
    }
    return 0;
}


int f(int i) {
    int result = 1;
    for(int j = 1; j <= i; j++)
        result *= j;
    return result;
}