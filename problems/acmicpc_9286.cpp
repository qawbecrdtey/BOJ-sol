#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ":\n";
        int n; cin >> n; while(n--) {
            int x; cin >> x; if(x > 5) continue; cout << x + 1 << '\n';
        }
    }
}