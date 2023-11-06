#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
class rat {
    __int128_t x, y; // x / y, y > 0
public:
    rat() : x(0), y(1) {}
    rat(__int128_t x) : x(x), y(1) {}
    rat(__int128_t x, __int128_t y) : x(x), y(y) {
        assert(y != 0);
        __int128_t g = std::gcd(x, y);
        if(y < 0) g = -g;
        this->x /= g, this->y /= g;
    }
    friend rat abs(rat const &r) { return { std::abs(r.x), r.y }; }
    rat operator-() const { return { -x, y }; }
    rat operator+(rat const &r) const { return {x * r.y + y * r.x, y * r.y}; }
    rat operator-(rat const &r) const { return {x * r.y - y * r.x, y * r.y}; }
    rat operator*(rat const &r) const { return {x * r.x, y * r.y}; }
    rat operator/(rat const &r) const { assert(r.x != 0); return {x * r.y, y * r.x}; }
    bool operator==(rat const &r) const { return x == r.x && y == r.y; }
    bool operator!=(rat const &r) const { return x != r.x || y != r.y; }
    bool operator<(rat const &r) const { return x * r.y < r.x * y; }
    bool operator>(rat const &r) const { return r < *this; }
    bool operator<=(rat const &r) const { return *this == r || *this < r; }
    bool operator>=(rat const &r) const { return *this == r || r < *this; }
    friend std::ostream &operator<<(std::ostream &os, rat const &r) {
        os.precision(12);
        os << std::fixed << static_cast<long double>(r.x) / static_cast<long double>(r.y);
        return os;
    }
};
class vector;
class point {
    rat x, y;
public:
    point() : x(0), y(0) {}
    point(rat x, rat y) : x(x), y(y) {}
    vector operator+(point const &p) const;
    vector operator-(point const &p) const;
    friend point operator+(point const &p, vector const &v);
    bool operator==(point const &p) const { return x == p.x && y == p.y; }
    bool operator!=(point const &p) const { return x != p.x || y != p.y; }
    bool operator<(point const &p) const { return x < p.x || (x == p.x && y < p.y); }
    bool operator>(point const &p) const { return *this < p; }
    bool operator<=(point const &p) const { return *this == p || *this < p; }
    bool operator>=(point const &p) const { return *this == p || p < *this; }
    friend std::ostream &operator<<(std::ostream &os, point const &p) {
        os << p.x << ' ' << p.y;
        return os;
    }
    friend class vector;
};
class vector {
public:
    rat x, y;
    vector() : x(0), y(0) {}
    vector(rat x, rat y) : x(x), y(y) {}
    vector operator-() const { return { -x, -y }; }
    vector operator+(vector const &v) const { return { x + v.x, y + v.y }; }
    vector operator-(vector const &v) const { return { x - v.x, y - v.y }; }
    vector operator+(point const &p) const { return { x + p.x, y + p.y }; }
    vector operator*(rat const &r) const { return { x * r, y * r }; }
    bool operator==(vector const &v) const { return x == v.x && y == v.y; }
    bool operator!=(vector const &v) const { return x != v.x || y != v.y; }
    [[nodiscard]] vector simpler() const {
        if(y == 0) return { 1, 0 };
        return { x / y, 1 };
    }
    [[nodiscard]] bool is_zero() const { return x == 0 && y == 0; }
    [[nodiscard]] vector elementwise_division(vector const &v) const {
        assert(v.x != 0 && v.y != 0);
        return { x / v.x, y / v.y };
    }
    [[nodiscard]] bool special_condition() const { return x >= 0 && x <= 1 && y >= 0 && y <= 1; }
    friend class mat;
};
class mat {
    rat a[4];
    // 0 2
    // 1 3
public:
    mat(vector const &a, vector const &b) : a{ a.x, a.y, b.x, b.y } {}
    mat(rat const &a, rat const &b, rat const &c, rat const &d) : a{ a, b, c, d } {}
    [[nodiscard]] rat det() const { return a[0] * a[3] - a[1] * a[2]; }
    [[nodiscard]] mat inverse() const {
        auto const d = det();
        assert(d != 0);
        auto const m = rat(1) / d;
        return { m * a[3], -m * a[1], -m * a[2], m * a[0] };
    }
    vector operator*(vector const &v) const { return { a[0] * v.x + a[2] * v.y, a[1] * v.x + a[3] * v.y }; }
};
vector point::operator-(point const &p) const { return { x - p.x, y - p.y }; }
point operator+(point const &p, vector const &v) { return { p.x + v.x, p.y + v.y }; }
point operator-(point const &p, vector const &v) { return p + (-v); }
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    point p[4];
    for(auto &pt : p) { int64_t x, y; std::cin >> x >> y; pt = { x, y }; }
    std::sort(p, p + 2); std::sort(p + 2, p + 4);
    auto va = p[1] - p[0];
    auto vb = p[3] - p[2];
    if(va.simpler() != vb.simpler() && va != vector(0, 0) && vb != vector(0, 0)) {
        auto const st = mat(va, -vb).inverse() * (p[2] - p[0]);
        if(!st.special_condition()) { std::cout << 0; return 0; }
        std::cout << "1\n" << p[0] + (p[1] - p[0]) * st.x;
        return 0;
    }
    else { // singular
        if(p[0] == p[1] && p[2] == p[3]) {
            if(p[0] == p[3]) { std::cout << "1\n" << p[0]; return 0; }
            std::cout << 0; return 0;
        }
        if(p[0] == p[1]) {
            if(vb.simpler() != ((p[2] - p[0]) + (p[3] - p[0])).simpler()) { std::cout << 0; return 0; }
            std::cout << "1\n" << p[0];
            return 0;
        }
        if(p[2] == p[3]) {
            if(va.simpler() != ((p[0] - p[2]) + (p[1] - p[2])).simpler()) { std::cout << 0; return 0; }
            std::cout << "1\n" << p[2];
            return 0;
        }
        if(((p[2] - p[0]) + (p[3] - p[0])).simpler() != va.simpler()) { std::cout << 0; return 0; }
        if(p[3] < p[0] || p[1] < p[2]) { std::cout << 0; return 0; }
        if(p[1] == p[2]) { std::cout << "1\n" << p[1]; return 0; }
        if(p[0] == p[3]) { std::cout << "1\n" << p[0]; return 0; }
        if((p[1] <= p[3] && p[2] < p[1]) || (p[3] <= p[1] && p[0] < p[3])) { std::cout << 1; return 0; }
        assert(false);
    }
}