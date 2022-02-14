#pragma GCC optimize "Ofast"
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    if(n == 2) {
        cout << '0';
        return 0;
    }
    auto a = new ll[n + 1]; a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] += a[i - 1];
    }
    ll res = 4200000001;
    int u = -1;
    for(int i = 0; i < n - 2; i++) {
        if(res > (a[i + 2] - a[i]) * 3) {
            u = i; res = (a[i + 2] - a[i]) * 3;
        }
        if(res > (a[i + 3] - a[i]) * 2) {
            u = i; res = (a[i + 3] - a[i]) * 2;
        }
    }
    if(res > (a[n] - a[n - 2]) * 3) u = n - 2;
    cout << u;
}