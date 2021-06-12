#include <iostream>
using ll = long long;
using namespace std;
int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	auto a = new ll*[k + 1];
	for(int i = 0; i <= k; i++) {
		a[i] = new ll[i + 1]();
		a[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j - 1];
			if(i - 1 >= j) a[i][j] = (a[i][j] + a[i - 1][j]) % k;
		}
	}
	ll res = 1;
	while(n) {
		if(n % k < m % k) {
			cout << 0;
			return 0;
		}
		res = (res * a[n % k][m % k]) % k;
		n /= k; m /= k;
	}
	cout << res;

	for(int i = 0; i <= k; i++) {
		delete[] a[i];
	}
	delete[] a;
}