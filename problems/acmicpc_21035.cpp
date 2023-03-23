#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int q; cin >> q; while(q--) {
        string s; cin >> s;
        int x, y; cin >> x >> y;
        if(s == "row") for(int i = 0; i < m; i++) a[x - 1][i] += y;
        else for(int i = 0; i < n; i++) a[i][x - 1] += y;
    }
    int sum = 0, mn = 0x7fffffff, mx = -0x7fffffff;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += a[i][j];
            mn = min(mn, a[i][j]);
            mx = max(mx, a[i][j]);
        }
    } cout << sum << ' ' << mn << ' ' << mx;
}