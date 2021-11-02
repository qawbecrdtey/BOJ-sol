#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	auto a = new ll[n + 1];
	auto b = new ll[n + 1];
	a[0] = b[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i] * a[i];
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << ((a[y] - a[x - 1]) * (a[y] - a[x - 1]) - (b[y] - b[x - 1])) / 2 << '\n';
	}
}