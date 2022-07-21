#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, s; cin >> n >> s;
	int m = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x; m = max(m, x);
	} cout << (m * s + 999) / 1000;
}