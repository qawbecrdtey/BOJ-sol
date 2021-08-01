#include <stdio.h>
using ll = long long;
constexpr ll M = 1000;
void mul(ll const A[4], ll const B[4], ll C[4]) {
	C[0] = (A[0] * B[0] + A[1] * B[2]) % M;
	C[1] = (A[0] * B[1] + A[1] * B[3]) % M;
	C[2] = (A[2] * B[0] + A[3] * B[2]) % M;
	C[3] = (A[2] * B[1] + A[3] * B[3]) % M;
}
void power(ll A[4], int n) {
	if(!n) {
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
	ll B[4], C[4], D[4];
	power(B, n >> 1);
	power(C, n & 1);
	mul(B, B, D);
	mul(D, C, A);
}
int main() {
	int tt;
	scanf("%d", &tt);
	for(int t = 1; t <= tt; t++) {
		printf("Case #%d: ", t);
		int n;
		scanf("%d", &n);
		ll A[4];
		power(A, n);
		ll val = (A[2] * 6 + A[3] * 2) % M;
		printf("%03lld\n", (val - 1 >= 0) ? (val - 1) : (M + val - 1));
	}
}