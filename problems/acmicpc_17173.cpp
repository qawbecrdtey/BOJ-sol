#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new bool[n + 1]();
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		for(int j = x; j <= n; j += x) a[j] = true;
	}
	int res = 0;
	for(int i = 1; i <= n; i++) res += a[i] * i;
	cout << res;
}