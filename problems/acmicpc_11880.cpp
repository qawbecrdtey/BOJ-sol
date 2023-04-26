#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
inline ll sq(ll n) { return n * n; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t; while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        cout << min({ sq(a + b) + sq(c), sq(b + c) + sq(a), sq(c + a) + sq(b) }) << '\n';
    }
}