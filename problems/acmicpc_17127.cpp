#include <stdio.h>
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);
    auto a = new ll[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    ll res = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                ll w = 1, x = 1, y = 1, z = 1;
                for(int l = 0; l < i; l++) w *= a[l];
                for(int l = i; l < j; l++) x *= a[l];
                for(int l = j; l < k; l++) y *= a[l];
                for(int l = k; l < n; l++) z *= a[l];
                auto const val = w + x + y + z;
                if(res < val) res = val;
            }
        }
    }
    printf("%lld", res);
}