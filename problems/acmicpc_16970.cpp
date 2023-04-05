#include <iostream>
#include <numeric>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    long long cnt{};
    for(int i = 0; i <= n; i++) {
        for(int j = (!i); j <= m; j++) {
            int const g = gcd(i, j);
            cnt += (g + 1 == k) * (1LL + (i != 0 && j != 0)) * (n - i + 1) * (m - j + 1);
        }
    } cout << cnt;
}