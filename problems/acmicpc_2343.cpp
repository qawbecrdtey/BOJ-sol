#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = n * 10000 + 1;
LP: while(l < r) {
        auto const mid = (l + r) / 2;
        int cnt = 1;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > mid) {
                l = mid + 1;
                goto LP;
            }
            if(sum + a[i] > mid) {
                sum = a[i];
                cnt++;
                continue;
            }
            sum += a[i];
        }
        if(cnt <= m) {
            r = mid;
            continue;
        }
        l = mid + 1;
    }
    cout << r;
}