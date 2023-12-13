#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
inline vector<ll> get_divisors(ll n) {
    vector<ll> result;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i) continue;
        result.push_back(i);
        if(i * i != n) result.push_back(n / i);
    }
    sort(result.begin(), result.end());
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b; cin >> a >> b;
    if(a == b) { cout << 1; return 0; }
    auto const divisors = get_divisors(abs(b - a));
    ll min_lcm = numeric_limits<ll>::max();
    ll min_n = abs(b - a);
    for(auto const div : divisors) {
        ll const n = ((div - (a % div)) - 1) % div + 1;
        if(auto const l = lcm(a + n, b + n); l < min_lcm || (l == min_lcm && n < min_n)) {
            min_lcm = l;
            min_n = n;
        }
    }
    cout << min_n;
}