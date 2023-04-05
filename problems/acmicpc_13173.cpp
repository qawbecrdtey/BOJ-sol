#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
ll power(ll a, ll n) {
    if(!n) return 1;
    if(n == 1) return a % M;
    ll const r = power(a, n >> 1);
    return (((r * r) % M) * power(a, n & 1)) % M;
}
inline ll inv(ll n) { return power(n, M - 2); }
void mul(ll const A[4], ll const B[4], ll C[4]) {
    C[0] = ((A[0] * B[0]) % M + (A[1] * B[2]) % M) % M;
    C[1] = ((A[0] * B[1]) % M + (A[1] * B[3]) % M) % M;
    C[2] = ((A[2] * B[0]) % M + (A[3] * B[2]) % M) % M;
    C[3] = ((A[2] * B[1]) % M + (A[3] * B[3]) % M) % M;
}
void power(ll A[4], ll n) {
    if(!n) {
        A[0] = A[3] = 1;
        A[1] = A[2] = 0;
        return;
    }
    if(n == 1) return;
    ll B[4], C[4];
    copy(A, A + 4, B);
    power(B, n >> 1);
    mul(B, B, C);
    if(n & 1) {
        mul(C, A, B);
        copy(B, B + 4, C);
    }
    copy(C, C + 4, A);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll p, q, n, k; cin >> p >> q >> n >> k;
    if(q == p) {
        cout << (k == n);
        return 0;
    }
    ll const prob = (q * inv(p)) % M;
    ll const tmp = inv((1 + M - prob) % M);
    ll mat[4]{ tmp, ((M - prob) % M * tmp) % M, 1, 0 };
    power(mat, n);
    ll const p1 = inv(mat[2]);
    mat[0] = tmp, mat[1] = ((M - prob) % M * tmp) % M, mat[2] = 1, mat[3] = 0;
    power(mat, k);
    cout << (p1 * mat[2]) % M;
}