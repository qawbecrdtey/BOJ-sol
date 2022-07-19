#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		ll a, b; cin >> a >> b;
		if(b % a || a == b) cout << "0\n";
		else cout << "1\n";
	}
}