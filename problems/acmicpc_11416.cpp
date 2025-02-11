#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll apply(vector<ll> poly, ll x) {
    if(poly.empty()) return 0;
    ll const c = poly.back();
    poly.pop_back();
    return c + apply(std::move(poly), x) * x;
}
void div(vector<ll> &poly, ll x) {
    vector<ll> new_poly(static_cast<int>(poly.size()) - 1);
    reverse(poly.begin(), poly.end());
    for(int i = static_cast<int>(new_poly.size()) - 1; i >= 0; i--) {
        ll const mul = poly[i + 1];
        poly[i] += mul * x;
        poly[i + 1] = 0;
        new_poly[i] = mul;
    }
    reverse(new_poly.begin(), new_poly.end());
    poly = std::move(new_poly);
}
bool find_root(vector<ll> &poly) {
    for(ll i = -10; i <= 10; i++) {
        if(apply(poly, i) == 0) {
            div(poly, i);
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<ll> v; v.reserve(n + 1);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x; v.push_back(x);
    }
    reverse(v.begin(), v.end());
    v.push_back(1);
    reverse(v.begin(), v.end());
    while(find_root(v)) {
        n--;
    }
    cout << n;
}
