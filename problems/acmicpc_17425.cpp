#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll sum[1000001] = {};
	for(int i = 1; i <= 1000000; i++) {
		for(int j = i; j <= 1000000; j += i) {
			sum[j] += i;
		}
		sum[i] += sum[i - 1];
	}
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << sum[n] << '\n';
	}
}