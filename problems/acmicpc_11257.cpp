#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int a[4]; for(int &j : a) cin >> j;
		cout << a[0] << ' ' << a[1] + a[2] + a[3] << ' ';
		if(a[1] + a[2] + a[3] < 55 || a[1] < 11 || a[2] < 8 || a[3] < 12) {
			cout << "FAIL\n";
		} else cout << "PASS\n";
	}
}