#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int M = 50000000;
vector<int> get_primes() {
	vector<int> primes{ 2, 3 };
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
	} return primes;
}
pair<int, int> two(vector<int> const &primes, int n) {
	for(int p : primes) {
		if(binary_search(primes.begin(), primes.end(), n - p)) {
			return { p, n - p };
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto const primes = get_primes();
	int n; while(cin >> n) {
		if(n < 8) {
			cout << "Impossible.\n";
			continue;
		}
		cout << "2 " << (n & 1) + 2 << ' ';
		auto const [x, y] = two(primes, (n - 4) - (n & 1));
		cout << x << ' ' << y << '\n';
	}
}