#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n; auto a = new ll[n];
	for(ll i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	ll m = 0;
	if(n & 1) m = a[--n];
	for(int i = 0; i < n / 2; i++) {
		if(m < a[i] + a[n - i - 1]) m = a[i] + a[n - i - 1];
	} cout << m;
}