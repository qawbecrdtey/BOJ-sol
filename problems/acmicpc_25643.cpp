#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct uf {
	int n;
	int *root;
	uf(int n) : n(n), root(new int[n]) {
		for(int i = 0; i < n; i++) root[i] = i;
	}
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
	bool check(int a, int b) { return find(a) == find(b); }
	bool is_all_connected() {
		for(int i = 1; i < n; i++) {
			if(!check(0, i)) return false;
		} return true;
	}
};
bool match(string const &a, string const &b, int n) {
	for(int i = 0; i < n; i++) {
		if(a.substr(0, n - i) == b.substr(i, n - i)) return true;
		if(b.substr(0, n - i) == a.substr(i, n - i)) return true;
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new string[n];
	auto v = new vector<int>[n];
	cin >> a[0];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		if(match(a[i - 1], a[i], m)) continue;
		cout << 0;
		return 0;
	} cout << 1;
}