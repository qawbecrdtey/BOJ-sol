#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n + 1];
	auto b = new pair<int, int>[n + 1];
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].second, &a[i].first);
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1);
	auto cur = new int[n + 1]();
	auto cnt = new int[n + 1]();
	int totsize = 0;
	auto size = new int[n + 1]();
	auto res = new int[n + 1];
	for(int i = 1; i <= n; i++) {
		if(size[a[i].second] != a[i].first) {
			size[a[i].second] = a[i].first;
			cnt[a[i].second] += cur[a[i].second];
			cur[a[i].second] = 0;
			if(totsize != a[i].first) {
				totsize = a[i].first;
				cnt[0] += cur[0];
				cur[0] = 0;
			}
		}
		res[i] = cnt[0] - cnt[a[i].second];
		cur[a[i].second] += a[i].first;
		cur[0] += a[i].first;
	}
	for(int i = 1; i <= n; i++) {
		printf("%d\n", res[lower_bound(a + 1, a + n + 1, b[i]) - a]);
	}
	delete[] res;
	delete[] size;
	delete[] cnt;
	delete[] cur;
	delete[] b;
	delete[] a;
}