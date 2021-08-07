#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(int i = 1; i <= c; i++) {
        bool flag = false;
        if(i % a == 0) { flag = true; printf("Fizz"); }
        if(i % b == 0) { flag = true; printf("Buzz"); }
        if(!flag) printf("%d", i);
        printf("\n");
    }
}
