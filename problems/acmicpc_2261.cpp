#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int dist(pair<int, int> *i, pair<int, int> *j) {
	auto const x = i->first - j->first;
	auto const y = i->second - j->second;
	return x * x + y * y;
}
int sqrt(int n) {
	int l = 0, r = n;
	while(l < r) {
		auto const m = (l + r) / 2;
		if(m * m == n) return m;
		if(m * m < n) {
			l = m + 1;
			continue;
		}
		r = m;
	}
	return l;
}
void f(pair<int, int> *a, int n, int &d, int l, int r) {
	if(l == r || l + 1 == r) return;
	auto const m = (l + r) / 2;
	f(a, n, d, l, m);
	f(a, n, d, m, r);
	auto const lo = lower_bound(a + l, a + r, make_pair(a[m].first - sqrt(d), -10001));
	auto const hi = upper_bound(a + l, a + r, make_pair(a[m].first + sqrt(d), 10001));
	auto arr = new pair<int, int>[hi - lo];
	copy(lo, hi, arr);
	sort(arr, arr + (hi - lo), [](pair<int, int> const &a, pair<int, int> const &b) {
		return a.second < b.second || (a.second == b.second && a.first < b.first);
	});
	for(auto i = arr; i != arr + (hi - lo) - 1; ++i) {
		for(auto j = i + 1; j != arr + (hi - lo) && j->second - i->second < sqrt(d); ++j) {
			auto const di = dist(i, j);
			if(d > di) d = di;
		}
	}
	delete[] arr;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int d = 800000001;
	f(a, n, d, 0, n);
	cout << d;
}