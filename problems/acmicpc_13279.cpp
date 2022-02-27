#include <complex>
#include <iostream>
#include <vector>
using namespace std;
using cld = complex<long double>;
using ll = unsigned long long;
template<bool inv>
inline void fft(vector<cld> &a) {
	ll const n = a.size();
	for(ll i = 1, j = 0; i < n; i++) {
		ll bit = n >> 1;
		while(!((j ^= bit) & bit)) bit >>= 1;
		if(i < j) swap(a[i], a[j]);
	}
	for(ll i = 1; i < n; i <<= 1) {
		cld w(cos(M_PIl / i), sin(M_PIl / i));
		if constexpr(inv) w = conj(w);
		for(ll j = 0; j < n; j += (i << 1)) {
			cld ww(1);
			for(ll k = 0; k < i; k++) {
				cld const tmp = a[i + j + k] * ww;
				a[i + j + k] = a[j + k] - tmp;
				a[j + k] += tmp;
				ww *= w;
			}
		}
	}
	if constexpr(inv) {
		for(auto &now : a) now /= n;
	}
}
inline vector<cld> mul(vector<cld> a, vector<cld> b) {
	ll N = a.size();
	while(N < a.size() + b.size()) N <<= 1;
	a.resize(N); b.resize(N);
	fft<false>(a);
	fft<false>(b);
	for(ll i = 0; i < a.size(); i++) a[i] *= b[i];
	fft<true>(a);
	return a;
}
vector<cld> mul(vector<cld> const &a, ll l, ll r) {
	if(l + 1 == r) {
		vector<cld> v = { a[l], 1 };
		return v;
	}
	ll const m = (l + r) >> 1;
	auto x = mul(a, l, m);
	auto y = mul(a, m, r);
	for(auto &now : x) now = (ll)(round(now.real())) % 100003;
	for(auto &now : y) now = (ll)(round(now.real())) % 100003;
	return mul(move(x), move(y));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n, m, x, N = 1; cin >> n;
	while(N < (n << 1)) N <<= 1;
	vector<cld> a; a.reserve(n);
	for(ll i = 0; i < n; i++) { cin >> x; a.emplace_back(x); }
	a = mul(a, 0, n);
	cin >> m; while(m--) {
		cin >> x; cout << (ll)(round(a[n - x].real())) % 100003 << '\n';
	}
}