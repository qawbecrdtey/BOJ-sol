#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct uf {
	int n;
	int *root;
	uf(int n) : n(n), root(new int[n + 1]) {
		for(int i = 1; i <= n; i++) root[i] = i;
	}
	int find(int a) {
		if(root[a] == a) return a;
		return root[a] = find(root[a]);
	}
	bool merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if(x == y) return false;
		root[x] = y;
		return true;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	int k; cin >> k;
	auto knower = new int[k];
	for(int i = 0; i < k; i++) cin >> knower[i];
	uf u(n);
	vector<set<int>> v(m + 1);
	for(int i = 1; i <= m; i++) {
		int o, x; cin >> o >> x;
		v[i].insert(x);
		while(--o) {
			int y; cin >> y;
			v[i].insert(y);
			u.merge(x, y);
		}
	}
	auto visited = new bool[m + 1]();
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			if(u.check(i, knower[j])) {
				for(int x = 1; x <= m; x++) {
					if(auto it = v[x].find(i); it != v[x].end()) {
						visited[x] = true;
					}
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		cnt += !visited[i];
	} cout << cnt;
}