#include <cstdio>
inline bool distinct(int n) {
	bool b[10]{};
	while(n) {
		if(b[n % 10]) return false;
		b[n % 10] = true;
		n /= 10;
	} return true;
}
int main() {
	int n; scanf("%d", &n);
	for(int i = n + 1; ; i++) {
		if(distinct(i)) {
			printf("%d", i); return 0;
		}
	}
}