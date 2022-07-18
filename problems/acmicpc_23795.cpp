#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n = 0, x; while(cin >> x) {
		if(x == -1) {
			cout << n;
			return 0;
		} n += x;
	}
}