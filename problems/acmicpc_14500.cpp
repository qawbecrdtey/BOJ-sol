#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
template<int n, int m>
struct plate {
	array<array<int, m>, n> arr;
	int calc(int **a, int x, int y) const {
		int res = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				res += a[x + i][y + j] * arr[i][j];
			}
		} return res;
	}
};
template<int r, int c>
int calc(int **a, int n, int m, plate<r, c> const &p) {
	int res = 0;
	for(int i = 0; i <= n - r; i++) {
		for(int j = 0; j <= m - c; j++) {
			res = max(res, p.calc(a, i, j));
		}
	} return res;
}
#define C(x) calc(a, n, m, x)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[m];
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}
	plate<1, 4> i1{{1, 1, 1, 1}};
	plate<4, 1> i2{{1, 1, 1, 1}};
	plate<2, 2> o{{1, 1, 1, 1}};
	plate<2, 3> l1{{1, 1, 1, 1, 0, 0}};
	plate<2, 3> l2{{1, 1, 1, 0, 0, 1}};
	plate<2, 3> l3{{1, 0, 0, 1, 1, 1}};
	plate<2, 3> l4{{0, 0, 1, 1, 1, 1}};
	plate<3, 2> l5{{1, 1, 0, 1, 0, 1}};
	plate<3, 2> l6{{1, 1, 1, 0, 1, 0}};
	plate<3, 2> l7{{1, 0, 1, 0, 1, 1}};
	plate<3, 2> l8{{0, 1, 0, 1, 1, 1}};
	plate<2, 3> s1{{1, 1, 0, 0, 1, 1}};
	plate<2, 3> s2{{0, 1, 1, 1, 1, 0}};
	plate<3, 2> s3{{1, 0, 1, 1, 0, 1}};
	plate<3, 2> s4{{0, 1, 1, 1, 1, 0}};
	plate<2, 3> t1{{1, 1, 1, 0, 1, 0}};
	plate<2, 3> t2{{0, 1, 0, 1, 1, 1}};
	plate<3, 2> t3{{1, 0, 1, 1, 1, 0}};
	plate<3, 2> t4{{0, 1, 1, 1, 0, 1}};
	cout << max({C(i1), C(i2), C(o), C(l1), C(l2), C(l3), C(l4), C(l5), C(l6), C(l7), C(l8), C(s1), C(s2), C(s3), C(s4), C(t1), C(t2), C(t3), C(t4)});
}