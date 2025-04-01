#include <cstdio>
using namespace std;
void print(int const n) {
    if(n >= 1000) {
        print(n / 1000);
        printf(",%03d", n % 1000);
    }
    else printf("%d", n);
}
int main() {
    int t; scanf("%d", &t); while(t--) {
        int x, k, h; scanf("%d%d%d", &x, &k, &h); k -= h;
        int res;
        if(k > 140) res = x * 140 + x * 3 / 2 * (k - 140) + h * x * 2;
        else res = x * k + h * x * 2;
        print(res);
        printf("\n");
    }
}
