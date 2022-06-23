#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(2); cout << fixed;
    for(int tt = 1; ; tt++) {
        int n; cin >> n;
        if(n < 0) return 0;
        cout << "Case " << tt << ": ";
        long long mx = 0, my = 0, m = 0;
        for(int i = 0; i < n; i++) {
            long long x, y, z; cin >> x >> y >> z;
            mx += z * x, my += z * y, m += z;
        }
        cout << (long double)(mx) / m << ' ' << (long double)(my) / m << '\n';
    }
}