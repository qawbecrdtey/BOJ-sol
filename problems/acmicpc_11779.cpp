#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<int, int>>[n + 1];
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(-c, b);
	}
	int s, e;
	scanf("%d%d", &s, &e);
	priority_queue<pair<int, pair<int, int>>> pq; // from, to
	for(auto const &now : v[s]) {
		pq.push(make_pair(now.first, make_pair(s, now.second)));
	}
	auto visited = new bool[n + 1]();
	auto path = new vector<int>[n + 1];
	path[s].push_back(s);
	while(!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if(visited[now.second.second]) continue;
		if(now.second.second == e) {
			printf("%d\n", -now.first);
			cout << path[now.second.first].size() + 1 << '\n';
			for(auto p : path[now.second.first]) {
				printf("%d ", p);
			}
			printf("%d", e);
			return 0;
		}
		path[now.second.second] = path[now.second.first];
		path[now.second.second].push_back(now.second.second);
		visited[now.second.second] = true;
		for(auto const &next : v[now.second.second]) {
			if(!visited[next.second]) {
				pq.push(make_pair(next.first + now.first, make_pair(now.second.second, next.second)));
			}
		}
	}
	delete[] visited;
	delete[] v;
}