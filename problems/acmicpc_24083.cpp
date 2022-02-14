#include <stdio.h>
int main() {
    int a, b; scanf("%d%d", &a, &b);
    int c = (a + b) % 12;
    printf("%d", c ? c : 12);
}