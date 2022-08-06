#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes() {
	vector<int> primes{ 3 };
	vector<bool> visited(100000001);
	int i = 5, d = 4;
	for(; i * i <= 100000000; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(long long j = i; j <= 100000000; j += (i << 1)) visited[j] = true;
		}
	}
	for(; i <= 100000000; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	} return primes;
}
inline bool is_prime(vector<int> const &primes, int n) {
	return n == 2 || ((n & 1) && binary_search(primes.begin(), primes.end(), n));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto const primes = get_primes();
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new int[n + 1]; a[0] = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
		pair<int, int> res{ 0, n + 1 };
		for(int s = 0; s <= n - 2 && res.second - res.first > 2; s++) {
			for(int d = 2; d <= n - s && res.second - res.first > d; d++) {
				if(is_prime(primes, a[s + d] - a[s])) {
					res.first = s, res.second = s + d;
					break;
				}
			}
		}
		if(res.second - res.first == n + 1) cout << "This sequence is anti-primed.\n";
		else {
			cout << "Shortest primed subsequence is length " << res.second - res.first << ':';
			for(int i = res.first; i < res.second; i++) {
				cout << ' ' << a[i + 1] - a[i];
			} cout << '\n';
		}
		delete[] a;
	}
}