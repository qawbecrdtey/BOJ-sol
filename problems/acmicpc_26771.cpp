#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> convert(ll x) {
    if(x < 5) return {x};
    auto v = convert(x / 5);
    v.push_back(x % 5);
    return v;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x; cin >> x;
    auto const v = convert(x);
    for(ll val : v) {
        cout << val * 2;
    }
}
