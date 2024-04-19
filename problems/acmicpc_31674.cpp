#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll m = 1;
    ll res = 0;
    for(int i = 0; i < n; i++) {
        res = (res + m * a[i] % M) % M;
        m = (m << 1) % M;
    }
    cout << res;
}