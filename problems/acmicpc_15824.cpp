#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new int[n];
	auto power = new ll[n]();
	power[0] = 1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i) power[i] = (power[i - 1] * 2) % M;
	}
	sort(a, a + n);
	ll res = 0;
	for(int i = 0; i < n; i++) {
		res += (power[i] * a[i]) % M;
		res += M - (power[n - i - 1] * a[i]) % M;
		res %= M;
	}
	cout << res;
	delete[] a;
}