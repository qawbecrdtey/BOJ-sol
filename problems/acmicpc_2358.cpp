#include <iostream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	map<int, int> m1, m2;
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		m1[a[i].first]++;
		m2[a[i].second]++;
	}
	int cnt = 0;
	for(auto now : m1) {
		cnt += (now.second > 1);
	}
	for(auto now : m2) {
		cnt += (now.second  > 1);
	}
	cout << cnt;
	delete[] a;
}