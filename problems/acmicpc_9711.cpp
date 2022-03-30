#include <iostream>
using namespace std;
using ll = long long;
inline void mul(ll const A[4], ll const B[4], ll C[4], ll m) {
    C[0] = ((A[0] * B[0]) % m + (A[1] * B[2]) % m) % m;
    C[1] = ((A[0] * B[1]) % m + (A[1] * B[3]) % m) % m;
    C[2] = ((A[2] * B[0]) % m + (A[3] * B[2]) % m) % m;
    C[3] = ((A[2] * B[1]) % m + (A[3] * B[3]) % m) % m;
}
void power(ll A[4], ll n, ll m) {
    if(!n) {
        A[0] = A[3] = 1;
        A[1] = A[2] = 0;
        return;
    }
    if(n == 1) return;
    ll B[4], C[4]; copy(A, A + 4, B);
    power(A, n >> 1, m);
    mul(A, A, C, m);
    power(B, n & 1, m);
    mul(C, B, A, m);
}
inline ll fib(ll a, ll b) {
    ll A[4]{ 1, 1, 1, 0 };
    power(A, a, b);
    return A[1] % b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        ll a, b; cin >> a >> b;
        cout << fib(a, b) << '\n';
    }
}