#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	auto a = new int[n];
	auto b = new int[n - 1];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i) b[i - 1] = a[i] - a[i - 1];
	}
	sort(b, b + n - 1);
	int res = a[n - 1] - a[0];
	for(int i = 0; i < k - 1; i++) {
		res -= b[n - 2 - i];
	}
	cout << res;
}