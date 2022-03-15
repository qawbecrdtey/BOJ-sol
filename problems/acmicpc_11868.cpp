#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	int res = 0;
	while(n--) {
		int x; scanf("%d", &x);
		res ^= x;
	}
	if(res) printf("koosaga");
	else printf("cubelover");
}