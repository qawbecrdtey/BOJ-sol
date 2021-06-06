#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n * 2];
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i * 2].first, &a[i * 2  +1].first);
		a[i * 2].second = 1;
		a[i * 2 + 1].second = -1;
	}
	sort(a, a + n * 2);
	int i = 0;
	int max = 0;
	int cnt = 0;
	while(i < 2 * n) {
		int const start = a[i].first;
		while(a[i].first == start) cnt += a[i++].second;
		if(max < cnt) max = cnt;
	}
	printf("%d", max);
}