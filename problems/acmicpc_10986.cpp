#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n + 1]; a[0] = 0;
    auto cnt = new long long[m](); cnt[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] = (a[i] + a[i - 1]) % m;
        cnt[a[i]]++;
    } long long res = 0;
    for(int i = 0; i < m; i++) {
        res += (cnt[i] * (cnt[i] - 1)) / 2;
    } cout << res;
}