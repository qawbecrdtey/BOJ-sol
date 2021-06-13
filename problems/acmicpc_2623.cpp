#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<int>[n + 1];
	auto d = new int[n + 1]();
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		int now, next;
		for(int j = 0; j < x; j++) {
			scanf("%d", &next);
			if(j) {
				v[now].push_back(next);
				d[next]++;
			}
			now = next;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(!d[i]) q.push(i);
	}
	vector<int> res;
	while(!q.empty()) {
		auto const now = q.front();
		q.pop();
		res.push_back(now);
		for(auto const next : v[now]) {
			if(d[next] == 0) {
				printf("0");
				return 0;
			}
			if(--d[next] == 0) q.push(next);
		}
	}
	if(res.size() != n) {
		printf("0");
		return 0;
	}
	for(auto const now : res) {
		printf("%d\n", now);
	}
	delete[] v;
	delete[] d;
}