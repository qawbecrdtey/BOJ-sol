#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int[n];
	auto b = new int[n]();
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		for(int j = 0; j < n; j++) {
			if(x >= a[j]) {
				b[j]++;
				break;
			}
		}
	}
	int idx = 0, res = b[0];
	for(int i = 1; i < n; i++) {
		if(res < b[i]) idx = i, res = b[i];
	} cout << idx + 1;
}