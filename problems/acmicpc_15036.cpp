#include <cstdio>
using namespace std;
using ll = long long;
int main() {
    ll n, r{}; scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        switch(x) {
            case 0: r += 20000; break;
            case 1: r += 10000; break;
            case 2: r += 5000; break;
            case 4: r += 2500; break;
            case 8: r += 1250; break;
            case 16: r += 625; break;
            default: __builtin_unreachable();
        }
    } printf("%lld", r / 10000);
    if(r % 10000) printf(".%04lld", r % 10000);
    printf("\n");
}