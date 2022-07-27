#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c, d; while(cin >> a >> b >> c >> d) {
		if(!a && !b && !c && !d) return 0;
		int const x = min(c * 100 / a, d * 100 / b);
		int const y = min(c * 100 / b, d * 100 / a);
		cout << min(max(x, y), 100) << "%\n";
	}
}