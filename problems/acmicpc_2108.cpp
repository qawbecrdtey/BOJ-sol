#include <stdio.h>
#include <algorithm>
int d(int x, int n) {
	double y = (double)x / n;
	int res = y;
	while(res > y) res--;
	if(y - res < 0.5) return res;
	return res + 1;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	int b[8001] = {};
	int sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		b[a[i] + 4000]++;
	}
	std::sort(a, a + n);
	printf("%d\n", d(sum, n));
	printf("%d\n", a[n / 2]);
	int min = 0;
	bool flag = false;
	for(int i = 1; i <= 8000; i++) {
		if(b[min] < b[i]) {
			flag = false;
			min = i;
			continue;
		}
		if(!flag && b[min] == b[i]) {
			flag = true;
			min = i;
		}
	}
	printf("%d\n", min - 4000);
	printf("%d", a[n - 1] - a[0]);
}