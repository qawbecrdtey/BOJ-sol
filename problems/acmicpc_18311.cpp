#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; cin >> n >> k;
    auto *a = new ll[n << 1];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[(n << 1) - 1 - i] = a[i];
    }
    for(int i = 1; i < (n << 1); i++) a[i] += a[i - 1];
    auto res = upper_bound(a, a + (n << 1), k) - a + 1;
    if(res > n) res = (n << 1) + 1 - res;
    cout << res;
}