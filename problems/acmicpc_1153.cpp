#include <stdio.h>
#include <vector>
using namespace std;
vector<int> prime(int n) {
	vector<int> v;
	auto visited = new bool[n + 1]();
	for(int i = 2; i <= n; i++) {
		if(!visited[i]) {
			v.push_back(i);
			for(int j = i; j <= n; j += i) {
				visited[j] = true;
			}
		}
	}
	delete[] visited;
	return v;
}
int main() {
	int n;
	scanf("%d", &n);
	if(n < 8) {
		printf("-1");
		return 0;
	}
	printf("2 ");
	if(n & 1) { printf("3 "); n -= 5; }
	else { printf("2 "); n -= 4; }
	auto primes = prime(n);
	for(auto it = primes.begin(); it != primes.end(); ++it) {
		auto p = lower_bound(it, primes.end(), n - *it);
		if(p == primes.end() || *p + *it != n) continue;
		printf("%d %d", *it, *p);
		return 0;
	}
}