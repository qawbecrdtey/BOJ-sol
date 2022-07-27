#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<long long, long double>[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	} sort(a, a + n);
	long double l = 0;
	for(int i = 1; i < n; i++) {
		auto const x = abs(a[i].second - a[i - 1].second) / (a[i].first - a[i - 1].first);
		if(l < x) l = x;
	}
	cout << fixed;
	cout.precision(12);
	cout << l;
}