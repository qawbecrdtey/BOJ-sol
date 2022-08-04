#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
ll power(ll a, ll n) {
	if(!n) return 1;
	if(n == 1) return a;
	ll const r = power(a, n >> 1);
	return r * r * power(a, n & 1);
}
void f(vector<int> const &v, ll n, ll m, ll cnt) {
	if(cnt == m) return;
	f(v, n / v.size(), m, cnt + 1);
	cout << v[n % v.size()] << ' ';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	set<int> s;
	for(int i = 0; i < n; i++) {
		int x; cin >> x; s.insert(x);
	}
	vector<int> v; for(auto now : s) v.push_back(now);
	ll x = power(v.size(), m);
	for(int i = 0; i < x; i++) {
		f(v, i, m, 0); cout << '\n';
	}
}