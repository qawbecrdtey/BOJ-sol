#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long long k, d, b = 1, n = 0; cin >> k >> d;
	while(k * b <= d) b = ((b << 1) | 1), n++;
	cout << n;
}