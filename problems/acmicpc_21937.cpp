#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int f(vector<int> const *v, int *d, int dest, int now) {
	if(d[now] != -1) return d[now];
	if(now == dest) return d[now] = 1;
	for(auto next : v[now]) {
		if(f(v, d, dest, next)) return d[now] = 1;
	}
	return d[now] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto v = new vector<int>[n + 1];
	auto d = new int[n + 1]();
	auto goes = new int[n + 1];
	fill(goes, goes + n + 1, -1);
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		d[y]++; v[x].push_back(y);
	} int x; cin >> x;
	int res = 0;
	for(int i = 1; i <= n; i++) {
		res += f(v, goes, x, i);
	} cout << res - 1;
}