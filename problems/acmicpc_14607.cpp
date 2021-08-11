#include <stdio.h>
#include <map>
using namespace std;
using ll = long long;
map<ll, ll> m;
ll f(ll n) {
	if(n == 1) return 0;
	if(m.find(n) != m.end()) return m[n];
	return m[n] = f(n / 2) + f(n - n / 2) + (n / 2) * (n - n / 2);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", f(n));
}