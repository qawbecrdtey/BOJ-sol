#include <iostream>
#include <utility>
#include <algorithm>
using std::cin;
using std::cout;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto a = new int[n + 1]();
	auto b = new std::pair<int, int>[m];
	for(int i = 0; i < m; i++) {
		cin >> b[i].first >> b[i].second;
	}
	std::sort(b, b + m);
	for(int i = 0; i < m; i++) {
		if(a[b[i].first]) a[b[i].first]--;
		a[b[i].second]++;
	}
	int res = 0;
	for(int i = 1; i <= n; i++) res += a[i];
	cout << res;
	delete[] a;
	delete[] b;
}