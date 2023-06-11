#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto piv = min_element(a, a + n);
    rotate(a, piv, a + n);
    int res = 1;
    for(int i = 1; i < n; i++) {
        res += (a[i] <= a[i - 1]);
    } cout << res;
}