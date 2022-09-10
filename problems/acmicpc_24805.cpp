#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, h; cin >> a >> b >> h;
	int cur = 0, cnt = 1;
	while(cur < h) {
		cur += a;
		if(cur >= h) {
			cout << cnt;
			return 0;
		}
		cur -= b;
		cnt++;
	}
}