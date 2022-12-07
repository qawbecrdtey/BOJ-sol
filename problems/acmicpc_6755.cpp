#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<int> const *v, vector<bool> &visited, int start, int end) {
	if(visited[start]) return false;
	if(start == end) return true;
	visited[start] = true;
	return any_of(v[start].begin(), v[start].end(), [v, &visited, end](int next) {
		return dfs(v, visited, next, end);
	});
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto *const v = new vector<int>[n + 1];
	while(m--) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
	}
	int s, e; cin >> s >> e;
	vector<bool> visited(n + 1);
	if(dfs(v, visited, s, e)) {
		cout << "yes";
		return 0;
	}
	std::fill(visited.begin(), visited.end(), false);
	if(dfs(v, visited, e, s)) cout << "no";
	else cout << "unknown";
}