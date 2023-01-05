#pragma GCC optimize("O3")
#include <iostream>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, cnt{}; cin >> n;
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) {
		int x, y, z, w; cin >> x >> y >> z >> w;
		a[i].first = z - x; a[i].second = w - y;
		if(a[i].second < a[i].first) swap(a[i].first, a[i].second);
		for(int j = 0; j < i; j++) {
			if((a[i].first > a[j].first && a[i].second < a[j].second) || (a[i].first < a[j].first && a[i].second > a[j].second)) cnt++;
		}
	} cout << cnt;
}