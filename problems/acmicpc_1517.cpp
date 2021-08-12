#include <iostream>
using namespace std;
using ll = long long;
ll f(int *a, int l, int r) {
	if(l + 1 >= r) return 0;
	auto const m = (l + r) / 2;
	ll res = f(a, l, m) + f(a, m, r);
	auto arr = new int[r - l];
	int left = l, right = m, idx = 0;
	while(left < m || right < r) {
		if(left == m) {
			arr[idx++] = a[right++];
			continue;
		}
		if(right == r) {
			arr[idx++] = a[left++];
			res += right - m;
			continue;
		}
		if(a[left] <= a[right]) {
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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << f(a, 0, n);
}