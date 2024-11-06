#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto a = new ll[n];
    ll l = 0, s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        if(l < a[i]) l = a[i];
    }
    ll r = s + 1;
    ll res = r;
    while(l < r) {
        ll const m = (l + r) >> 1;
        ll sum = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(sum + a[i] > m) {
                sum = a[i];
                cnt++;
            }
            else sum += a[i];
        }
        if(sum) cnt++;
        if(cnt > k) l = m + 1;
        else {
            res = m;
            r = m;
        }
    }
    cout << res;
}
