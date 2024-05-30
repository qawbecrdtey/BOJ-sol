#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
vector<ll> get_primes() {
    vector<ll> primes{2, 3};
    vector<bool> visited(10000001);
    ll i = 5, d = 4;
    for(; i * i <= 10000000; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(ll j = i; j <= 10000000; j += (i << 1)) visited[i] = true;
    }
    for(; i <= 10000000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
ll power(ll const n, ll const p) {
    if(!p) return 1;
    if(p == 1) return n % M;
    ll const r = power(n, p >> 1);
    return (((r * r) % M) * power(n, p & 1)) % M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    auto const primes = get_primes();
    unordered_map<int, int> a;
    while(n--) {
        ll x, y; cin >> x >> y; x = y - x;
        for(ll const p : primes) {
            if(p * p > x) break;
            while(x % p == 0) {
                a[p]++;
                x /= p;
            }
        }
        if(x != 1) a[x]++;
        for(ll const p : primes) {
            if(p * p > y) break;
            while(y % p == 0) {
                a[p]--;
                y /= p;
            }
        }
        if(y != 1) a[y]--;
    }
    ll mul = 1, div = 1;
    for(ll i = 2; i < 10000000; i++) {
        if(a[i] > 0) mul = (mul * power(i, a[i])) % M;
        else if(a[i] < 0) div = (div * power(i, -a[i])) % M;
    }
    cout << mul << ' ' << div;
}
