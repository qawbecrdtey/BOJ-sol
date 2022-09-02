#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; while(cin >> n) {
		if(!n) return 0;
		auto a = new int[n];
		int cnt = 0;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 1; i < n - 1; i++) cnt += (a[i] > a[i - 1] && a[i] > a[i + 1]);
		cout << cnt << '\n';
		delete[] a;
	}
}