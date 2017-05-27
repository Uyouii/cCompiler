
int f(int x);
int global = 0;

int main(){
    int a = 0,b = 0;
    int s[10] = {1,1,1,1};
    a += a;
    for(; a < 10; a++){
        printf("hello from sun! ");
    }
} 

int f(int x) {
	return 2 * x;
}