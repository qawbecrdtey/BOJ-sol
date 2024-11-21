#include <iostream>
#include <set>
using namespace std;
using ll = long long;
static bool contains(set<ll> const &s, ll const n) {
    auto const it = s.find(n);
    return it != s.end();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    auto a = new ll[n + 1]; a[0] = 0;
    set<ll> s; s.insert(0);
    for(ll i = 1; i <= n; i++) {
        a[i] = a[i - 1] - i;
        if(a[i] < 0 || contains(s, a[i])) {
            a[i] = a[i - 1] + i;
        }
        s.insert(a[i]);
    }
    cout << a[n];
}
