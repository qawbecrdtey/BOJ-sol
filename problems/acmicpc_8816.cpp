#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n; n >>= 1;
        int res = 1;
        for(int i = 0; i < n; i++) {
            res = (res * (2 * i + 1)) % 1000;
        } cout << res << '\n';
    }
}