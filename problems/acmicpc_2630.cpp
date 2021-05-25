#include <stdio.h>
#include <utility>
using namespace std;
pair<int, int> f(int **a, int l, int x, int y) {
	auto const c = a[x][y];
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++) {
			if(c != a[i + x][j + y]) {
				auto const p1 = f(a, l / 2, x, y);
				auto const p2 = f(a, l / 2, x + l / 2, y);
				auto const p3 = f(a, l / 2, x, y + l / 2);
				auto const p4 = f(a, l / 2, x + l / 2, y + l / 2);
				return make_pair(p1.first + p2.first + p3.first + p4.first, p1.second + p2.second + p3.second + p4.second);
			}
		}
	}
	return make_pair(1 - c, c);
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	auto const p = f(a, n, 0, 0);
	printf("%d\n%d", p.first, p.second);
}