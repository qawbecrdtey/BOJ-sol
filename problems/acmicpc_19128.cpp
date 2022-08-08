#include <cmath>
#include <iostream>
using namespace std;
struct point{ long double x, y; };
inline long double dist(point const &a, point const &b) {
	return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	point p[3];
	for(auto &i : p) cin >> i.x >> i.y;
	cout.precision(12);
	cout << fixed << dist(p[2], p[0]) + dist(p[2], p[1]) * 2;
}