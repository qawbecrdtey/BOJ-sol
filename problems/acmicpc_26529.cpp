#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a[46]{1, 1};
	for(int i = 2; i < 46; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	int t; cin >> t; while(t--) {
		int n; cin >> n; cout << a[n] << '\n';
	}
}