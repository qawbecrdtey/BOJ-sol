#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int t = 1;; t++) {
        int l; cin >> l;
        if(!l) return 0;
        cout << "User " << t << '\n';
        int n; cin >> n;
        while(n--) {
            ll x; cin >> x;
            cout.precision(5);
            cout << fixed << static_cast<long double>(x * l) / 100000 << '\n';
        }
    }
}
