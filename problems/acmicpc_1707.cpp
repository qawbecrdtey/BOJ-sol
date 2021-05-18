#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n, m;
		scanf("%d%d", &n, &m);
		auto v = new vector<int>[n + 1];
		auto visited = new bool[n + 1]();
		auto color = new int[n + 1];
		for(int i = 1; i <= n; i++) {
			color[i] = -1;
		}
		for(int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		queue<pair<int, int>> q;
		for(int i = 1; i <= n; i++) {
			if(visited[i]) continue;
			q.push(make_pair(i, 0));
			while (!q.empty()) {
				auto const now = q.front();
				q.pop();
				if (visited[now.first]) {
					if (now.second == color[now.first]) continue;
					printf("NO\n");
					goto END;
				}
				visited[now.first] = true;
				color[now.first] = now.second;
				for (auto const &next : v[now.first]) {
					if (!visited[next]) q.push(make_pair(next, 1 - now.second));
				}
			}
		}
		printf("YES\n");
		END:
		delete[] color;
		delete[] visited;
		delete[] v;
	}
}