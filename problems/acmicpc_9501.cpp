#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, d; cin >> n >> d;
        int res = 0;
        while(n--) {
            long double a, b, c, x; cin >> a >> b >> c; x = a * b / c;
            res += (x >= d);
        } cout << res << '\n';
    }
}