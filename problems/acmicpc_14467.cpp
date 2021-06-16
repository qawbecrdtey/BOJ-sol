#include <cstdio>
#include <cstring>
int main() {
	int n;
	scanf("%d", &n);
	int a[10];
	memset(a, -1, sizeof(int) * 10);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(a[x - 1] == -1) a[x - 1] = y;
		else if(a[x - 1] != y) {
			cnt++;
			a[x - 1] = y;
		}
	}
	printf("%d", cnt);
}