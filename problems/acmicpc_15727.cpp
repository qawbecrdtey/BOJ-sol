#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    printf("%d",n%5?n/5+1:n/5);
}