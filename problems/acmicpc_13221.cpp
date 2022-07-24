#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, n, m = INT32_MAX;
	cin >> a >> b >> n;
	pair<int, int> res;
	while(n--) {
		int x, y; cin >> x >> y;
		int d = abs(x - a) + abs(y - b);
		if(m > d) m = d, res = {x, y};
	} cout << res.first << ' ' << res.second;
}