#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto a = new int[n + 1]; a[0] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] = 2 - a[i]; cnt += a[i]; a[i] += a[i - 1];
    }
    if(cnt < k) { cout << -1; return 0; }
    int l = k, r = n, res = n;
    while(l < r) {
        int const m = (l + r) >> 1;
        bool flag = false;
        for(int i = 0; i + m <= n; i++) {
            if(a[i + m] - a[i] >= k) {
                flag = true;
                break;
            }
        }
        if(flag) {
            res = m;
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    cout << res;
}
