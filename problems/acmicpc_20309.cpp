#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	if(n == 1) {
		cout << "YES";
		return 0;
	}
	auto a = new int[(n + 1) / 2]; auto b = new int[n / 2];
	for(int i = 0; i < n; i++) {
		if(i & 1) cin >> b[i >> 1];
		else cin >> a[i >> 1];
	}
	sort(a, a + (n + 1) / 2);
	sort(b, b + n / 2);
	for(int i = 0; i < n / 2; i++) {
		if(a[i] > b[i]) {
			cout << "NO";
			return 0;
		}
		if(i + 1 < n / 2 && a[i + 1] < b[i]) {
			cout << "NO";
			return 0;
		}
	}
	if((n & 1) && a[n / 2] < b[n / 2 - 1]) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
}