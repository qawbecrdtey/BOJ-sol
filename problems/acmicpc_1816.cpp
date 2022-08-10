#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		ll n; cin >> n; if(n < 1000000) goto NO;
		for(ll i = 2; i < 1000000; i++) {
			if(!(n % i)) goto NO;
		}
		cout << "YES\n";
		continue;
	NO:	cout << "NO\n";
	}
}