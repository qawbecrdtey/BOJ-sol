#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new long long[n]; auto b = new long long[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n); sort(b, b + n);
	cout << (a[n - 1] - a[0]) * (b[n - 1] - b[0]);
}