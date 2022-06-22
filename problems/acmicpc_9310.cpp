#include <iostream>
using namespace std;
using ll = long long;
inline ll power(ll a, ll n) {
    ll x = 1;
    for(int i = 0; i < n; i++) {
        x *= a;
    } return x;
}
int main() {
    while(true) {
        int n;
        cin >> n;
        if (!n) return 0;
        ll a[3];
        for (long long &i: a) cin >> i;
        switch (n) {
            case 1:
                cout << a[0] << '\n';
                break;
            case 2:
                cout << a[0] + a[1] << '\n';
                break;
            case 3:
                cout << a[0] + a[1] + a[2] << '\n';
                break;
            default: {
                if (a[1] - a[0] == a[2] - a[1]) {
                    cout << a[0] * n + n * (n - 1) / 2 * (a[1] - a[0]) << '\n';
                } else {
                    cout << a[0] * (power(a[1] / a[0], n) - 1) / (a[1] / a[0] - 1) << '\n';
                }
                break;
            }
        }
    }
}