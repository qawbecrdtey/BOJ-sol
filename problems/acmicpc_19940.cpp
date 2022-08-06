#include <iostream>
using namespace std;
void print(int h, int m) {
	switch(m) {
		case 0: cout << h 		<< " 0 0 0 0\n"; return;
		case 1: cout << h 		<< " 0 0 1 0\n"; return;
		case 2: cout << h 		<< " 0 0 2 0\n"; return;
		case 3: cout << h 		<< " 0 0 3 0\n"; return;
		case 4: cout << h 		<< " 0 0 4 0\n"; return;
		case 5: cout << h 		<< " 0 0 5 0\n"; return;
		case 6: cout << h 		<< " 1 0 0 4\n"; return;
		case 7: cout << h 		<< " 1 0 0 3\n"; return;
		case 8: cout << h 		<< " 1 0 0 2\n"; return;
		case 9: cout << h 		<< " 1 0 0 1\n"; return;
		case 10: cout << h		<< " 1 0 0 0\n"; return;
		case 11: cout << h		<< " 1 0 1 0\n"; return;
		case 12: cout << h		<< " 1 0 2 0\n"; return;
		case 13: cout << h		<< " 1 0 3 0\n"; return;
		case 14: cout << h		<< " 1 0 4 0\n"; return;
		case 15: cout << h		<< " 1 0 5 0\n"; return;
		case 16: cout << h		<< " 2 0 0 4\n"; return;
		case 17: cout << h		<< " 2 0 0 3\n"; return;
		case 18: cout << h		<< " 2 0 0 2\n"; return;
		case 19: cout << h		<< " 2 0 0 1\n"; return;
		case 20: cout << h		<< " 2 0 0 0\n"; return;
		case 21: cout << h		<< " 2 0 1 0\n"; return;
		case 22: cout << h		<< " 2 0 2 0\n"; return;
		case 23: cout << h		<< " 2 0 3 0\n"; return;
		case 24: cout << h		<< " 2 0 4 0\n"; return;
		case 25: cout << h		<< " 2 0 5 0\n"; return;
		case 26: cout << h		<< " 3 0 0 4\n"; return;
		case 27: cout << h		<< " 3 0 0 3\n"; return;
		case 28: cout << h		<< " 3 0 0 2\n"; return;
		case 29: cout << h		<< " 3 0 0 1\n"; return;
		case 30: cout << h		<< " 3 0 0 0\n"; return;
		case 31: cout << h		<< " 3 0 1 0\n"; return;
		case 32: cout << h		<< " 3 0 2 0\n"; return;
		case 33: cout << h		<< " 3 0 3 0\n"; return;
		case 34: cout << h		<< " 3 0 4 0\n"; return;
		case 35: cout << h		<< " 3 0 5 0\n"; return;
		case 36: cout << h + 1	<< " 0 2 0 4\n"; return;
		case 37: cout << h + 1	<< " 0 2 0 3\n"; return;
		case 38: cout << h + 1	<< " 0 2 0 2\n"; return;
		case 39: cout << h + 1	<< " 0 2 0 1\n"; return;
		case 40: cout << h + 1	<< " 0 2 0 0\n"; return;
		case 41: cout << h + 1	<< " 0 2 1 0\n"; return;
		case 42: cout << h + 1	<< " 0 2 2 0\n"; return;
		case 43: cout << h + 1	<< " 0 2 3 0\n"; return;
		case 44: cout << h + 1	<< " 0 2 4 0\n"; return;
		case 45: cout << h + 1	<< " 0 1 0 5\n"; return;
		case 46: cout << h + 1	<< " 0 1 0 4\n"; return;
		case 47: cout << h + 1	<< " 0 1 0 3\n"; return;
		case 48: cout << h + 1	<< " 0 1 0 2\n"; return;
		case 49: cout << h + 1	<< " 0 1 0 1\n"; return;
		case 50: cout << h + 1	<< " 0 1 0 0\n"; return;
		case 51: cout << h + 1	<< " 0 1 1 0\n"; return;
		case 52: cout << h + 1	<< " 0 1 2 0\n"; return;
		case 53: cout << h + 1	<< " 0 1 3 0\n"; return;
		case 54: cout << h + 1	<< " 0 1 4 0\n"; return;
		case 55: cout << h + 1	<< " 0 0 0 5\n"; return;
		case 56: cout << h + 1	<< " 0 0 0 4\n"; return;
		case 57: cout << h + 1	<< " 0 0 0 3\n"; return;
		case 58: cout << h + 1	<< " 0 0 0 2\n"; return;
		case 59: cout << h + 1	<< " 0 0 0 1\n"; return;
		default: __builtin_unreachable();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		print(n / 60, n % 60);
	}
}