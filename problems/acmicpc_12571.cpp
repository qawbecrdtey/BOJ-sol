#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": "; int cnt = 0;
		int n; cin >> n; auto a = new pair<int, int>[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			for(int j = 0; j < i; j++) {
				cnt += ((a[i].first < a[j].first && a[i].second > a[j].second) || (a[i].first > a[j].first && a[i].second < a[j].second));
			}
		}
		cout << cnt << '\n';
		delete[] a;
	}
}