#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, c; cin >> n >> c;
	int a = n, b = n;
	while(c--) {
		int x, y; cin >> x >> y;
		if(x >= a || y >= b) continue;
		int const hor = a * y;
		int const ver = x * b;
		if(hor > ver) b = y;
		if(ver >= hor) a = x;
	} cout << a * b;
}