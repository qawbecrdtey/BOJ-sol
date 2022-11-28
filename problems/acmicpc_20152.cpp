#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll a[100]{1, 1, 2, 5};
	int x, y; cin >> x >> y; x = abs(x - y);
	for(int i = 4; i <= x; i++) {
		for(int j = 0; j < i; j++) {
			a[i] += a[j] * a[i - j - 1];
		}
	} cout << a[x];
}