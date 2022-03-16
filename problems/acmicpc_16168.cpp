#include <iostream>
#include <queue>
#include <vector>
using namespace std;
inline bool connected(vector<int> const *v, int V) {
	vector<bool> visited(V + 1);
	queue<int> q; q.push(1);
	while(!q.empty()) {
		int const now = q.front(); q.pop();
		if(visited[now]) continue;
		visited[now] = true;
		for(int next : v[now]) {
			if(!visited[next]) q.push(next);
		}
	}
	for(int i = 1; i <= V; i++) if(!visited[i]) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int V, E; cin >> V >> E;
	auto v = new vector<int>[V + 1];
	for(int i = 0; i < E; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int cnt = 0;
	if(!connected(v, V)) goto NO;
	for(int i = 1; i <= V; i++) {
		cnt += (v[i].size() & 1);
	} if(cnt > 2) goto NO;
	cout << "YES";
	return 0;
NO:	cout << "NO";
}