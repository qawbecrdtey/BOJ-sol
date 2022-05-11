#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	long long n; while(cin >> n) {
		if(!n) return 0;
		long long cnt = 0;
		for(long long i = 1; i < n; i++) {
			if((n * n - i * i) % (2 * i)) continue;
			auto const x = (n * n - i * i) / (2 * i);
			if(x <= n) break;
			cnt++;
		}
		cout << cnt << '\n';
	}
}