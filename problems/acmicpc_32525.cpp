#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n; for(int i = 1; i <= n; i++) {
            int x, y; cin >> x >> y;
            cout << i << ' ' << x + 200000001 << ' ' << y + 1 << '\n';
        }
    }
}
