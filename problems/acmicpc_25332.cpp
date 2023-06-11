#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> m; m[0] = 1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] -= x;
        if(i) a[i] += a[i - 1];
        m[a[i]]++;
    }
    ll res = 0;
    for(auto [_, now] : m) {
        res += now * (now - 1) / 2;
    } cout << res;
}