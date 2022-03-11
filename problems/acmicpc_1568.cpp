#include <cstdio>
int main() {
    int n; scanf("%d", &n);
    int cur = 1;
    int i = 0;
    while(n) {
        if(n < cur) cur = 1;
        n -= cur++;
        i++;
    } printf("%d", i);
}