#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<pair<ll, ll>, ll>> v;
	for(int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &c, &b);
		if(c < a) continue;
		v.emplace_back(make_pair(a, b), c);
	}
	ll l = 0, r = 2147483648;
	ll res = r;
	while(l < r) {
		ll sum = 0;
		auto const m = (l + r) / 2;
		for(auto const &now : v) {
			if(m < now.first.first) continue;
			sum += ((m > now.second ? now.second : m) - now.first.first) / now.first.second + 1;
		}
		if(sum & 1) r = res = m;
		else l = m + 1;
	}
	if(res >= 2147483648) {
		printf("NOTHING");
	}
	else {
		printf("%lld ", res);
		ll cnt = 0;
		for(auto const &now : v) {
			if(res <= now.second && res >= now.first.first && (res - now.first.first) % now.first.second == 0) {
				cnt++;
			}
		}
		printf("%lld", cnt);
	}
}