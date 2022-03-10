#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using cd = complex<double>;
template<bool inv>
void fft(vector<cd> &a) {
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
inline int RPS(char c, int n) {
    switch(n) {
        case 0: return c == 'S';
        case 1: return c == 'R';
        case 2: return c == 'P';
        default: __builtin_unreachable();
    }
}
inline int YMC(char c, int n) {
    switch(n) {
        case 0: return c == 'R';
        case 1: return c == 'P';
        case 2: return c == 'S';
        default: __builtin_unreachable();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int N = 1; while(N < s.size() + t.size()) N <<= 1;
    auto arr = new int[N]();
    for(int i = 0; i < 3; i++) {
        vector<cd> a(N), b(t.size());
        for(int j = 0; j < s.size(); j++) a[j] = RPS(s[j], i);
        for(int j = 0; j < t.size(); j++) b[t.size() - j - 1] = YMC(t[j], i);
        b.resize(N);
        fft<false>(a); fft<false>(b);
        for(int j = 0; j < N; j++) a[j] *= b[j];
        fft<true>(a);
        for(int j = 0; j < N; j++) arr[j] += (int)round(a[j].real());
    }
    int max = 0;
    for(int i = t.size() - 1; i < s.size() + t.size(); i++) {
        if(max < arr[i]) max = arr[i];
    } cout << max;
    delete[] arr;
}