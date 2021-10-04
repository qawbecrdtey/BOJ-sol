#include <cstdio>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll x; char c;
		vector<ll> v;
		while(true) {
			scanf("%lld%c", &x, &c);
			v.push_back(x > 0 ? x : -x);
			if(c == '\n') break;
		}
		ll m = 0;
		for(int i = 0; i < v.size(); i++) {
			for(int j = 0; j < i; j++) {
				auto const g = gcd(v[i], v[j]);
				if(m < g) m = g;
			}
		}
		printf("%lld\n", m);
	}
}