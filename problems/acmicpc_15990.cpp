#include <stdio.h>
using ll = long long;
constexpr ll M = 1000000009;
int main() {
	int tt;
	scanf("%d", &tt);
	auto input = new int[tt];
	int max = 0;
	for(int i = 0; i < tt; i++) { scanf("%d", &input[i]); if(max < input[i]) max = input[i]; }
	ll *a[4];
	for(int i = 1; i < 4; i++) a[i] = new ll[max + 4]();
	a[1][1] = a[2][2] = a[3][3] = a[1][3] = a[2][3] = 1;
	for(int i = 4; i <= max; i++) {
		a[1][i] = (a[2][i - 1] + a[3][i - 1]) % M;
		a[2][i] = (a[1][i - 2] + a[3][i - 2]) % M;
		a[3][i] = (a[1][i - 3] + a[2][i - 3]) % M;
	}
	for(int i = 0; i < tt; i++) {
		printf("%lld\n", (a[1][input[i]] + a[2][input[i]] + a[3][input[i]]) % M);
	}
}