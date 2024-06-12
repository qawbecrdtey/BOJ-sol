#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll w, h, k; cin >> w >> h >> k;
    ll n; cin >> n;
    auto a = new ll[n + 2]; a[0] = 0; a[n + 1] = h;
    auto da = new ll[n + 1]; 
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; da[i - 1] = a[i] - a[i - 1];
    } da[n] = a[n + 1] - a[n];
    delete[] a;
    sort(da, da + n + 1);
    ll m; cin >> m;
    auto b = new ll[m + 2]; b[0] = 0; b[m + 1] = w;
    ll res = 0;
    for(int i = 1; i <= m + 1; i++) {
        if(i != m + 1) cin >> b[i];
        ll const now = b[i] - b[i - 1];
        res += upper_bound(da, da + n + 1, k / now) - da;
    }
    cout << res;
}
