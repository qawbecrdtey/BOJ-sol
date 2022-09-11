#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new long long[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	if((a[1] << 1) == (a[2] + a[0])) {
		cout << a[n - 1] + a[1] - a[0];
	}
	else {
		cout << a[n - 1] / a[0] * a[1];
	}
}