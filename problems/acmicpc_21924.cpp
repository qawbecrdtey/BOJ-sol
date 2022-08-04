#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct uf {
	int n;
	int *root;
	uf(int n) : n(n), root(new int[n + 1]) {
		for(int i = 0; i <= n; i++) root[i] = i;
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
	uf u(n);
	long long res = 0, tot = 0;
	struct info{ long long a, b, c; };
	vector<info> v; v.reserve(m);
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		tot += c;
		v.push_back({ a, b, c });
	} sort(v.begin(), v.end(), [](info const &a, info const &b) { return a.c < b.c; });
	for(auto [x, y, c] : v) {
		if(u.merge(x, y)) res += c;
	}
	for(int i = 1; i < n; i++) {
		if(!u.check(i, i + 1)) {
			cout << -1;
			return 0;
		}
	} cout << tot - res;
}