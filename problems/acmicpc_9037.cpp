#include <iostream>
using namespace std;
bool is_all_same(int const *a, int n) {
	for(int i = 1; i < n; i++) {
		if(a[i] != a[0]) return false;
	} return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] += (a[i] & 1);
		} int cnt = 0;
		while(true) {
			if(is_all_same(a, n)) break;
			cnt++;
			auto b = new int[n];
			for(int i = 0; i < n; i++) {
				b[i] = (a[i] >> 1) + (a[(i + n - 1) % n] >> 1);
				b[i] += (b[i] & 1);
			} swap(a, b);
			delete[] b;
		} cout << cnt << '\n';
		delete[] a;
	}
}