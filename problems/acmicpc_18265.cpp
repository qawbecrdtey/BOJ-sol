#include <cstdio>
inline long long off(long long n) {
	switch(n) {
		case 0: return 1;
		case 1: return 2;
		case 2: return 4;
		case 3: return 7;
		case 4: return 8;
		case 5: return 11;
		case 6: return 13;
		case 7: return 14;
		default: __builtin_unreachable();
	}
}
int main() {
	long long n, ans; scanf("%lld", &n);
	printf("%lld", (n - 1) / 8 * 15 + off((n - 1) % 8));
}