#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> pq;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		pq.push(-x);
	}
	long long sum = 0;
	while(pq.size() != 1) {
		int x = 0;
		x = -pq.top(); pq.pop();
		x -= pq.top(); pq.pop();
		pq.push(-x);
		sum += x;
	}
	printf("%lld", sum);
}