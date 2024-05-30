#include <cassert>
#include <initializer_list>
#include <iostream>
#include <memory>
using namespace std;
using ll = long long;
static constexpr ll M = 998244353;
class matrix {
public:
    matrix(ll n, ll m) : n(n), m(m), mat(make_unique<ll[]>(n * m)) {}
    matrix(ll n, ll m, initializer_list<ll> l) : n(n), m(m), mat(make_unique<ll[]>(n * m)) {
        copy(l.begin(), l.end(), mat.get());
    }
    matrix(matrix const &A) : n(A.n), m(A.m), mat(make_unique<ll[]>(A.n * A.m)) {
        copy(A.mat.get(), A.mat.get() + A.n * A.m, mat.get());
    }
    matrix(matrix &&A) noexcept : n(A.n), m(A.m), mat(std::move(A.mat)) {}
    static matrix identity(ll n) {
        matrix res(n, n);
        for(int i = 0; i < n; i++) {
            res(i, i) = 1;
        }
        return res;
    }
    ll &operator()(ll r, ll c) { return mat[r * m + c]; }
    ll operator()(ll r, ll c) const { return mat[r * m + c]; }
    friend istream &operator>>(istream &is, matrix &m) {
        for(ll i = 0; i < m.n; i++) {
            for(ll j = 0; j < m.m; j++) {
                is >> m(i, j);
            }
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, matrix const &A) {
        for(ll i = 0; i < A.n; i++) {
            for(ll j = 0; j < A.m; j++) {
                os << A(i, j) << ' ';
            }
            os << '\n';
        }
        return os;
    }
    matrix operator*(matrix const &mat) const {
        assert(m == mat.n);
        matrix res(n, mat.m);
        for(ll i = 0; i < n; i++) {
            for(ll k = 0; k < mat.m; k++) {
                for(ll j = 0; j < m; j++) {
                    res(i, k) += ((*this)(i, j) * mat(j, k)) % M;
                    res(i, k) %= M;
                }
            }
        }
        return res;
    }
    friend matrix power(matrix const &m, ll n) {
        assert(m.n == m.m);
        if(!n) return matrix::identity(m.n);
        if(n == 1) return m;
        auto const r = power(m, n >> 1);
        return r * r * power(m, n & 1);
    }
    
private:
    ll n;
    ll m;
    unique_ptr<ll[]> mat;
};
inline ll f(ll n) {
    // 1, 1, 1, 2, 2
    // a_{n} = a_{n - 1} + a_{n - 5}
    matrix const v(5, 1, {1, 0, 1, 0, 0});
    matrix const m(5, 5, {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0});
    return (power(m, n) * v)(0, 0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        cout << f(n - 1) << '\n';
    }
}
