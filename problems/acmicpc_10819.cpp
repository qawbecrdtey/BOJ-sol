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
    int max = 0;
    do {
        int res = 0;
        for(int i = 1; i < n; i++) {
            res += (a[i] > a[i - 1] ? a[i] - a[i - 1] : a[i - 1] - a[i]);
        }
        if(max < res) max = res;
    } while(std::next_permutation(a, a + n));
    printf("%d", max);
    delete[] a;
}