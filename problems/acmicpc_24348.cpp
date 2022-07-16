#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll a[3]; cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	ll ans = 0;
	do {
		ans = max({ ans, a[0] + a[1] - a[2], a[0] + a[1] * a[2], a[0] - a[1] + a[2], a[0] - a[1] * a[2], a[0] * a[1] + a[2], a[0] * a[1] - a[2] });
	} while(next_permutation(a, a + 3));
	cout << ans;
}