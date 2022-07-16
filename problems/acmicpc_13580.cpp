#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c; cin >> a >> b >> c;
	if(a == b || b == c || c == a || a + b == c || b + c == a || c + a == b) cout << "S";
	else cout << "N";
}