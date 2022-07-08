#include <algorithm>
#include <iostream>
using namespace std;
int dfs(int const *a, bool *visited, int now) {
	if(visited[now]) return 0;
	visited[now] = true;
	return 1 + dfs(a, visited, a[now]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int res = 0, resi = 0;
	auto visited = new bool[n + 1];
	for(int i = 1; i <= n; i++) {
		fill(visited + 1, visited + n + 1, false);
		auto const val = dfs(a, visited, i);
		if(!resi || res < val) res = val, resi = i;
	} cout << resi;
}