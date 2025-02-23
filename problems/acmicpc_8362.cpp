#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    auto b = new int[m];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
    int i = 0, j = 0;
    int res = 200000000;
    while(i < n || j < m) {
        if(i == n) {
            res = min(res, abs(a[i] - b[j]));
            j++;
            continue;
        }
        if(j == m) {
            res = min(res, abs(a[i] - b[j]));
            i++;
            continue;
        }
        res = min(res, abs(a[i] - b[j]));
        if(a[i] < b[j]) i++;
        else j++;
    }
    cout << res;
}
