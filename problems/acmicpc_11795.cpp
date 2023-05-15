#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a{}, b{}, c{};
    int t; cin >> t; while(t--) {
        int x, y, z; cin >> x >> y >> z;
        a += x; b += y; c += z;
        if(min({a, b, c}) < 30) {
            cout << "NO\n";
            continue;
        }
        int m = min({a, b, c});
        cout << m << '\n';
        a -= m; b -= m; c -= m;
    }
}