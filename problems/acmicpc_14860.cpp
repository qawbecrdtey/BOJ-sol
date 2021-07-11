#include <stdio.h>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
vector<int> prime(int n) {
	vector<int> p;
	auto visited = new bool[n + 1]();
	for(int i = 2; i <= n; i++) {
		if(!visited[i]) {
			p.push_back(i);
			for(int j = i; j <= n; j += i) {
				visited[j] = true;
			}
		}
	}
	delete[] visited;
	return p;
}
ll power(ll a, ll b) {
	if(b == 0) return 1;
	if(b == 1) return a % M;
	ll const r = power(a, b / 2);
	return (((r * r) % M) * power(a, b % 2)) % M;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto p = prime(n > m ? n : m);
	ll res = 1;
	for(auto now : p) {
		if(now > n || now > m) break;
		ll sum = 0;
		ll pow = now;
		while(pow <= n || pow <= m) {
			sum = (sum + (n / pow) * (m / pow)) % (M - 1);
			pow *= now;
		}
		res = (res * power(now, sum)) % M;
	}
	printf("%lld", res);
}