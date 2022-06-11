#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<int, int>[n << 1];
	for(int i = 0; i < n; i++) {
		cin >> a[i << 1].first >> a[(i << 1) | 1].first;
		a[i << 1].second = 1;
		a[(i << 1) | 1].second = -1;
	}
	sort(a, a + (n << 1));
	int cnt = 0;
	long long res = 0, start = -1000000000;
	for(int i = 0; i < (n << 1); i++) {
		if(!cnt) {
			assert(a[i].second == 1);
			cnt = 1;
			start = a[i].first;
			continue;
		}
		cnt += a[i].second;
		if(!cnt) res += a[i].first - start;
	} cout << res;
}