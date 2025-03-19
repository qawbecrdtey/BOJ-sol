#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll res = 0;
    for(ll i = -n + 1, idx = 0; i <= n - 1; i += 2, idx++) {
        res += a[idx] * i;
    }
    cout << res * 2;
}
