#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int x, y; cin >> x >> y;
	if(y <= x) cout << x + y;
	else cout << y - x;
}