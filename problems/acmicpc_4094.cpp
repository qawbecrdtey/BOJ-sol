#include <cmath>
#include <iostream>
using namespace std;
using ld = long double;
class vector;
class matrix;
class point {
    ld x, y;
public:
    explicit point(ld const x = 0, ld const y = 0) : x(x), y(y) {}
    point &operator+=(vector const &v);
    point &operator-=(vector const &v);
    point operator+(vector const &v) const;
    point operator-(vector const &v) const;
    vector operator-(point const &p) const;
    [[nodiscard]] vector to_vector() const;
    friend ld dist(point const &a, point const &b);
    friend class vector;
    friend class matrix;
    friend istream &operator>>(istream &is, point &p) { is >> p.x >> p.y; return is; }
    friend ostream &operator<<(ostream &os, point const &p) { cout << p.x << ' ' << p.y; return os; }
};
class vector {
    ld x, y;
public:
    explicit vector(ld const x = 0, ld const y = 0) : x(x), y(y) {}
    vector &operator+=(vector const &v);
    vector &operator-=(vector const &v);
    vector &operator*=(ld const d);
    vector &operator/=(ld const d);
    vector operator-() const;
    vector operator+(vector const &v) const;
    point operator+(point const &p) const;
    vector operator-(vector const &v) const;
    ld operator*(vector const &v) const;
    vector operator*(ld const d) const;
    vector operator/(ld const d) const;
    [[nodiscard]] point to_point() const;
    [[nodiscard]] ld length() const;
    friend class point;
    friend class matrix;
};
class matrix {
    ld mat[4];
public:
    explicit matrix(ld const a, ld const b, ld const c, ld const d) : mat{a, b, c, d} {}
    explicit matrix(vector const a, vector const b) : mat{a.x, b.x, a.y, b.y} {}
    matrix &operator+=(matrix const &m) { for(int i = 0; i < 4; i++) mat[i] = m.mat[i]; return *this; }
    matrix &operator-=(matrix const &m) { return *this += -m; }
    matrix &operator*=(matrix const &m) { return *this = *this * m; }
    matrix &operator*=(ld const d) { for(auto &i : mat) i *= d; return *this; }
    matrix &operator/=(ld const d) { return *this *= 1 / d; }
    matrix operator-() const { auto n = *this; for(auto &i : n.mat) i = -i; return n; }
    matrix operator+(matrix const &m) const { auto n = *this; return n += m; }
    matrix operator-(matrix const &m) const { auto n = *this; return n -= m; }
    matrix operator*(matrix const &m) const { return matrix(mat[0] * m.mat[0] + mat[1] * m.mat[2], mat[0] * m.mat[1] + mat[1] * m.mat[3], mat[2] * m.mat[0] + mat[3] * m.mat[2], mat[2] * m.mat[1] + mat[3] * m.mat[3]); }
    vector operator*(vector const &v) const { return vector(mat[0] * v.x + mat[1] * v.y, mat[2] * v.x + mat[3] * v.y); }
    matrix operator*(ld const d) const { return matrix(mat[0] * d, mat[1] * d, mat[2] * d, mat[3] * d); }
    matrix operator/(ld const d) const { return matrix(mat[0] / d, mat[1] / d, mat[2] / d, mat[3] / d); }
    [[nodiscard]] matrix transpose() const { return matrix(mat[0], mat[2], mat[1], mat[3]); }
    [[nodiscard]] ld determinant() const { return mat[0] * mat[3] - mat[1] * mat[2]; }
    [[nodiscard]] matrix inverse() const { return matrix(mat[3], -mat[1], -mat[2], mat[0]) / determinant(); }
    friend class point;
    friend class vector;
};
point &point::operator+=(vector const &v) { x += v.x, y += v.y; return *this; }
point &point::operator-=(vector const &v) { x -= v.x, y -= v.y; return *this; }
point point::operator+(vector const &v) const { return point(x + v.x, y + v.y); }
point point::operator-(vector const &v) const { return point(x - v.x, y - v.y); }
vector point::operator-(point const &p) const { return vector(x - p.x, y - p.y); }
vector point::to_vector() const { return vector(x, y); }
ld dist(point const &a, point const &b) { return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
vector &vector::operator+=(vector const &v) { x += v.x, y += v.y; return *this; }
vector &vector::operator-=(vector const &v) { x -= v.x, y -= v.y; return *this; }
vector &vector::operator*=(ld const d) { x *= d, y *= d; return *this; }
vector &vector::operator/=(ld const d) { x /= d, y *= d; return *this; }
vector vector::operator-() const { return vector(-x, -y); }
vector vector::operator+(vector const &v) const { return vector(x + v.x, y + v.y); }
point vector::operator+(point const &p) const { return point(x + p.x, y + p.y); }
vector vector::operator-(vector const &v) const { return vector(x - v.x, y - v.y); }
ld vector::operator*(vector const &v) const { return x * v.x + y * v.y; }
vector vector::operator*(ld const d) const { return vector(x * d, y * d); }
vector vector::operator/(ld const d) const { return vector(x / d, y / d); }
point vector::to_point() const { return point(x, y); }
ld vector::length() const { return sqrtl(x * x + y * y); }
point get_center(point const &A, point const &B, point const &C) { // Circle which passes A and B, and has tangent BC.
    return (matrix(B - C, A - B).transpose().inverse() * vector((B - C) * B.to_vector(), (A.to_vector() * A.to_vector() - B.to_vector() * B.to_vector()) / 2)).to_point();
}
point get_intersection(point const &A, point const &B, point const &C, ld const rA, ld const rB, ld const rC) {
    return (matrix(A - B, C - B).transpose().inverse() * vector(A.to_vector() * A.to_vector() - B.to_vector() * B.to_vector() - rA * rA + rB * rB, C.to_vector() * C.to_vector() - B.to_vector() * B.to_vector() - rC * rC + rB * rB) / 2).to_point();
}
point get_point(point const &A, point const &B, point const &C) {
    point const AB = get_center(A, B, C);
    point const BC = get_center(B, C, A);
    point const CA = get_center(C, A, B);
    return get_intersection(AB, BC, CA, dist(AB, A), dist(BC, B), dist(CA, C));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int ax, ay, bx, by, cx, cy;
    cout.precision(2);
    while(cin >> ax >> ay >> bx >> by >> cx >> cy) {
        if(!ax && !ay && !bx && !by && !cx && !cy) return 0;
        point const A(ax, ay);
        point const B(bx, by);
        point const C(cx, cy);
        cout << fixed << get_point(A, B, C) << ' ' << get_point(A, C, B) << '\n';
    }
}