#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<long long, long long>[n];
	long long res = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i].first, &a[i].second);
	}
	for(int i = 0; i < n; i++) {
		res += (a[i].first * a[(i + 1) % n].second) - (a[i].second * a[(i + 1) % n].first);
	}
	res = (res > 0 ? res : -res);
	printf("%lld", res / 2);
	printf(res % 2 ? ".5" : ".0");
}