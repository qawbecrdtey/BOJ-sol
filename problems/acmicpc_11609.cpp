#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<string, string>[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	} sort(a, a + n, [](pair<string, string> const &a, pair<string, string> const &b) {
		return a.second < b.second || (a.second == b.second && a.first < b.first);
	});
	for(int i = 0; i < n; i++) {
		cout << a[i].first << ' ' << a[i].second << '\n';
	}
}