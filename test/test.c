


int main() {
    int a[10];
    for(int i = 0; i < 10; i++) {
        a[i] = i * i;
        write(a[i]);
    }
}

// int fact(int n)
// {
//     if(n==1)
//         return n;
//     else
//         return (n*fact(n-1));
// }
// int main()
// {
//     int m,result;
//     m = read();
//     if(m>1)
//         result=fact(m);
//     else
//         result = 1;
//     write(result);
//     return 0;
// }