#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n; cin >> n;
	long long sum = 0;
	for(long long i = 0; i < n; i++) {
		long long x; cin >> x; sum += x;
	}
	cout << sum - ((n * (n - 1)) >> 1);
}