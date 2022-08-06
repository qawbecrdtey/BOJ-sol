#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline vector<int> get_fib() {
	vector<int> fib{ 1, 2 };
	while(fib.back() <= 1000000000) {
		fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
	} return fib;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto const fib = get_fib();
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v;
		while(n > 0) {
			int const x = *(upper_bound(fib.begin(), fib.end(), n) - 1);
			v.push_back(x); n -= x;
		}
		for(auto it = v.rbegin(); it != v.rend(); ++it) {
			cout << *it << ' ';
		} cout << '\n';
	}
}