#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct frac { ll num, den; };
ostream &operator<<(ostream &os, frac const &f) { os << f.num << '/' << f.den; return os; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	frac f; while(cin >> f.num >> f.den) {
		if(!f.num && !f.den) return 0;
		vector<frac> v;
		for(ll m = 2 * f.den; m; m--) {
			if(m == f.den) continue;
			ll const x = m * f.num * (2 * f.den - m);
			if(x % (f.den * f.den)) continue;
			v.push_back({ x / (f.den * f.den), m });
		}
		sort(v.begin(), v.end(), [](frac const &a, frac const &b) {
			return a.den * b.num > a.num * b.den || (a.den * b.num == a.num * b.den && a.num < b.num);
		});
		for(auto const &fr : v) {
			cout << fr << ' ';
		} cout << '\n';
	}
}