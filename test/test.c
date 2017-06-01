
int f(int i,int j);


int main() {
    int a = read();
    int i = f(a,a);
    write(1);
    return a;
}

int f(int i,int j) {
    return i + j;
}