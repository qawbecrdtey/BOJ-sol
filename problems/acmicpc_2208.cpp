#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n + 1]; a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] += a[i - 1];
    }
    int res = 0;
    for(int l = 0; l < n; l++) {
        for(int r = l + m; r <= n; r++) {
            res = max(res, a[r] - a[l]);
        }
    }
    cout << res;
}
