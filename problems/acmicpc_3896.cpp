#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int M = 1299709;
vector<int> get_primes() {
	vector<int> primes{2, 3};
	vector<bool> visited(M + 1);
	int i = 5, d = 4;
	for(; i * i <= M; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = i; j <= M; j += (i << 1)) visited[j] = true;
		}
	}
	for(; i <= M; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	}
	return primes;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto const primes = get_primes();
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		if(n < 4) {
			cout << "0\n";
			continue;
		}
		auto l = lower_bound(primes.begin(), primes.end(), n);
		if(*l == n) cout << "0\n";
		else cout << *l - *(l - 1) << '\n';
	}
}