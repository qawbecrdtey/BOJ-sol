#include <iostream>
#include <numeric>
using namespace std;
using ll = unsigned long long;
constexpr ll M = 1000000000;
int main() {
	int n, m;
	scanf("%d", &n);
	auto a = new ll[n];
	for(int i = 0; i < n; i++) scanf("%llu", &a[i]);
	scanf("%d", &m);
	auto b = new ll[m];
	for(int i = 0; i < m; i++) scanf("%llu", &b[i]);
	bool over = false;
	ll val = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			auto const g = gcd(a[i], b[j]);
			val *= g;
			a[i] /= g;
			b[j] /= g;
			if(val >= M) {
				val %= M;
				over = true;
			}
		}
	}
	if(over) {
		printf("%09llu", val);
	}
	else printf("%llu", val);
}