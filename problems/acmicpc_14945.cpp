#include <algorithm>
#include <cstdio>
constexpr int M = 10007;
int f(int ***dp, int n, int floor, int l, int r) {
    if(dp[floor][l][r] != -1) return dp[floor][l][r];
    if(floor == n - 1) return dp[floor][l][r] = 1;
    dp[floor][l][r] = 0;
    for(int i = l; i < l + 2; i++) {
        for(int j = r; j < r + 2 && j < n; j++) {
            if(i == j) continue;
            dp[floor][l][r] = (dp[floor][l][r] + f(dp, n, floor + 1, i, j)) % M;
        }
    }
    return dp[floor][l][r];
}
int main() {
    int n; scanf("%d", &n);
    auto dp = new int**[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new int*[n];
        for(int j = 0; j < n; j++) {
            dp[i][j] = new int[n];
            std::fill(dp[i][j], dp[i][j] + n, -1);
        }
    }
    printf("%d", (2 * f(dp, n, 1, 0, 1)) % M);
}