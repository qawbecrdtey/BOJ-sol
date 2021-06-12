#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
struct uf {
	uf(int n) : n(n), arr(make_unique<int[]>(n)), rank(make_unique<int[]>(n)), cnt(make_unique<int[]>(n)), size(0) {
		for(int i = 0; i < n; i++) {
			arr[i] = i;
			rank[i] = cnt[i] = 1;
		}
	}
	void insert(string const &s) {
		if(m.find(s) != m.end()) return;
		m[s] = size++;
	}
	int find(string const &s) { return find(m[s]); }
	int find(int idx) {
		if(arr[idx] == idx) return idx;
		return arr[idx] = find(arr[idx]);
	}
	void join(string const &a, string const &b) { return join(m[a], m[b]); }
	void join(int a, int b) {
		a = find(a);
		b = find(b);
		if(rank[a] < rank[b]) swap(a, b);
		rank[a] += rank[b];
		arr[b] = a;
		cnt[a] += cnt[b];
	}
	int count(string const &s) { return count(m[s]); }
	int count(int idx) { return cnt[find(idx)]; }
	bool check(string const &a, string const &b) { return check(m[a], m[b]); }
	bool check(int a, int b) { return find(a) == find(b); }
	int n;
	unique_ptr<int[]> arr;
	unordered_map<string, int> m;
	unique_ptr<int[]> rank;
	unique_ptr<int[]> cnt;
	int size;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		uf u(n * 2);
		for(int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			u.insert(a);
			u.insert(b);
			if(!u.check(a, b))u.join(a, b);
			cout << u.count(a) << '\n';
		}
	}
}