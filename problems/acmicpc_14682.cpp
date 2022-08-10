#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long long n, k; cin >> n >> k;
	long long x = 1; while(k--) {
		x = x * 10 + 1;
	} cout << n * x;
}