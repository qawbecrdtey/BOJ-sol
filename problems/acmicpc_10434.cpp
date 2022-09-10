#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
inline vector<int> get_primes() {
	vector<int> primes{ 2, 3 };
	vector<bool> visited(10001);
	int i = 5, d = 4;
	for(; i * i <= 10000; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = i; j <= 10000; j += (i << 1)) {
				visited[j] = true;
			}
		}
	}
	for(; i <= 10000; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	}
	return primes;
}
inline bool is_prime(vector<int> const &primes, int n) {
	return binary_search(primes.begin(), primes.end(), n);
}
inline bool is_happy(map<int, bool> &m, set<int> &visited,  int n) {
	if(auto it = m.find(n); it != m.end()) return it->second;
	if(auto it = visited.find(n); it != visited.end()) return m[n] = false;
	visited.insert(n);
	if(n == 1) return m[1] = true;
	int x = 0, nn = n;
	while(nn) {
		int const y = nn % 10;
		x += y * y;
		nn /= 10;
	}
	return m[n] = is_happy(m, visited, x);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto const primes = get_primes();
	map<int, bool> m;
	int tt; cin >> tt; while(tt--) {
		short t, n; cin >> t >> n;
		cout << t << ' ' << n << ' ';
		set<int> visited;
		if(!is_prime(primes, n) || !is_happy(m, visited, n)) cout << "NO\n";
		else cout << "YES\n";
	}
}