#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int[n + 1]();
	while(m--) {
		int x, y; cin >> x >> y;
		a[x]++; a[y]++;
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i] << '\n';
	}
}