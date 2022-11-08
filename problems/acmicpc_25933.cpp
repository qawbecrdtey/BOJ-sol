#include <iostream>
using namespace std;
inline bool count_win(int const a[3], int const b[3]) {
	int sum = 0;
	for(int i = 0; i < 3; i++) sum += a[i];
	for(int i = 0; i < 3; i++) sum -= b[i];
	return sum > 0;
}
inline bool color_win(int const a[3], int const b[3]) {
	return a[0] > b[0] || (a[0] == b[0] && (a[1] > b[1] || (a[1] == b[1] && a[2] > b[2])));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int a[3], b[3];
		for(int &i : a) { cin >> i; cout << i << ' '; }
		for(int &i : b) { cin >> i; cout << i << ' '; }
		cout << '\n';
		bool count = count_win(a, b);
		bool color = color_win(a, b);
		if(count && color) cout << "both\n\n";
		else if(count) cout << "count\n\n";
		else if(color) cout << "color\n\n";
		else cout << "none\n\n";
	}
}