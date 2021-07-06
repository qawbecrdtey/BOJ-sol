#include <stdio.h>
#include <algorithm>
int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	int l = 1, r = a[n - 1] + 1;
	int res = r;
	while(l < r) {
		auto const m = (l + r) / 2;
		int idx = 0, cnt = 1;
		int i = 1;
		for(; i < n; i++) {
			if(a[i] - a[idx] <= m) continue;
			idx = i;
			cnt++;
		}
		if(cnt < c) {
			r = m;
			continue;
		}
		l = m + 1;
	}
	printf("%d", l);
	delete[] a;
}