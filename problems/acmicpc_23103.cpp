#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, sum = 0; cin >> n;
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for(int i = 1; i < n; i++) sum += abs(a[i - 1].first - a[i].first) + abs(a[i - 1].second - a[i].second);
	cout << sum;
}