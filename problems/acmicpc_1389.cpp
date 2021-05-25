#include <stdio.h>
#include <set>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto s = new set<int>[n + 1];
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(s[a].find(b) == s[a].end()) {
			s[a].insert(b);
			s[b].insert(a);
		}
	}
	int min = 0;
	int minc = 1000000000;
	for(int i = 1; i <= n; i++) {
		queue<pair<int, int>> q;
		q.push(make_pair(i, 0));
		auto visited = new bool[n + 1]();
		int cnt = 0;
		while(!q.empty()) {
			auto const now = q.front(); q.pop();
			if(visited[now.first]) continue;
			visited[now.first] = true;
			cnt += now.second;
			for(auto next : s[now.first]) {
				if(!visited[next]) q.push(make_pair(next, now.second + 1));
			}
		}
		if(minc > cnt) {
			minc = cnt;
			min = i;
		}
		delete[] visited;
	}
	printf("%d", min);
	delete[] s;
}