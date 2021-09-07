#include <stdio.h>
using ll = unsigned long long;
constexpr ll M = 1000000007;
constexpr ll I[8][8] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1 }
};
constexpr ll orig[8][8] = {
		{ 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 0, 1, 1, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 0, 1, 1, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 0 }
};
void mul(ll const A[8][8], ll const B[8][8], ll C[8][8]) {
	for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) C[i][j] = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			for(int k = 0; k < 8; k++) {
				C[i][j] += (A[i][k] * B[k][j]) % M;
				C[i][j] %= M;
			}
		}
	}
}
void power(ll A[8][8], ll n) {
	if(!n) {
		for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) A[i][j] = I[i][j];
		return;
	}
	if(n == 1) {
		for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) A[i][j] = orig[i][j];
		return;
	}
	ll B[8][8], C[8][8];
	power(B, n >> 1);
	mul(B, B, C);
	power(B, n & 1);
	mul(C, B, A);
}
int main() {
	ll n;
	scanf("%llu", &n);
	ll A[8][8];
	power(A, n);
	printf("%llu", A[0][0]);
}