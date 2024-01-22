#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[m];
    for(int i = 0; i < m; i++) cin >> a[i];
    int l = 0, r = n + 1;
    int res;
    while(l < r) {
        auto const h = (l + r) >> 1;
        bool pass = true;
        int cur = 0;
        for(int i = 0; i < m; i++) {
            if(cur >= n) break;
            else if(a[i] - h <= cur && a[i] + h >= cur) cur = a[i] + h;
            else {
                pass = false;
                break;
            }
        }
        if(cur < n) pass = false;
        if(pass) res = h, r = h;
        else l = h + 1;
    }
    cout << res;
}