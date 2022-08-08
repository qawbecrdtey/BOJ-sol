#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		int l = 0, r = 0;
		while(n--) {
			string s, t; cin >> s >> t;
			l += ((t == "R" && s == "P") || (t == "S" && s == "R") || (t == "P" && s == "S"));
			r += ((s == "R" && t == "P") || (s == "S" && t == "R") || (s == "P" && t == "S"));
		}
		if(l > r) cout << "Player 1\n";
		else if(l == r) cout << "TIE\n";
		else cout << "Player 2\n";
	}
}