#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a, b; cin >> a >> b;
        cout << a << ' ' << b << '\n';
        cout << b * a - 2 * (a - 1) << '\n';
    }
}