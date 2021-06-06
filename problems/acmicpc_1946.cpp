#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		auto a = new pair<int, int>[n];
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		sort(a, a + n);
		int x = a[0].second;
		int cnt = 1;
		for(int i = 1; i < n; i++) {
			if(a[i].second < x) {
				cnt++;
				x = a[i].second;
			}
		}
		printf("%d\n", cnt);
		delete[] a;
	}
}