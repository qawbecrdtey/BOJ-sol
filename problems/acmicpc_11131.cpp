#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, tot = 0; cin >> n; while(n--) {
			int x; cin >> x; tot += x;
		} if(!tot) cout << "Equilibrium\n";
		else if(tot < 0) cout << "Left\n";
		else cout << "Right\n";
	}
}