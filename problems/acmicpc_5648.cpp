#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
void reverse(ll &n) {
	ll res = 0;
	while(n) {
		res = res * 10 + n % 10;
		n /= 10;
	} n = res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n;
	auto a = new ll[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		reverse(a[i]);
	} sort(a, a + n);
	for(int i = 0; i < n; i++) cout << a[i] << '\n';
}