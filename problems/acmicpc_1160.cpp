#include <iostream>
using namespace std;
using ll = long long;
inline void mult(ll const A[4], ll v[2], ll m) {
    ll vv[2]{
        (ll)(((__int128_t)A[0] * v[0] % m + (__int128_t)A[1] * v[1] % m) % m),
        (ll)(((__int128_t)A[2] * v[0] % m + (__int128_t)A[3] * v[1] % m) % m)
    }; v[0] = vv[0], v[1] = vv[1];
}
inline void mult(ll const A[4], ll const B[4], ll C[4], ll m) {
    C[0] = (ll)(((__int128_t)A[0] * B[0] % m + (__int128_t)A[1] * B[2] % m) % m);
    C[1] = (ll)(((__int128_t)A[0] * B[1] % m + (__int128_t)A[1] * B[3] % m) % m);
    C[2] = (ll)(((__int128_t)A[2] * B[0] % m + (__int128_t)A[3] * B[2] % m) % m);
    C[3] = (ll)(((__int128_t)A[2] * B[1] % m + (__int128_t)A[3] * B[3] % m) % m);
}
void power(ll A[4], ll n, ll m) {
    if(!n) {
        A[0] = A[3] = 1;
        A[1] = A[2] = 0;
        return;
    }
    if(n == 1) return;
    ll B[4]; copy(A, A + 4, B);
    power(B, n >> 1, m);
    ll C[4]; mult(B, B, C, m);
    power(A, n & 1, m);
    mult(C, A, B, m);
    copy(B, B + 4, A);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll m, a, c, x0, n, g;
    cin >> m >> a >> c >> x0 >> n >> g;
    ll v[2]{ x0 % m, 1 };
    ll A[4]{ a % m, c % m, 0, 1 };
    power(A, n, m);
    mult(A, v, m);
    cout << v[0] % g;
}