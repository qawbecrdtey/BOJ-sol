#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n; ll res = 1;
		for(int i = 2; i <= n; i++) {
			res *= i;
			while(!(res % 5)) res /= 10;
			res %= 1000000000000000;
		}
		cout << res % 10 <<'\n';
	}
}