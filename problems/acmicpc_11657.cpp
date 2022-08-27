#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = numeric_limits<ll>::max() >> 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto v = new vector<pair<int, ll>>[n + 1];
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].emplace_back(b, c);
	}
	auto dist = new ll[n + 1];
	fill(dist, dist + n + 1, M);
	dist[1] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(dist[j] == M) continue;
			for(auto [next, weight] : v[j]) {
				if(dist[next] > dist[j] + weight) {
					if(i == n) {
						cout << "-1";
						return 0;
					}
					dist[next] = dist[j] + weight;
				}
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		cout << (dist[i] == M ? -1 : dist[i]) << '\n';
	}
}