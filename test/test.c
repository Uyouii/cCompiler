
int main() {
    int N = read();
    for(int i = 0; i < N; i++) {
        int n = read();
        if(n >= 0) {
            int arry[n];
            int j = n;
            while(j > 0) {
                arry[n - j] = read();
                j--;
            }
        }
    }
    return 0;
}
