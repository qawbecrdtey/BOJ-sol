#include <algorithm>
#include <iostream>
#include <random>
using namespace std;
static auto random_engine() { // inclusive
    static random_device rd{};
    static default_random_engine engine(rd());
    return engine;
}
inline double dist(pair<double, double> const &a, pair<double, double> const &b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
struct circle {
    pair<double, double> center;
    double radius;
    [[nodiscard]] bool contains(pair<double, double> const &p) const noexcept {
        return dist(p, center) <= radius + 1e-9;
    }
};
bool ccw(pair<double, double> const &a, pair<double, double> const &b, pair<double, double> const &c) {
    double r = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
    return !(r >= -1e-9 && r <= 1e-9);
}
inline circle with_two_points(pair<double, double> const &a, pair<double, double> const &b) {
    return { { (a.first + b.first) / 2, (a.second + b.second) / 2 }, dist(a, b) / 2 };
}
inline circle with_three_points(pair<double, double> const &a, pair<double, double> const &b, pair<double, double> const &c) {
    if(!ccw(a, b, c)) return with_two_points(min({ a, b, c }), max({ a, b, c }));
    pair<double, double> center {
            ((a.first * a.first + a.second * a.second - b.first * b.first - b.second * b.second) * (a.second - c.second) - (a.first * a.first + a.second * a.second - c.first * c.first - c.second * c.second) * (a.second - b.second))
            / (2 * ((a.first - b.first) * (a.second - c.second) - (a.first - c.first) * (a.second - b.second))),
            ((a.first - b.first) * (a.first * a.first + a.second * a.second - c.first * c.first - c.second * c.second) - (a.first - c.first) * (a.first * a.first + a.second * a.second - b.first * b.first - b.second * b.second))
            / (2 * ((a.first - b.first) * (a.second - c.second) - (a.first - c.first) * (a.second - b.second)))
    };
    return { center, dist(center, a) };
}
circle new_circ_with_two_points(pair<double, double> *begin, pair<double, double> *end, pair<double, double> const &p, pair<double, double> const &q) {
    shuffle(begin, end, random_engine());
    circle circ = with_two_points(p, q);
    for(auto it = begin; it != end; ++it) {
        if(circ.contains(*it)) continue;
        circ = with_three_points(*it, p, q);
    } return circ;
}
circle new_circ_with_one_point(pair<double, double> *begin, pair<double, double> *end, pair<double, double> const &p) {
    shuffle(begin, end, random_engine());
    circle circ = with_two_points(*begin, p);
    for(auto it = begin + 1; it != end; ++it) {
        if(circ.contains(*it)) continue;
        circ = new_circ_with_two_points(begin, it, p, *it);
    } return circ;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<double, double>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    } shuffle(a, a + n, random_engine());
    circle circ(with_two_points(a[0], a[1]));
    for(int i = 2; i < n; i++) {
        if(circ.contains(a[i])) continue;
        circ = new_circ_with_one_point(a, a + i, a[i]);
    } cout.precision(3);
    cout << fixed << circ.center.first << ' ' << circ.center.second << '\n' << circ.radius;
}