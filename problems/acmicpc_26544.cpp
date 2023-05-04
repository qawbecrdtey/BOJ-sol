#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new int[n + 2];
        int l = 0;
        for(int i = 0; i < n; i++) { int x; cin >> x; l += (x << 1); }
        for(int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n + 1] = 0;
        for(int i = 0; i <= n; i++) {
            l += abs(a[i] - a[i + 1]);
        } cout << l << '\n';
        delete[] a;
    }
}