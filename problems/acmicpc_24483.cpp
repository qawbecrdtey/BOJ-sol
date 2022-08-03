#include <iostream>
#include <set>
using namespace std;
using ll = long long;
ll dfs(set<int> const *s, bool *visited, int now, ll depth, ll &turn) {
	ll res = depth * turn;
	visited[now] = true;
	for(auto next : s[now]) {
		if(!visited[next]) res += dfs(s, visited, next, depth + 1, ++turn);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, r; cin >> n >> m >> r;
	auto s = new set<int>[n + 1];
	while(m--) {
		int x, y; cin >> x >> y;
		s[x].insert(y);
		s[y].insert(x);
	}
	auto visited = new bool[n + 1]();
	ll turn = 1;
	cout << dfs(s, visited, r, 0, turn);
}