#include <stdio.h>
#include <algorithm>
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    int l = 0, r = n - 1;
    int res = 2000000001;
    int resl = 0, resr = n - 1;
    while(l < r) {
        if(res > abs(a[r] + a[l])) {
            res = abs(a[resr = r] + a[resl = l]);
        }
        if(a[r] + a[l] == 0) {
            printf("%d %d", a[l], a[r]);
            return 0;
        }
        if(a[r] + a[l] > 0) {
            r--;
        }
        if(a[r] + a[l] < 0) {
            l++;
        }
    }
    printf("%d %d", a[resl], a[resr]);
    delete[] a;
}