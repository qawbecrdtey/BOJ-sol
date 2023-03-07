#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, c; cin >> a >> b >> c;
    ll res = 0xfffffffffffffff;
    auto const f = [a, b, c](ll A, ll B) { return abs(A - a) + abs(B - b) + abs(A * B - c); };
    ll const n = max(a, max(b, c)) << 2;
    for(ll A = 1; A <= n; A++) {
        for(ll B = 1; A * B <= n; B++) {
            res = min(res, f(A, B));
        }
    } cout << res;
}