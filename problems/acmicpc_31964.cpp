#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n; auto a = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    ll res = max(a[n - 1].first, a[n - 1].second);
    for(int i = n - 2; i >= 0; i--) {
        res = max(a[i].second, res + a[i + 1].first - a[i].first);
    }
    cout << res + a[0].first;
}
