#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<int, int>[n << 1];
	for(int i = 0; i < n; i++) {
		cin >> a[i << 1].first >> a[(i << 1) | 1].first;
		a[i << 1].second = 1; a[(i << 1) | 1].second = -1;
	} sort(a, a + (n << 1));
	int cnt = 0, start = 0, sum = 0;
	n <<= 1;
	for(int i = 0; i < n; i++) {
		if(!cnt) start = a[i].first;
		cnt += a[i].second;
		if(!cnt) sum += a[i].first - start;
	} cout << sum;
}