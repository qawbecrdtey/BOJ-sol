#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n + 2];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} a[n] = a[n + 1] = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i]) {
			cnt++;
			a[i] = 0;
			a[i + 1] = 1 - a[i + 1];
			a[i + 2] = 1 - a[i + 2];
		}
	}
	cout << cnt;
}