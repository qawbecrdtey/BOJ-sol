#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while(true) {
		cin >> n;
		if(!n) return 0;
		int a = 0, b = 0;
		while(n--) {
			int x; cin >> x;
			a += !x, b += x;
		}
		cout << "Mary won " << a << " times and John won " << b << " times\n";
	}
}