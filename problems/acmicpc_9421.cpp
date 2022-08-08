#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
inline vector<int> get_primes(int n) {
	vector<int> primes{2, 3};
	vector<bool> visited(n + 1);
	int i = 5, d = 4;
	for(; i * i <= n; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = i; j <= n; j += (i << 1)) visited[j] = true;
		}
	}
	for(; i <= n; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	} return primes;
}
inline int next(int n) {
	int res = 0;
	while(n) {
		int const x = n % 10;
		res += x * x;
		n /= 10;
	} return res;
}
bool check(unordered_map<int, bool> &is_p, unordered_set<int> &visited, int p) {
	if(auto it = is_p.find(p); it != is_p.end()) return it->second;
	if(visited.find(p) != visited.end()) return is_p[p] = false;
	visited.insert(p);
	return is_p[p] = check(is_p, visited, next(p));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto const primes = get_primes(n);
	unordered_map<int, bool> is_p;
	is_p[1] = true;
	for(int p : primes) {
		unordered_set<int> visited;
		if(check(is_p, visited, p)) cout << p << '\n';
	}
}