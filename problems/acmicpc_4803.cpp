#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
	int n, m, tt = 1;
	while(true) {
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0) return 0;
		printf("Case %d: ", tt++);
		auto v = new vector<int>[n + 1];
		while(m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		auto visited = new bool[n + 1]();
		int res = 0;
		for(int i = 1; i <= n; i++) {
			if(!visited[i]) {
				queue<pair<int, int>> q;
				q.push({ -1, i });
				bool tree = true;
				while(!q.empty()) {
					auto const now = q.front(); q.pop();
					if(visited[now.second]) {
						tree = false;
						continue;
					}
					visited[now.second] = true;
					for(auto next : v[now.second]) {
						if(next == now.first) continue;
						q.push({ now.second, next });
					}
				}
				res += tree;
			}
		}
		if(!res) {
			printf("No trees.\n");
		}
		else if(res == 1) {
			printf("There is one tree.\n");
		}
		else {
			printf("A forest of %d trees.\n", res);
		}
		delete[] visited;
		delete[] v;
	}
}