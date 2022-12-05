#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	vector<int> primes;
	for(int i = 2; i <= 118; i++) {
		bool flag = false;
		for(int j = 2; j * j <= i; j++) {
			if(i % j) continue;
			flag = true; break;
		} if(!flag) primes.push_back(i);
	}
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		bool flag = false;
		for(int const p : primes) {
			if(p >= n) break;
			if(!binary_search(primes.begin(), primes.end(), n - p)) continue;
			flag = true; break;
		}
		cout << (flag ? "Yes\n" : "No\n");
	}
}