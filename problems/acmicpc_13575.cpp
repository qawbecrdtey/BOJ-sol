#pragma GCC optimize("Ofast")
#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;
using cd = complex<long double>;
template<bool inv>
inline void fft(vector<cd> &a) {
	int const n = a.size();
	for(int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		while(!((j ^= bit) & bit)) bit >>= 1;
		if(i < j) swap(a[i], a[j]);
	}
	for(int i = 1; i < n; i <<= 1) {
		cd w(cos(M_PI / i), sin(M_PI / i));
		if constexpr(inv) w = conj(w);
		for(int j = 0; j < n; j += (i << 1)) {
			cd ww(1);
			for(int k = 0; k < i; k++) {
				cd const tmp = a[i + j + k] * ww;
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
inline void square(vector<cd> &a) {
	int N = 1; while(N < (a.size() << 1)) N <<= 1;
	a.resize(N);
	fft<false>(a);
	for(auto &now : a) now *= now;
	fft<true>(a);
	for(auto &now : a) now = (((int)round(now.real())) != 0);
	while(!a.empty() && !(int)round(a.back().real())) a.pop_back();
}
inline void mul(vector<cd> &a, vector<cd> b) {
	int N = 1; while(N < a.size() + b.size()) N <<= 1;
	a.resize(N); b.resize(N);
	fft<false>(a); fft<false>(b);
	for(int i = 0; i < N; i++) a[i] *= b[i];
	fft<true>(a);
	for(auto &now : a) now = (((int)round(now.real())) != 0);
	while(!a.empty() && !(int)round(a.back().real())) a.pop_back();
}
inline void power(vector<cd> &a, int k) {
	vector<cd> b = { 1 };
	while(k) {
		if(k & 1) mul(b, a);
		square(a);
		k >>= 1;
	}
	a = move(b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto arr = new int[n]; int max = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(max < arr[i]) max = arr[i];
	}
	vector<cd> a(max + 1);
	for(int i = 0; i < n; i++) a[arr[i]] = 1;
	delete[] arr;
	power(a, k);
	for(int i = 0; i < a.size(); i++) {
		if((int)round(a[i].real())) cout << i << ' ';
	}
}