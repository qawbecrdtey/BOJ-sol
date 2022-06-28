#include <cstdio>
#include <vector>
using ll = long long;
constexpr ll M = 1000000007;
std::vector<ll> get_primes(ll n) {
    std::vector<ll> primes{ 2, 3 };
    std::vector<bool> visited(n + 1);
    ll i = 5, d = 4;
    for(; i * i <= n; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(ll j = i; j <= n; j += (i << 1)) visited[j] = true;
        }
    }
    for(; i <= n; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ll n; scanf("%lld", &n);
    auto primes = get_primes(n);
    auto phi = new ll[n + 1];
    for(ll i = 1; i <= n; i++) phi[i] = i;
    for(ll p : primes) {
        for(ll i = p; i <= n; i += p) {
            phi[i] = phi[i] / p * (p - 1);
        }
    }
    auto sum = new ll[n + 1]; sum[1] = 0;
    for(ll i = 2; i <= n; i++) {
        sum[i] = (sum[i - 1] + ((i * i) % M * phi[i]) % M) % M;
    }
    ll res = 0;
    for(ll g = 1; g <= (n >> 1); g++) {
        res = (res + g * sum[n / g]) % M;
    } if(res & 1) res = ((res + M) >> 1); else res >>= 1;
    printf("%lld", res);
}