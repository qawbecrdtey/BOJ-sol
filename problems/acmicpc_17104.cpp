#pragma GCC optimize("Ofast")
#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;
using cld = complex<double>;
using ll = unsigned long long;
inline vector<ll> get_primes() {
    vector<ll> primes { 2, 3 };
    vector<bool> visited(999984);
    ll d = 4;
    ll i;
    for(i = 5; i * i < 999984; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(ll j = i; j < 999984; j += (i << 1)) {
                visited[j] = true;
            }
        }
    }
    for(; i < 999984; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
constexpr ll N = 1 << 21;
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto primes = get_primes();
    vector<cld> a(N);
    for(auto p : primes) a[p] = 1;
    fft<false>(a);
    for(auto &now : a) now *= now;
    fft<true>(a);
    int t; cin >> t; while(t--) {
        int x; cin >> x;
        cout << (((ll)round(a[x].real()) + 1) >> 1) << '\n';
    }
}