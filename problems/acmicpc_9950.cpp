#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c; while(cin >> a >> b >> c) {
		if(!a && !b && !c) return 0;
		if(!a) cout << c / b << ' ' << b << ' ' << c << '\n';
		else if(!b) cout << a << ' ' << c / a << ' ' << c << '\n';
		else cout << a << ' ' << b << ' ' << a * b << '\n';
	}
}