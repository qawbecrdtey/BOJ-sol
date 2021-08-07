#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll init(ll *t, ll const *a, int tidx, int l, int r) {
	if(l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = x + y;
}
ll update(ll *t, int tidx, int idx, ll val, int l, int r) {
	if(idx < l || idx > r) return t[tidx];
	if(l == r) return t[tidx] = val;
	auto const m = (l + r) / 2;
	auto const x = update(t, tidx * 2, idx, val, l, m);
	auto const y = update(t, tidx * 2 + 1, idx, val, m + 1, r);
	return t[tidx] = x + y;
}
ll sum(ll const *t, int tidx, int start, int end, int l, int r) {
	if(end < l || r < start) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new ll[n + 1];
	auto t = new ll[n * 4]();
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init(t, a, 1, 1, n);
	delete[] a;
	int m; cin >> m;
	vector<pair<int, int>> v1;
	vector<pair<pair<ll, ll>, pair<int, int>>> v2;
	ll cnt = 0;
	while(m--) {
		int w, x, y;
		cin >> w >> x >> y;
		if(w == 1) {
			v1.emplace_back(x, y);
		}
		else {
			int z; cin >> z;
			v2.emplace_back(make_pair(x, cnt), make_pair(y, z));
			cnt++;
		}
	}
	sort(v2.begin(), v2.end());
	cnt = 0;
	for(auto &now : v2) {
		while(cnt < now.first.first) {
			update(t, 1, v1[cnt].first, v1[cnt].second, 1, n);
			cnt++;
		}
		now.first.first = now.first.second;
		now.first.second = sum(t, 1, now.second.first, now.second.second, 1, n);
	}
	sort(v2.begin(), v2.end());
	for(auto const &now : v2) {
		cout << now.first.second << '\n';
	}
	delete[] t;
}