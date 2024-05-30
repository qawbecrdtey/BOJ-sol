#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    ll res = 0;
    while(n--) {
        ll a, b, c; cin >> a >> b >> c;
        if(a >= b) continue;
        res += (b - a) * c;
    } cout << res;
}
