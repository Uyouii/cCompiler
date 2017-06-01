
int main() {
    double a[10];
    for(int i = 0 ; i < 10 ; i += 1) {
        a[i] = i;
    }
    int i = 0;
    double result;
    while(i < 10) {
        result += a[i];
    }
}

// int f(int a,int b);

// int main() {
//     int x = read();
//     if(x > 0) {
//         x = f(x,2 * x);
//     }
//     else if( x < 0) {
//         x = 0 - f(x,2*x);
//     }
//     else x = 0;
//     write(x);
//     return 0;
// }

// int f(int a,int b) {
//     int result = 0;
//     for(int i = 0; i < 10; i = i + 1) {
//         result += (a & b) * (a | b) + result;
//     }
//     return result;
// }