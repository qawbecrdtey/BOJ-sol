#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    n >>= 2;
    while(n--) printf("long ");
    printf("int");
}