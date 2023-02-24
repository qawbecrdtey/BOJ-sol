#include <iostream>
using namespace std;
using ll = unsigned long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m; cin >> n >> m;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll res = 0;
    for(int i = 0; i < (1 << n); i++) {
        bool plus = true;
        ll val = 1;
        for(int j = 0; j < n && val <= m; j++) {
            if(i & (1 << j)) {
                plus = !plus;
                val *= a[j];
            }
        } if(val > m) continue;
        if(plus) res += m / val;
        else res -= m / val;
    } cout << m - res;
}