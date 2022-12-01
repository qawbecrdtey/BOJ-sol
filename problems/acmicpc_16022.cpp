#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} sort(a, a + n);
	auto b = new int[n - 1];
	for(int i = 0; i < n - 1; i++) {
		b[i] = a[i + 1] + a[i];
	}
	auto c = new int[n - 2];
	for(int i = 0; i < n - 2; i++) {
		c[i] = b[i + 1] - b[i];
	} int res = *min_element(c, c + n - 2);
	if(res & 1) {
		cout << res / 2 << ".5";
	} else cout << res / 2 << ".0";
}