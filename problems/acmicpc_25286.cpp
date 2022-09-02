#include <iostream>
using namespace std;
inline int day(int n, int m) {
	switch(m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: return 31;
		case 4:
		case 6:
		case 9:
		case 11: return 30;
		case 2:
			if(n % 4) return 28;
			if(n % 100) return 29;
			if(n % 400) return 28;
			return 29;
		default: __builtin_unreachable();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m;
		if(m == 1) n--, m = 12;
		else m--;
		cout << n << ' ' << m << ' ' << day(n, m) << '\n';
	}
}