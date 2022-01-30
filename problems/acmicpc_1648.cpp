#include <algorithm>
#include <stdio.h>
using ll = long long;
ll dp(ll **arr, int n, int m, int next, int r, int c) {
    if(c >= m) return dp(arr, n, m, next, r + 1, c - m);
    if(r == n && c == 0) return 1;
    auto &val = arr[r * m + c][next];
    if(val != -1) return val;
    if(r == n - 1) {
        if(next & (1 << (m - 1))) return val = dp(arr, n, m, ((next << 1) & ((1 << m) - 1)) | 1, r, c + 1);
        val = 0;
        if(c < m - 1 && !((next << 2) & (1 << m))) val = dp(arr, n, m, ((next << 2) & ((1 << m) - 1)) | 3, r, c + 2);
        return val;
    }
    if(next & (1 << (m - 1))) return val = dp(arr, n, m, (next << 1) & ((1 << m) - 1), r, c + 1);
    val = dp(arr, n, m, (((next << 1) & ((1 << m) - 1)) | 1), r, c + 1);
    if(c < m - 1 && !((next << 2) & (1 << m))) val += dp(arr, n, m, (next << 2) & ((1 << m) - 1), r, c + 2);
    return val %= 9901;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    auto arr = new ll*[n * m];
    for(int i = 0; i < n * m; i++) {
        arr[i] = new ll[1 << m];
        std::fill(arr[i], arr[i] + (1 << m), -1);
    }
    printf("%lld", dp(arr, n, m, 0, 0, 0));
}