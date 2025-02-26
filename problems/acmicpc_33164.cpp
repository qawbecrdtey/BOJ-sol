#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto b = new ll[m];
    for(int i = 0; i < m; i++) cin >> b[i];
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res += (a[i] + b[j]) * max(a[i], b[j]);
        }
    }
    cout << res;
}
