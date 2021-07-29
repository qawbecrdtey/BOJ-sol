#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
using line = pair<point, point>;
ll ccw(point const &x, point const &y, point const &z) {
	ll res = x.first * y.second + y.first * z.second + z.first * x.second;
	res -= x.second * y.first + y.second * z.first + z.second * x.first;
	if(!res) return 0;
	if(res > 0) return 1;
	return -1;
}
bool intersect(line const &x, line const &y) {
	auto const &a = x.first;
	auto const &b = x.second;
	auto const &c = y.first;
	auto const &d = y.second;
	auto const ab = ccw(a, b, c) * ccw(a, b, d);
	auto const cd = ccw(c, d, a) * ccw(c, d, b);
	if(ab == 0 && cd == 0) {
		return min(a, b) <= max(c, d) && min(c, d) <= max(a, b);
	}
	return ab <= 0 && cd <= 0;
}
int main() {
	line a, b;
	cin >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
	cin >> b.first.first >> b.first.second >> b.second.first >> b.second.second;
	cout << intersect(a, b);
}