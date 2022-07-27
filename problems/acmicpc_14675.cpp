#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto d = new int[n + 1]();
	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		d[a]++; d[b]++;
	} int m; cin >> m; while(m--) {
		int a, b; cin >> a >> b;
		if(a == 2 || d[b] != 1) cout << "yes\n";
		else cout << "no\n";
	}
}