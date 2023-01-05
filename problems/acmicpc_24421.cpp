#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, cnt{}; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = 1; j < i; j++) {
			for(int k = 0; k < j; k++) {
				cnt += (a[k] * a[j] == a[i]);
			}
		}
	} cout << cnt;
}