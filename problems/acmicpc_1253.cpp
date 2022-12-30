#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            auto lo = lower_bound(a, a + n, a[i] - a[j]) - a;
            auto hi = upper_bound(a, a + n, a[i] - a[j]) - a;
            if(lo == hi || (lo + 1 == hi && (lo == i || lo == j)) || (lo + 2 == hi && ((lo == i && lo + 1 == j) || (lo == j && lo + 1 == i)))) continue;
            res++; break;
        }
    } cout << res;
}