#include <iostream>
using namespace std;
inline void rotate(int *a, int start, int end, int mid) {
	if(start == mid) return;
	auto arr = new int[mid - start];
	for(int i = start; i < mid; i++) arr[i - start] = a[i];
	for(int i = mid; i <= end; i++) a[i - mid + start] = a[i];
	for(int i = 0; i < mid - start; i++) a[i + start + end - mid + 1] = arr[i];
	delete[] arr;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int[n + 1]; for(int i = 0; i <= n; i++) a[i] = i;
	for(int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		rotate(a, x, y, z);
	} for(int i = 1; i <= n; i++) cout << a[i] << ' ';
}