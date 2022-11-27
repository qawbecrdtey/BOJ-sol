#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; while(cin >> n) {
		bool flag = false;
		if(!n) return 0;
		for(ll i = 2; i * i <= abs(n); i++) {
			if(n % i) continue;
			ll pos = i, neg = -i;
			ll cnt = 1;
			while(pos < abs(n)) {
				pos *= i; neg *= -i;
				cnt++;
			}
			if(pos == n || neg == n) {
				flag = true;
				cout << cnt << '\n';
				break;
			}
		}
		if(!flag) cout << "1\n";
	}
}