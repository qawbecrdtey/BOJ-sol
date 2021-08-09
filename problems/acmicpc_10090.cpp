#include <algorithm>
#include <stdio.h>
using namespace std;
using ll = long long;
ll f(int *a, int l, int r) {
	if(l + 1 == r) return 0;
	auto const m = (l + r) / 2;
	auto res = f(a, l, m);
	res += f(a, m, r);
	int left = l, right = m;
	int idx = 0;
	auto arr = new int[r - l];
	copy(a + l, a + r, arr);
	while(idx < r - l) {
		if(left < m && (right == r || a[left] < a[right])) {
			arr[idx++] = a[left++];
			res += right - m;
			continue;
		}
		arr[idx++] = a[right++];
	}
	copy(arr, arr + r - l, a + l);
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%lld", f(a, 0, n));
}