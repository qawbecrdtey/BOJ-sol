#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	int ab = ((n / a) + (n % a != 0)) * b;
	int cd = ((n / c) + (n % c != 0)) * d;
	cout << min(ab, cd);
}