#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    unsigned int m = *(unsigned int*)&n;
    if(!m) {
        printf("1");
        return 0;
    }
    int cnt = 0;
    while(m) {
        m >>= 1;
        cnt++;
    }printf("%d", cnt);
}