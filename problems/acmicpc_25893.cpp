#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int a[3], cnt{}; for(auto &i : a) {
			cin >> i; cout << i << ' ';
			cnt += (i >= 10);
		} cout << '\n';
		if(cnt == 3) cout << "triple-double\n\n";
		else if(cnt == 2) cout << "double-double\n\n";
		else if(cnt == 1) cout << "double\n\n";
		else cout << "zilch\n\n";
	}
}