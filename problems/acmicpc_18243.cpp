#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
struct matrix {
	int n;
	vector<int> mat;
	explicit matrix(int n) : n(n), mat(n * n) {}
	int &operator()(int r, int c) {
		assert(r < n && c < n && r >= 0 && c >= 0);
		return mat[r * n + c];
	}
	int operator()(int r, int c) const {
		assert(r < n && c < n && r >= 0 && c >= 0);
		return mat[r * n + c];
	}
	matrix &operator+=(matrix const &m) {
		for(int i = 0; i < n * n; i++) {
			mat[i] |= m.mat[i];
		} return *this;
	}
	[[nodiscard]] matrix operator+(matrix const &m) const {
		matrix res(*this);
		return res += m;
	}
	[[nodiscard]] matrix operator*(matrix const &m) const {
		matrix res(n);
		for(int k = 0; k < n; k++) {
			for(int r = 0; r < n; r++) {
				for(int c = 0; c < n; c++) {
					res(r, c) |= ((*this)(r, k) & m(k, c));
				}
			}
		} return res;
	}
	static matrix identity(int n) {
		matrix id(n);
		for(int r = 0; r < n; r++) {
			for(int c = 0; c < n; c++) {
				id(r, c) = (r == c);
			}
		} return id;
	}
};
matrix power(matrix const &m, int n) {
	if(!n) return matrix::identity(m.n);
	if(n == 1) return m;
	matrix r = power(m, n >> 1);
	return r * r * power(m, n & 1);;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	matrix M = matrix::identity(n);
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y; x--; y--;
		M(x, y) = M(y, x) = 1;
	}
	M = power(M, 6);
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			if(!M(r, c)) {
				cout << "Big World!";
				return 0;
			}
		}
	} cout << "Small World!";
}