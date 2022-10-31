#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, x; cin >> n >> x;
	auto a = new int[n + 1];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int idx = 1;
	while(x <= a[idx]) {
		x++; idx = idx % n + 1;
	} cout << idx;
}