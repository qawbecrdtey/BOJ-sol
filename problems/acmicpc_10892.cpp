#include <algorithm>
#include <iostream>
using namespace std;
struct info { int x, y, i; };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new info[n * 3];
	for(int i = 0; i < n * 3; i++) {
		cin >> a[i].x >> a[i].y; a[i].i = i + 1;
	}
	sort(a, a + n * 3, [](info const &a, info const &b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	});
	for(int i = 0; i < n * 3; i += 3) {
		cout << a[i].i << ' ' << a[i + 1].i << ' ' << a[i + 2].i << '\n';
	}
}