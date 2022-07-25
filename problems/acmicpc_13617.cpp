#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, r = 0; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int zero = 0;
		for(int j = 0; j < m; j++) {
			int x; cin >> x;
			zero += (!x);
		} r += !zero;
	} cout << r;
}