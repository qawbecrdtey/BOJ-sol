#include <stdio.h>
#include <deque>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int sum = 0;
	deque<int> dq;
	for(int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		dq.push_back(x);
	}
	int max = sum;
	for(int i = k; i < n; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		sum -= dq.front();
		if(max < sum) max = sum;
		dq.pop_front();
		dq.push_back(x);
	}
	printf("%d", max);
}