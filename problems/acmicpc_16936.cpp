#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<ll, ll>[n]();
	for(int i = 0; i < n; i++) {
		ll x; cin >> x; a[i].second = x;
		while(x % 3 == 0) a[i].first++, x /= 3;
		while(x % 2 == 0) a[i].first--, x /= 2;
	} sort(a, a + n, [](pair<ll, ll> const &a, pair<ll, ll> const &b){ return a.first > b.first; });
	for(int i = 0; i < n; i++) cout << a[i].second << ' ';
}