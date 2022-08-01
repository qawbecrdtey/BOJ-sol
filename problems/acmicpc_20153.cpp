#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, x = 0, m; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i]; x ^= a[i];
	} m = x;
	for(int i = 0; i < n; i++) {
		if(m < (x ^ a[i])) m = (x ^ a[i]);
	} cout << m << m;
}