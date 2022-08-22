#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = static_cast<ll>(numeric_limits<int>::max());
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m, w; cin >> n >> m >> w;
		auto dist = new ll*[n + 1];
		for(int i = 1; i <= n; i++) {
			dist[i] = new ll[n + 1];
			fill(dist[i], dist[i] + n + 1, M);
			dist[i][i] = 0;
		}
		while(m--) {
			ll x, y, z; cin >> x >> y >> z;
			dist[x][y] = min(dist[x][y], z);
			dist[y][x] = min(dist[x][y], z);
		}
		while(w--) {
			ll x, y, z; cin >> x >> y >> z;
			dist[x][y] = min(dist[x][y], -z);
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		} bool flag = false;
		for(int i = 1; i <= n; i++) {
			flag = flag || (dist[i][i] < 0);
		} if(flag) cout << "YES\n";
		else cout << "NO\n";
		for(int i = 1; i <= n; i++) delete[] dist[i];
		delete[] dist;
	}
}