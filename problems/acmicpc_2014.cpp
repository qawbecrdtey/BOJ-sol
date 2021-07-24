#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;
using ll = long long;
int main() {
	int k, n;
	scanf("%d%d", &k, &n);
	auto a = new ll[k];
	for(int i = 0; i < k; i++) scanf("%lld", &a[i]);
	sort(a, a + k);
	priority_queue<ll> pq;
	for(int i = 0; i < k; i++) {
		pq.push(-a[i]);
	}
	for(int i = 0; i < n - 1; i++) {
		auto const now = pq.top(); pq.pop();
		for(int j = k - 1; j >= 0; j--) {
			pq.push(now * a[j]);
			if((-now) % a[j] == 0) break;
		}
	}
	printf("%lld", -pq.top());
	delete[] a;
}