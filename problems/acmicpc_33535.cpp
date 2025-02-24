#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[m + 1]();
    int res = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        for(int j = m; j >= x; j--) {
            a[j] = max(a[j], a[j - x] + y);
            res = max(a[j], res);
        }
    }
    cout << res;
}
