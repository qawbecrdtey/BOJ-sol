#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		long long n; cin >> n;
		if(n % 3 == 0) cout << n * n * n / 27 << '\n';
		else if(n % 4 == 0) cout << n * n * n / 32 << '\n';
		else cout << "-1\n";
	}
}