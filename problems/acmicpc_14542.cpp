#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int tt = 1; ; tt++) {
        int n; cin >> n; if(!n) return 0;
        cout << "Case #" << tt << ":";
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                int x; cin >> x; if(!j || j == i || i == n - 1) res += x;
            }
        } cout << res << '\n';
    }
}