#include <iostream>
#include <algorithm>
#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using ll = long long;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	auto a = new ll[n * n];
	auto b = new ll[n * n];
	for(int i = 0; i < n * n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a + n * n);
	auto max = a[n * n - 1];
	b[0] = a[0];
	for(int i = 1; i < n * n; i++) {
		b[i] = a[i] + b[i - 1];
	}
	ll l = 0, r = max + 1;
	ll res = max;
	while(l < r) {
		auto const m = (l + r) >> 1;
		auto const idx = std::lower_bound(a, a + n * n, m) - a;
		auto sum = (n * n - idx) * m;
		if(idx) sum += b[idx - 1];
		if(sum >= ((b[n * n - 1] + 1) >> 1)) {
			res = m;
			r = m;
			continue;
		}
		l = m + 1;
	}
	std::cout << res;
}