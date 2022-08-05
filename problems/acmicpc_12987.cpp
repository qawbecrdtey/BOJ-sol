#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
struct matrix {
	int n, m;
	vector<int> mat;
	matrix(int n, int m) : n(n), m(m), mat(n * n) {}
	int &operator()(int r, int c) {
		assert(r < n && c < n && r >= 0 && c >= 0);
		return mat[r * n + c];
	}
	int operator()(int r, int c) const {
		assert(r < n && c < n && r >= 0 && c >= 0);
		return mat[r * n + c];
	}
	matrix &operator+=(matrix const &M) {
		for(int i = 0; i < n * n; i++) {
			mat[i] = (mat[i] + M.mat[i]) % m;
		}
		return *this;
	}
	matrix operator+(matrix const &M) const {
		matrix res(*this); return res += M;
	}
	matrix operator*(matrix const &M) const {
		matrix res(n, m);
		for(int k = 0; k < n; k++) {
			for(int r = 0; r < n; r++) {
				for(int c = 0; c < n; c++) {
					res(r, c) = (res(r, c) + ((*this)(r, k) * M(k, c)) % m) % m;
				}
			}
		}
		return res;
	}
	static matrix identity(int n, int m) {
		matrix res(n, m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				res(i, j) = (i == j);
			}
		} return res;
	}
};
matrix power(matrix const &A, int p) {
	if(!p) return matrix::identity(A.n, A.m);
	if(p == 1) return A;
	auto r = power(A, p >> 1);
	return r * r * power(A, p & 1);
}
matrix calc(matrix const &A, int k) {
	if(k == 1) return A;
	if(k & 1) return A * (matrix::identity(A.n, A.m) + calc(A, k ^ 1));
	auto r = calc(A, k >> 1);
	auto s = matrix::identity(A.n, A.m) + power(A, k >> 1);
	return r * s;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k, m; cin >> n >> k >> m;
	matrix A(n, m);
	for(int i = 0; i < n * n; i++) {
		cin >> A.mat[i];
		if(A.mat[i] < 0) {
			A.mat[i] = (m - (-A.mat[i]) % m) % m;
		}
		else A.mat[i] %= m;
	}
	auto res = calc(A, k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << res(i, j) << ' ';
		} cout << '\n';
	}
}