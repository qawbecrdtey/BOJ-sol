#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int a[200001] = {};
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(-1, n));
	while(!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if(a[now.second]) continue;
		a[now.second] = -now.first;
		if(now.second == k) {
			printf("%d", -now.first - 1);
			return 0;
		}
		if(now.second && now.second < k) {
			pq.push(make_pair(now.first, now.second * 2));
		}
		if(now.second) {
			pq.push(make_pair(now.first - 1, now.second - 1));
		}
		if(now.second < k) {
			pq.push(make_pair(now.first - 1, now.second + 1));
		}
	}
}