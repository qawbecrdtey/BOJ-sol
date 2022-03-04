#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;
using cd = complex<double>;
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int N = 1; while(N < n * 3) N <<= 1;
    vector<cd> a(N), b(n);
    for(int i = 0; i < n; i++) { cin >> a[i]; a[n + i] = a[i]; }
    for(int i = 0; i < n; i++) cin >> b[i];
    reverse(b.begin(), b.end()); b.resize(N);
    fft<false>(a); fft<false>(b);
    for(int i = 0; i < N; i++) a[i] *= b[i];
    fft<true>(a);
    double max = 0;
    for(auto now : a) if(max < now.real()) max = now.real();
    cout << (int)round(max);
}