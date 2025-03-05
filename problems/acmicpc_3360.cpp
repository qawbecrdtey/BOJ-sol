#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000;
static constexpr ll mat[81] {
    1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0
};
ll *id() {
    auto m = new ll[81]();
    for(int i = 0; i < 81; i += 10) m[i] = 1;
    return m;
}
ll *mul(ll const *const a, ll const *const b) {
    auto m = new ll[81]();
    for(ll i = 0; i < 9; i++) {
        for(ll j = 0; j < 9; j++) {
            for(ll k = 0; k < 9; k++) {
                m[i * 9 + k] += a[i * 9 + j] * b[j * 9 + k];
                m[i * 9 + k] %= M;
            }
        }
    }
    return m;
}
ll *power(ll const *const a, ll const p) {
    if(!p) return id();
    if(p == 1) {
        auto m = new ll[81];
        copy(mat, mat + 81, m);
        return m;
    }
    auto const r = power(mat, p >> 1);
    auto s = mul(r, r);
    delete[] r;
    if(p & 1) {
        auto t = mul(s, mat);
        swap(s, t);
        delete[] t;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    if(n == 1) cout << 1;
    else if(n == 2) cout << 2;
    else if(n == 3) cout << 3;
    else {
        auto m = power(mat, n - 3);
        ll res = m[0] * 2 + m[2] + m[3] + m[4] + m[6] + m[9] * 2 + m[11] + m[12] + m[13] + m[15] + m[18] * 2 + m[20] + m[21] + m[22] + m[24];
        cout << res % M;
    }
}
