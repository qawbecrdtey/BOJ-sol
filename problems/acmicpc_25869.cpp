#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c; cin >> a >> b >> c;
	if(a <= 2 * c || b <= 2 * c) cout << 0;
	else cout << (a - 2 * c) * (b - 2 * c);
}