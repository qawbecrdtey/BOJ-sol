#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while(cin >> n) {
		int m = 1, cnt = 1;
		while(true) {
			if(m % n) {
				m = (m * 10 + 1) % n;
				cnt++;
			} else {
				cout << cnt << '\n';
				break;
			}
		}
	}
}