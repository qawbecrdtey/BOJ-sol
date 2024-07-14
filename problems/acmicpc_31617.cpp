#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int k, n, m, r = 0; cin >> k >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int j = 0; j < m; j++) {
        int x; cin >> x;
        for(int i = 0; i < n; i++) {
            r += (x - a[i] == k);
        }
    } cout << r;
}