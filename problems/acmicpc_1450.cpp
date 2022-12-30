#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> comb(vector<ll> const &v, ll c) {
    vector<ll> res;
    for(ll i = 0; i < (1 << v.size()); i++) {
        ll sum = 0;
        for(int j = 0; j < v.size(); j++) {
            sum += ((i >> j) & 1) * v[j];
        } if(sum <= c) res.push_back(sum);
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, c; cin >> n >> c;
    vector<ll> lv, rv;
    for(ll i = 0; i < n / 2; i++) {
        ll x; cin >> x; lv.push_back(x);
    } for(ll i = n / 2; i < n; i++) {
        ll x; cin >> x; rv.push_back(x);
    } auto lrv = comb(lv, c), rrv = comb(rv, c);
    sort(lrv.begin(), lrv.end()); sort(rrv.begin(), rrv.end());
    ll res = 0;
    for(ll now : lrv) {
        auto val = upper_bound(rrv.begin(), rrv.end(), c - now) - rrv.begin();
        res += val;
    } cout << res;
}