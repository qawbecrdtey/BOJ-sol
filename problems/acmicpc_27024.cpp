#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    auto const m = (n >> 1) + 1;
    int res = numeric_limits<int>::max();
    for(int i = 0; i + m <= n; i++) {
        if(res > a[i + m - 1] - a[i]) {
            res = a[i + m - 1] - a[i];
        }
    }
    cout << res;
}