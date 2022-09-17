#include <iostream>
#include <vector>
using namespace std;
inline constexpr int M = 1000;
using ll = long long;
class matrix {
	int n;
	vector<int> mat;
	[[nodiscard]] matrix mul(matrix const &m) const {
		matrix res(n);
		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					res(i, j) += (*this)(i, k) * m(k, j);
					res(i, j) %= M;
				}
			}
		} return res;
	}
	matrix &add_eq(matrix const &m) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				(*this)(i, j) += m(i, j);
				(*this)(i, j) %= M;
			}
		} return *this;
	}
	[[nodiscard]] matrix add(matrix const &m) const {
		matrix res(*this);
		return res.add_eq(m);
	}
public:
	explicit matrix(int n) : n(n), mat(n * n) {}
	int &operator()(int r, int c) { return mat[r * n + c]; }
	[[nodiscard]] int operator()(int r, int c) const { return mat[r * n + c]; }
	[[nodiscard]] matrix operator*(matrix const &m) const { return mul(m); }
	[[nodiscard]] matrix operator+(matrix const &m) const { return add(m); }
	matrix &operator+=(matrix const &m) { return add_eq(m); }
	friend istream &operator>>(istream &is, matrix &m) {
		for(int i = 0; i < m.n; i++) {
			for(int j = 0; j < m.n; j++) {
				is >> m(i, j);
				m(i, j) %= M;
			}
		} return is;
	}
	friend ostream &operator<<(ostream &os, matrix const &m) {
		for(int i = 0; i < m.n; i++) {
			for(int j = 0; j < m.n; j++) {
				cout << m(i, j) << ' ';
			} cout << '\n';
		} return os;
	}
	static matrix identity(int n) {
		matrix m(n);
		for(int i = 0; i < n; i++) {
			m(i, i) = 1;
		} return m;
	}
	friend matrix power(matrix const &m, ll b) {
		if(!b) return matrix::identity(m.n);
		if(b == 1) return m;
		auto const r = power(m, b >> 1);
		return r * r * power(m, b & 1);
	}
	friend matrix f(matrix const &m, ll b) {
		if(b == 1) return m;
		auto const r = f(m, b >> 1);
		return r + r * power(m, b >> 1) + ((b & 1) ? power(m, b) : matrix(m.n));
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; ll b; cin >> n >> b; matrix m(n); cin >> m;
	cout << f(m, b);
}