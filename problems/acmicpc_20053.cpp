#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		int min = 1000001, max = -1000001;
		while(n--) {
			int x;
			cin >> x;
			if(x < min) min = x;
			if(x > max) max = x;
		}
		cout << min << ' ' << max << '\n';
	}
}