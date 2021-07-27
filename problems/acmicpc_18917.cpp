#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	cin >> m;
	ll sum = 0, xro = 0;
	while(m--) {
		int x;
		cin >> x;
		if(x == 1) {
			int y;
			cin >> y;
			sum += y;
			xro ^= y;
		}
		else if(x == 2) {
			int y;
			cin >> y;
			sum -= y;
			xro ^= y;
		}
		else if(x == 3) {
			cout << sum << '\n';
		}
		else {
			cout << xro << '\n';
		}
	}
}