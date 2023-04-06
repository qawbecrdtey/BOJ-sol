#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    auto a = new int[n + 1]; auto b = new string[n + 1];
    for(int i = 0; i < n; i++) cin >> b[i] >> a[i]; a[n] = 1000000007; b[n] = b[n - 1];
    while(q--) {
        int x; cin >> x; cout << b[lower_bound(a, a + n + 1, x) - a] << '\n';
    }
}