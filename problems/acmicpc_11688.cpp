#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_divisors(ll n) {
    vector<ll> divisors;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i) continue;
        divisors.push_back(i);
        if(i * i != n) {
            divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, L; cin >> a >> b >> L;
    ll l = lcm(a, b);
    if(L % l) { cout << -1; return 0; }
    auto const divisors = get_divisors(L);
    for(auto const now : divisors) {
        if(lcm(l, now) == L) {
            cout << now;
            return 0;
        }
    }
}
