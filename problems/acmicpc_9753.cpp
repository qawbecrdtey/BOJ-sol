#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = 100001;
vector<ll> get_primes() {
    vector<ll> primes{ 2, 3 };
    vector<bool> visited(M);
    ll i = 5, d = 4;
    for(; i * i <= M; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(ll j = i; j <= M; j += (i << 1)) visited[j] = true;
        }
    }
    for(; i <= M; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto primes = get_primes();
    vector<ll> muls;
    for(ll p : primes) {
        for(ll q : primes) {
            if(p == q) break;
            if(p * q > M) break;
            muls.push_back(p * q);
        }
    } sort(muls.begin(), muls.end());
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        cout << *lower_bound(muls.begin(), muls.end(), n) << '\n';
    }
}