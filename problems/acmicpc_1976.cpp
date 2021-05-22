#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<int>[n + 1];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if(x) v[i].push_back(j);
		}
	}
	set<int> s;
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if(s.find(x) == s.end()) s.insert(x);
	}
	auto visited = new bool[n + 1]();
	for(int i = 1; i <= n; i++) {
		if(visited[i]) continue;
		bool flag = false;
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			auto const now = q.front(); q.pop();
			if(visited[now]) continue;
			visited[now] = true;
			if(s.find(now) != s.end()) {
				flag = true;
				s.erase(now);
			}
			for(auto const next : v[now]) {
				if(!visited[next]) q.push(next);
			}
		}
		if(flag) {
			if(!s.empty()) {
				printf("NO");
				return 0;
			}
			printf("YES");
			return 0;
		}
	}
	delete[] v;
}