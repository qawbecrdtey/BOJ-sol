#include <iostream>
using namespace std;
inline void left(int way[2]) {
	int x = -way[1];
	int y = way[0];
	way[0] = x;
	way[1] = y;
}
inline void right(int way[2]) {
	int x = way[1];
	int y = -way[0];
	way[0] = x;
	way[1] = y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, t; cin >> n >> t;
	int ans[2]{};
	int way[2] { 1, 0 };
	int time = 0;
	while(n--) {
		int tt; string s; cin >> tt >> s;
		ans[0] += (tt - time) * way[0];
		ans[1] += (tt - time) * way[1];
		time = tt;
		if(s == "left") left(way);
		else right(way);
	}
	ans[0] += (t - time) * way[0];
	ans[1] += (t - time) * way[1];
	cout << ans[0] << ' ' << ans[1];
}