#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int x, y; cin >> x >> y;
	cout << n * x / 100 << ' ' << n - (lower_bound(a, a + n, y) - a);

}