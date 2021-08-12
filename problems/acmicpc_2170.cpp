#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<int, int>[n << 1];
	for(int i = 0; i < n; i++) {
		cin >> a[i << 1].first >> a[(i << 1) | 1].first;
		a[i << 1].second = 1;
		a[(i << 1) | 1].second = -1;
	}
	sort(a, a + (n << 1));
	long long res = 0;
	for(int idx = 0; idx < (n << 1); idx++) {
		auto const start = a[idx].first;
		int sum = a[idx].second;
		while(sum) {
			sum += a[++idx].second;
		}
		res += a[idx].first - start;
	}
	cout << res;
}