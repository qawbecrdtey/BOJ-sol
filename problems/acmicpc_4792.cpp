#include <algorithm>
#include <iostream>
using namespace std;
struct uf {
	int *root;
	uf(int n) : root(new int[n + 1]) {
		for(int i = 1; i <= n; i++) root[i] = i;
	}
	~uf() { delete[] root; }
	int find(int a) {
		if(a == root[a]) return a;
		return root[a] = find(root[a]);
	}
	bool merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if(x == y) return false;
		root[x] = y;
		return true;
	}
	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
struct node {
	int x, y;
	bool color; // is blue
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while(true) {
		int n, m, k;
		cin >> n >> m >> k;
		if(!n && !m && !k) return 0;
		auto a = new node[m];
		for(int i = 0; i < m; i++) {
			char c[2];
			int x, y;
			cin >> c >> x >> y;
			a[i].x = x;
			a[i].y = y;
			a[i].color = (*c == 'B');
		}
		sort(a, a + m, [](node const &a, node const &b) {
			return a.color < b.color;
		});
		int cntb = 0, cntr = 0;
		int costb = 0, costr = 0;
		uf ub(n);
		for(int i = 0; i < m && cntb < n - 1; i++) {
			bool const flag = ub.merge(a[i].x, a[i].y);
			cntb += flag;
			costb += flag * a[i].color;
		}
		sort(a, a + m, [](node const &a, node const &b) {
			return a.color > b.color;
		});
		uf ur(n);
		for(int i = 0; i < m && cntr < n - 1; i++) {
			bool const flag = ur.merge(a[i].x, a[i].y);
			cntr += flag;
			costr += flag * a[i].color;
		}
		cout << (costb <= k && costr >= k) << '\n';
		delete[] a;
	}
}