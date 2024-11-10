#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a, b, c; cin >> a >> b >> c;
        int res = 0;
        for(int i = 0; i < a; i++) {
            res += b;
            b += c;
        }
        cout << res << '\n';
    }
}
