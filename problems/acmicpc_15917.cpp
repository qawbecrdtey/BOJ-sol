#include <stdio.h>
bool p2(int n) {
    while(n) {
        if(n != 1 && n % 2) return false;
        n /= 2;
    }
    return true;
}
int main() {
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int n;
        scanf("%d", &n);
        printf(p2(n) ? "1\n" : "0\n");
    }
}