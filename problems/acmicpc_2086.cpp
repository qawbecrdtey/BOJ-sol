#include <stdio.h>
using ll = long long;
constexpr ll m = 1000000000;
void mul(ll const A[4], ll const B[4], ll C[4]) {
	C[0] = ((A[0] * B[0]) % m + (A[1] * B[2]) % m) % m;
	C[1] = ((A[0] * B[1]) % m + (A[1] * B[3]) % m) % m;
	C[2] = ((A[2] * B[0]) % m + (A[3] * B[2]) % m) % m;
	C[3] = ((A[2] * B[1]) % m + (A[3] * B[3]) % m) % m;
}
void f(ll A[4], ll a) {
	if(a == 0) {
		A[0] = A[3] = 1;
		A[1] = A[2] = 0;
		return;
	}
	if(a == 1) {
		A[0] = A[1] = A[2] = 1;
		A[3] = 0;
		return;
	}
	ll R[4] = {};
	f(R, a / 2);
	ll B[4] = {};
	ll C[4] = {};
	mul(R, R, B);
	f(C, a % 2);
	mul(B, C, R);
	for(int i = 0; i < 4; i++) A[i] = R[i];
}
int main() {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	ll A[4] = {};
	ll B[4] = {};
	f(A, a - 1); f(B, b);
	ll res = B[0] + B[1] - A[0] - A[1];
	if(res >= 0) res %= m;
	else res = (m - (m - res) % m) % m;
	printf("%lld", res);
}