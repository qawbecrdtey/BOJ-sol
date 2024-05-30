#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, d; cin >> n >> d;
    auto a = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    ll l = 0, r = 0;
    ll sum = 0;
    ll res = 0;
    while(l < n) {
        if(l >= r) {
            sum += a[r++].second;
            if(res < sum) res = sum;
            continue;
        }
        if(r < n && a[r].first - a[l].first < d) {
            sum += a[r++].second;
            if(res < sum) res = sum;
            continue;
        }
        sum -= a[l++].second;
    }
    cout << res;
}
