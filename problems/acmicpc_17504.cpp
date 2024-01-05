#include <iostream>
#include <numeric>
#include <stack>
using namespace std;
using ll = long long;
inline pair<ll, ll> add(pair<ll, ll> v1, pair<ll, ll> v2) {
    ll const n = v1.first * v2.second + v1.second * v2.first;
    ll const d = v1.second * v2.second;
    ll const g = gcd(n, d);
    return { n / g, d / g };
}
inline pair<ll, ll> rev(pair<ll, ll> v) { return { v.second, v.first }; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    stack<pair<ll, ll>> s;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.emplace(x, 1);
    }
    while(s.size() != 1) {
        auto const v2 = s.top(); s.pop();
        auto const v1 = s.top(); s.pop();
        s.push(add(v1, rev(v2)));
    }
    cout << s.top().first - s.top().second << ' ' << s.top().first;
}