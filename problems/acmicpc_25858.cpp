#include <iostream>
#include <numeric>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, d; cin >> n >> d;
	auto a = new int[n];
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i]; sum += a[i];
	}
	int g = sum;
	for(int i = 0; i < n; i++) {
		g = gcd(g, a[i]);
	} sum /= g;
	for(int i = 0; i < n; i++) {
		a[i] /= g;
		cout << d * a[i] / sum << '\n';
	}
}