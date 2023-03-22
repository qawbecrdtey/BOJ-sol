#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0x7fffffff;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if((a[i] - a[j]) % (i - j)) continue;
            ll const d = (a[i] - a[j]) / (i - j);
            ll const x = a[i] - i * d;
            int cnt = 0;
            for(int k = 0; k < n; k++) {
                cnt += (a[k] != x + k * d);
            } res = min(res, cnt);
        }
    } cout << res;
}