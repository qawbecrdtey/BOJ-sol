#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
static constexpr ll M = 104729;
vector<ll> get_primes() {
    vector<ll> primes{2, 3};
    vector<bool> visited(M + 1);
    ll i = 5, d = 4;
    for(; i * i <= M; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(ll j = i; j <= M; j += (i << 1)) visited[j] = true;    }
    for(; i <= M; i += (d = 6 - d)) if(!visited[i]) primes.push_back(i);
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    int n; cin >> n; cout << primes[n - 1];
}