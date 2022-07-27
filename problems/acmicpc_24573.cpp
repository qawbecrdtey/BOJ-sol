#include <iostream>
using namespace std;
int f(int n) {
	switch(n % 20) {
		case 0: return 1 + n / 20;
		case 1: if(n < 20) return 0; return f(n - 21);
		case 2: if(n < 22) return 0; return f(n - 22);
		case 3: if(n < 23) return 0; return f(n - 23);
		case 4: return f(n - 4);
		case 5: return f(n - 5);
		case 6: if(n < 26) return 0; return f(n - 26);
		case 7: if(n < 27) return 0; return f(n - 27);
		case 8: return f(n - 8);
		case 9: return f(n - 9);
		case 10: return f(n - 10);
		case 11: if(n < 31) return 0; return f(n - 31);
		case 12: return f(n - 12);
		case 13: return f(n - 13);
		case 14: return f(n - 14);
		case 15: return f(n - 15);
		case 16: return f(n - 16);
		case 17: return f(n - 17);
		case 18: return f(n - 18);
		case 19: return f(n - 19);
		default: __builtin_unreachable();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; cout << f(n);
}