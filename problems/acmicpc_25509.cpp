#include <cassert>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>
using ll = long long;
class polynomial {
	ll M;
	std::vector<ll> coeff;
	void clean() noexcept { while(!coeff.empty() && !coeff.back()) coeff.pop_back(); }
public:
	polynomial() = delete;
	explicit polynomial(ll M) : M(M) {}
	polynomial(ll M, std::vector<ll> coeff) noexcept : M(M), coeff(std::move(coeff)) { clean(); }
	polynomial(polynomial const&) = default;
	polynomial(polynomial&&) noexcept = default;
	polynomial &operator=(polynomial const&) = default;
	polynomial &operator=(polynomial&&) noexcept  = default;
	static polynomial monic_polynomial(ll M, ll leading, ll deg) {
		polynomial poly(M);
		poly.coeff.resize(deg + 1);
		poly.coeff.back() = (leading % M + M) % M;
		poly.clean();
		return poly;
	}
	polynomial &operator+=(polynomial const &poly) {
		assert(poly.M == M);
		std::vector<ll> vec(std::max(coeff.size(), poly.coeff.size()));
		ll i;
		for(i = 0; i < poly.coeff.size() && i < coeff.size(); i++) {
			vec[i] = coeff[i] + poly.coeff[i];
		}
		for(; i < poly.coeff.size(); i++) {
			vec[i] = poly.coeff[i];
		}
		for(; i < coeff.size(); i++) {
			vec[i] = coeff[i];
		}
		coeff = std::move(vec);
		return *this;
	}
	polynomial &operator*=(polynomial const &poly) {

	}
	polynomial operator+(polynomial const &poly) const {
		polynomial p(*this);
		return p += poly;
	}
	polynomial operator*(polynomial const &poly) const {
		assert(poly.M == M);
		polynomial p(M);

	}
	[[nodiscard]] bool is_zero() const noexcept { return coeff.empty(); }
	[[nodiscard]] size_t degree() const { assert(!is_zero()); return coeff.size() - 1; }
};
class matrix_ll {
	ll n, m;
	std::unique_ptr<ll[]> mat;
public:
	matrix(ll n, ll m) : n(n), m(m), mat(std::make_unique<ll[]>(n * n)) {}

	friend std::istream &operator>>(std::istream &is, matrix &M) {
		for(ll i = 0; i < M.n * M.n; i++) {
			is >> M.mat[i];
		} return is;
	}
};
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	ll n, m; std::cin >> n >> m;
	matrix M(n, m); std::cin >> M;
}