#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll a, b; cin >> a >> b; b++;
	cout << b * (1 - a + 2) + (a - 2) * b * (b + 1) / 2;
}