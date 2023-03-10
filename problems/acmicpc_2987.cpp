#include <cassert>
#include <iostream>
using namespace std;
struct point {
    int x;
    int y;
    bool operator<(point const &p) const { return x < p.x || (x == p.x && y < p.y); }
    bool operator<=(point const &p) const { return x < p.x || (x == p.x && y <= p.y); }
};
inline int size2(point const &p, point const &q, point const &r) {
    return p.x * q.y + q.x * r.y + r.x * p.y - p.y * q.x - q.y * r.x - r.y * p.x;
}
inline int ccw(point const &p, point const &q, point const &r) {
    int const res = size2(p, q, r);
    if(!res) return 0;
    if(res > 0) return 1;
    return -1;
}
inline bool is_inside_triangle(point const &a, point const &b, point const &c, point const &p) {
    assert(ccw(a, b, c) == 1);
    return ccw(a, b, p) == 1 && ccw(b, c, p) == 1 && ccw(c, a, p) == 1;
}
inline bool on_segment(point a, point b, point const &p) {
    if(b < a) swap(a, b);
    return ccw(a, b, p) == 0 && a <= p && p <= b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    point tri[3]; for(auto &p : tri) cin >> p.x >> p.y;
    if(ccw(tri[0], tri[1], tri[2]) != 1) swap(tri[0], tri[1]);
    int s = abs(size2(tri[0], tri[1], tri[2]));
    cout << s / 2 << (s & 1 ? ".5\n" : ".0\n");
    int cnt = 0;
    int q; cin >> q; while(q--) {
        point p; cin >> p.x >> p.y;
        cnt += (is_inside_triangle(tri[0], tri[1], tri[2], p) || on_segment(tri[0], tri[1], p) || on_segment(tri[1], tri[2], p) || on_segment(tri[2], tri[0], p));
    } cout << cnt;
}