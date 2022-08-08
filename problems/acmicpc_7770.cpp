#include <iostream>
using namespace std;
using ll = long long;
inline ll f(ll n) { return (2 * n * n * n + n) / 3; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, i; cin >> n;
	for(i = 1; f(i) <= n; i++); cout << i - 1;
}