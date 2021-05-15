#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n, k;
		scanf("%d%d", &n, &k);
		auto a = new int[n + 1]();
		auto d = new int[n + 1]();
		auto v = new vector<int>[n + 1];
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < k; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			d[y]++;
		}
		int w;
		scanf("%d", &w);
		priority_queue<pair<int, int>> pq;
		for(int i = 1; i <= n; i++) {
			if(!d[i]) pq.push(make_pair(-a[i], i));
		}
		while(!pq.empty()) {
			auto const now = pq.top(); pq.pop();
			if(now.second == w) {
				printf("%d\n", -now.first);
				break;
			}
			for(auto&& next : v[now.second]) {
				if(--d[next] == 0) {
					pq.push(make_pair(now.first - a[next], next));
				}
			}
		}
		delete[] a;
		delete[] d;
		delete[] v;
	}
}