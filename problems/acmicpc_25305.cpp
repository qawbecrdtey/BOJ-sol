#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} sort(a, a + n);
	cout << a[n - k];
}