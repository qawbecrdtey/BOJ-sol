#include <iostream>
#include <vector>
using namespace std;
int f(vector<pair<int, int>> const *v, int now, int cost, int prev) {
	int sum = 0;
	for(auto const [next, nextcost] : v[now]) {
		if(next == prev) continue;
		sum += f(v, next, nextcost, now);
	} if(!sum) return cost;
	return cost > sum ? sum : cost;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m;
		auto v = new vector<pair<int, int>>[n + 1];
		while(m--) {
			int x, y, z; cin >> x >> y >> z;
			v[x].emplace_back(y, z);
			v[y].emplace_back(x, z);
		} int res = 0;
		for(auto const [next, cost] : v[1]) {
			res += f(v, next, cost, 1);
		}
		cout << res << '\n';
		delete[] v;
	}
}