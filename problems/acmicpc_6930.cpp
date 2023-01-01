#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x, m; cin >> x >> m;
    for(ll i = 1; i < m; i++) {
        if((x * i) % m == 1) {
            cout << i;
            return 0;
        }
    } cout << "No such integer exists.";
    return 0;
}