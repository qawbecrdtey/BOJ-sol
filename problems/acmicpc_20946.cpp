#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_primes(ll n) {
    vector<ll> primes{ 2, 3 };
    vector<bool> visited(n + 1);
    ll i = 5, d = 4;
    for(; i * i <= n; i += (d = 6 - d)) {
        if(visited[i]) continue;
        visited[i] = true;
        primes.push_back(i);
        for(ll j = i; j <= i; j += (i << 1)) visited[j] = true;
    }
    for(; i <= n; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
template<typename Iterator>
void print(Iterator begin, Iterator end) {
    switch(end - begin) {
        case 1: cout << -1; break;
        case 2: cout << (*begin) * (*(begin + 1)); break;
        case 3: cout << (*begin) * (*(begin + 1)) * (*(begin + 2)); break;
        default: cout << (*begin) * (*(begin + 1)) << ' '; print(begin + 2, end); break;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    auto const primes = get_primes(1000000);
    vector<ll> factor;
    for(ll p : primes) {
        if(p * p > n) break;
        while(n % p == 0) {
            n /= p;
            factor.push_back(p);
        }
    } if(n != 1) factor.push_back(n);
    print(factor.begin(), factor.end());
}