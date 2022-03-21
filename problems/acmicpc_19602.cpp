#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf(a + 2 * b + 3 * c < 10 ? "sad" : "happy");
}