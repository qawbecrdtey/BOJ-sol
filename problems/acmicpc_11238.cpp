#include <stdio.h>
using ll = long long;
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}
constexpr ll M = 1000000007;
void mul(ll const A[4], ll const B[4], ll C[4]) {
	C[0] = ((A[0] * B[0]) % M + (A[1] * B[2]) % M) % M;
	C[1] = ((A[0] * B[1]) % M + (A[1] * B[3]) % M) % M;
	C[2] = ((A[2] * B[0]) % M + (A[3] * B[2]) % M) % M;
	C[3] = ((A[2] * B[1]) % M + (A[3] * B[3]) % M) % M;
}
void f(ll A[4], int g) {
	if(!g) {
		A[0] = A[3] = 1;
		A[1] = A[2] = 0;
		return;
	}
	if(g == 1) {
		A[0] = A[1] = A[2] = 1;
		A[3] = 0;
		return;
	}
	ll B[4], C[4];
	f(B, g >> 1);
	mul(B, B, C);
	f(B, g & 1);
	mul(B, C, A);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y, g;
		scanf("%d%d", &x, &y);
		g = gcd(x, y);
		ll A[4];
		f(A, g);
		printf("%lld\n", A[1]);
	}
}