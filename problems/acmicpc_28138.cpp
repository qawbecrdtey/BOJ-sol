#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline vector<ll> factors(ll n) {
    vector<ll> v;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i * i != n) v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, r; cin >> n >> r;
    auto const v = factors(n - r);
    ll sum = 0;
    for(auto it = upper_bound(v.begin(), v.end(), r); it != v.end(); it++) {
        sum += *it;
    } cout << sum;
}