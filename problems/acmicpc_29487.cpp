#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, d; cin >> n >> d;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, [](ll const a, ll const b) { return a > b; });
    ll l = d - 1, r = d + 1;
    ll i = 1;
    ll res = 0;
    while(i < n) {
        if(l >= 0) { res += (d - l) * a[i]; i++; l--; }
        res += (r - d) * a[i]; i++; r++;
    }
    cout << res;
}
