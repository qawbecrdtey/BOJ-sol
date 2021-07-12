#include <stdio.h>
using ll = long long;
constexpr ll p = 1000;
void mul(ll const A[4], ll const B[4], ll C[4]) {
    C[0] = (A[0] * B[0] + A[1] * B[2]) % p;
    C[1] = (A[0] * B[1] + A[1] * B[3]) % p;
    C[2] = (A[2] * B[0] + A[3] * B[2]) % p;
    C[3] = (A[2] * B[1] + A[3] * B[3]) % p;
}
void power(ll A[4], ll n) {
    if(n == 0) {
        A[0] = A[3] = 1;
        A[1] = A[2] = 0;
        return;
    }
    if(n == 1) {
        A[0] = 6;
        A[1] = -4;
        A[2] = 1;
        A[3] = 0;
        return;
    }
    ll R[4];
    power(R, n / 2);
    ll B[4];
    ll C[4];
    power(C, n % 2);
    mul(R, R, B);
    mul(B, C, R);
    for(int i = 0; i < 4; i++) {
        if(R[i] < 0) R[i] = (p - (p - R[i]) % p) % p;
        A[i] = R[i];
    }
}
void vecmul(ll const A[4], ll v[2]) {
    ll const r[2] = { (A[0] * v[0] + A[1] * v[1]) % p, (A[2] * v[0] + A[3] * v[1]) % p };
    v[0] = r[0], v[1] = r[1];
}
int main() {
    int tt;
    scanf("%d", &tt);
    for(int ttt = 1; ttt <= tt; ttt++) {
        printf("Case #%d: ", ttt);
        ll n;
        scanf("%lld", &n);
        ll A[4];
        ll v[2] = { 6, 2 };
        power(A, n);
        vecmul(A, v);
        printf("%03lld\n", v[1] - 1);
    }
}