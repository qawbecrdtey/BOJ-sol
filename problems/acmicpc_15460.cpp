#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using ll = long long;
inline constexpr int M = numeric_limits<int>::max() >> 1;
using pll = pair<ll, ll>;
inline bool gt(pll const &a, pll const &b) {
	return a.second * b.first < a.first * b.second;
}
inline bool eq(pll const &a, pll const &b) {
	return a.second * b.first == a.first * b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n + 1]();
	auto b = new int[n + 1];
	fill(b, b + n + 1, M);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	b[n] = a[n] - a[n - 1];
	for(int i = n - 1; i; i--) {
		b[i] = min(b[i + 1], a[i] - a[i - 1]);
	}
	pll max{ 0, 1 };
	vector<int> v;
	for(int i = 1; i <= n - 2; i++) {
		pll now = make_pair<ll, ll>(a[n] - a[i] - b[i + 1], n - i - 1);
		if(gt(now, max)) {
			max = now;
			v.clear();
			v.push_back(i);
			continue;
		}
		if(eq(now, max)) {
			v.push_back(i);
			continue;
		}
	}
	for(int now : v) cout << now << '\n';
}