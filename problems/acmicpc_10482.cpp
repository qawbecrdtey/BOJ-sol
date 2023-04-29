#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_primes() {
    vector<ll> primes{2, 3};
    vector<bool> visited(32001);
    ll i = 5, d = 4;
    for(; i * i <= 32000; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(ll j = i; j <= 32000; j += (i << 1)) visited[j] = true;
    }
    for(; i <= 32000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    int t; cin >> t; while(t--) {
        ll n; cin >> n; cout << n << " has ";
        vector<pair<ll, ll>> v;
        for(ll p : primes) {
            if((p << 1) > n) break;
            if(auto it = lower_bound(primes.begin(), primes.end(), n - p); it != primes.end() && *it == n - p) {
                v.emplace_back(p, n - p);
            }
        }
        cout << v.size() << " representation(s)\n";
        for(auto [x, y] : v) {
            cout << x << '+' << y << '\n';
        } cout << '\n';
    }

}