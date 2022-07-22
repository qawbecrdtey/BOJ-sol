#include <cmath>
#include <cstdio>
int main() {
	int tt; scanf("%d", &tt); while(tt--) {
		long long a, b, c, s, t;
		scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &s, &t);
		if(a < 0) a = -a, b = -b, c = -c;
		if(b * b <  4 * a * c) {
			printf("No\n");
			continue;
		}
		if(b * b == 4 * a * c) {
			if(b >= -2 * a * t && b <= -2 * a * s) {
				printf("Yes\n");
			} else printf("No\n");
			continue;
		}
		auto const l = (-b + sqrtl(b * b - 4 * a * c)) / (2 * a);
		auto const r = (-b - sqrtl(b * b - 4 * a * c)) / (2 * a);
		if((s <= l && l <= t) || (s <= r && r <= t)) printf("Yes\n");
		else printf("No\n");
	}
}