#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<ll, ll>[n];
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	ll res = 0;
	for(int i = n - 1; i; i--) {
		res += a[i - 1].first * a[i].first * a[i].second;
		a[i - 1].second = a[i].second;
	} cout << res;
}