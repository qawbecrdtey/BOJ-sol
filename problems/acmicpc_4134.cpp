#include <iostream>
using namespace std;
inline bool is_prime(long long n) {
	if(n < 2) return false;
	for(long long i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	} return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		long long n; cin >> n;
		while(!is_prime(n)) n++;
		cout << n << '\n';
	}
}