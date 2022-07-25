#include <cmath>
#include <iostream>
using namespace std;
inline int score(double x, double y) {
	double const d2 = x * x + y * y;
	if(d2 <= 3 * 3) return 100;
	if(d2 <= 6 * 6) return 80;
	if(d2 <= 9 * 9) return 60;
	if(d2 <= 12 * 12) return 40;
	if(d2 <= 15 * 15) return 20;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		cout << "SCORE: ";
		double a[12]; for(auto &i : a) cin >> i;
		int xscore = 0, yscore = 0;
		for(int i = 0; i < 3; i++) {
			xscore += score(a[i * 2], a[i * 2 + 1]);
			yscore += score(a[6 + i * 2], a[6 + i * 2 + 1]);
		} cout << xscore << " to " << yscore << ", ";
		if(xscore == yscore) cout << "TIE.\n";
		else if(xscore >= yscore) cout << "PLAYER 1 WINS.\n";
		else cout << "PLAYER 2 WINS.\n";
	}
}