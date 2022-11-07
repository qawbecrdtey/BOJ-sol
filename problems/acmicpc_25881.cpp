#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, n; cin >> a >> b >> n;
	while(n--) {
		int x; cin >> x; cout << x << ' ';
		if(x <= 1000) cout << x * a << '\n';
		else cout << 1000 * a + (x - 1000) * b << '\n';
	}
}