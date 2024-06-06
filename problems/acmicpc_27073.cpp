#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n + 1]; a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int res = 99999999;
    int l = 9999999, r = 9999999;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(res > abs(a[j] - a[i]) || (res == abs(a[j] - a[i]) && r - l < j - i)) {
                l = i + 1, r = j, res = abs(a[j] - a[i]);
            }
        }
    }
    cout << l << ' ' << r << ' ' << res;
}
