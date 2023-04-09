#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        auto a = new char*[n];
        auto dp = new int*[n];
        for(int i = 0; i < n; i++) {
            dp[i] = new int[m];
            a[i] = new char[m + 1];
            cin >> a[i];
        }
        dp[0][0] = (a[0][0] == 'C');
        for(int i = 0; i < n; i++) {
            for(int j = !i; j < m; j++) {
                int r = 0;
                if(j) r = dp[i][j - 1];
                if(i) r = max(r, dp[i - 1][j]);
                dp[i][j] = r + (a[i][j] == 'C');
            }
        } cout << dp[n - 1][m - 1] << '\n';
        for(int i = 0; i < n; i++) delete[] a[i];
        delete[] a;
    }
}