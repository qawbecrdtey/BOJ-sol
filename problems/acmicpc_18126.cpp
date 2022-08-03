#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll dfs(vector<pair<int, ll>> const *v, bool *visited, int now, ll dist) {
	visited[now] = true;
	ll res = dist;
	for(auto [next, nextd] : v[now]) {
		if(!visited[next]) res = max(res, dfs(v, visited, next, dist + nextd));
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto v = new vector<pair<int, ll>>[n + 1];
	for(int i = 1; i < n; i++) {
		int a, b; ll c; cin >> a >> b >> c;
		v[a].emplace_back(b, c);
		v[b].emplace_back(a, c);
	}
	auto visited = new bool[n + 1]();
	cout << dfs(v, visited, 1, 0);
}