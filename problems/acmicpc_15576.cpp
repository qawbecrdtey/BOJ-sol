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
    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int N = 1; while(N < (s.size() + t.size())) N <<= 1;
    vector<cd> a(N), b(N);
    for(int i = 0; i < s.size(); i++) a[i] = s[i] - '0';
    for(int i = 0; i < t.size(); i++) b[i] = t[i] - '0';
    fft<false>(a); fft<false>(b);
    for(int i = 0; i < N; i++) a[i] *= b[i];
    fft<true>(a);
    while(!a.empty() && !(int)(round(a.back().real()))) a.pop_back();
    if(a.empty()) {
        cout << 0;
        return 0;
    }
    string res; int c = 0;
    for(auto now : a) {
        int const x = (int)(round(now.real())) + c;
        res.push_back('0' + x % 10);
        c = x / 10;
    }
    while(c) {
        res.push_back('0' + c % 10);
        c /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}