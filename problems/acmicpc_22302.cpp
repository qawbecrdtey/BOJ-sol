#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_primes(ll n) {
    vector<ll> primes{2, 3};
    vector<bool> visited(n + 1);
    ll i = 5, d = 4;
    for(; i * i <= n; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(ll j = i; j <= n; j += (i << 1)) visited[j] = true;
    }
    for(; i <= n; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto const m = *max_element(a, a + n);
    auto const primes = get_primes(m);
    for(int i = 0; i < n; i++) {
        ll cnt = 0;
        for(ll const p : primes) {
            if(p > a[i]) break;
            ll mul = p;
            while(a[i] >= mul) {
                cnt += a[i] / mul;
                mul *= p;
            }
        }
        cout << (upper_bound(primes.begin(), primes.end(), a[i]) - primes.begin()) << ' ' << cnt << '\n';
    }
}