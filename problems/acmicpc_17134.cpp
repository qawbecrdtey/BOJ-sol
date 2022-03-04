#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;
using cd = complex<double>;
inline vector<int> get_primes(int n) {
    vector<int> primes = { 2, 3 };
    vector<bool> visited(n + 1);
    int d = 4, i = 5;
    for(; i * i <= n; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int j = i * 3; j <= n; j += (i << 1)) {
                visited[j] = true;
            }
        }
    }
    for(; i <= n; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
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
    int t, max = 0; cin >> t;
    auto arr = new int[t];
    for(int i = 0; i < t; i++) {
        cin >> arr[i];
        if(max < arr[i]) max = arr[i];
    }
    auto primes = get_primes(max);
    int N = 16; while(N < (max * 3)) N <<= 1;
    vector<cd> a(N), b(N);
    for(auto p : primes) {
        a[p] = 1; b[p << 1] = 1;
    }
    fft<false>(a); fft<false>(b);
    for(int i = 0; i < N; i++) a[i] *= b[i];
    fft<true>(a);
    for(int i = 0; i < t; i++) {
        cout << (int)(round(a[arr[i]].real())) << '\n';
    }
}