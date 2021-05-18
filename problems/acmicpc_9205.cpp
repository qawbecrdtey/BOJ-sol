#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
int abs(int x) { return x > 0 ? x : -x; }
using namespace std;
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n;
		scanf("%d", &n);
		auto a = new pair<int, int>[n + 2];
		auto v = new vector<int>[n + 2];
		for(int i = 0; i < n + 2; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
			for(int j = 0; j < i; j++) {
				if(abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) <= 1000) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		queue<int> pq;
		pq.push(0);
		auto visited = new bool[n + 2]();
		while(!pq.empty()) {
			auto const now = pq.front(); pq.pop();
			if(visited[now]) continue;
			visited[now] = true;
			if(now == n + 1) {
				printf("happy\n");
				goto end;
			}
			for(auto next : v[now]) {
				if(!visited[next]) pq.push(next);
			}
		}
		printf("sad\n");
		end:
		delete[] v;
		delete[] a;
	}
}
