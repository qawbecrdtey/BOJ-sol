#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n; ll sum = n * (n + 1) / 2;
	while(--n) {
		int x; cin >> x; sum -= x;
	} cout << sum;
}