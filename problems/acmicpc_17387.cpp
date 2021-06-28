#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
using line = pair<point, point>;
ll ccw(point const &x, point const &y, point const &z) {
    ll res = x.first * y.second + y.first * z.second + z.first * x.second;
    res -= x.second * y.first + y.second * z.first + z.second * x.first;
    if(res == 0) return 0;
    if(res > 0) return 1;
    return -1;
}
bool intersect(line const &x, line const &y) {
    point const &a = x.first;
    point const &b = x.second;
    point const &c = y.first;
    point const &d = y.second;
    auto const ab = ccw(a, b, c) * ccw(a, b, d);
    auto const cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0) return min(c, d) <= max(a, b) && min(a, b) <= max(c, d);
    return ab <= 0 && cd <= 0;
}
int main() {
    line a, b;
    cin >> a.first.first >> a.first.second >> a.second.first >> a.second.second;
    cin >> b.first.first >> b.first.second >> b.second.first >> b.second.second;
    cout << (intersect(a, b) ? 1 : 0);
}