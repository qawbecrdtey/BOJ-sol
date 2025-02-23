#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, x; cin >> n >> x;
    auto a = new ll[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = new ll[n];
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
        if(i) b[i] += b[i - 1];
        if(b[i] < a[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << (b[n - 1] - a[n - 1]) / x;
}
