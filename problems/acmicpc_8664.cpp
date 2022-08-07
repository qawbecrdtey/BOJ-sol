#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	array<array<int, 2>, 4> a;
	for(auto &i : a) for(auto &j : i) cin >> j;
	sort(a.begin(), a.end(), [](array<int, 2> const &a, array<int, 2> const &b) { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
	/*for(auto &i : a) {
		for(auto &j : i) {
			cout << j << ' ';
		} cout << '\n';
	}*/
	if(a[0][0] == a[1][0] && a[0][1] == a[2][1] && a[1][1] == a[3][1] && a[2][0] == a[3][0] && a[1][1] - a[0][1] == a[2][0] - a[0][0] && a[1][1] != a[0][1]) {
		cout << "TAK";
	} else cout << "NIE";
}