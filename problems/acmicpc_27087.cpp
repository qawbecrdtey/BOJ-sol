#include <iostream>
using namespace std;
static bool f(int const a, int const p) noexcept { return a % p == 0; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a, b, c, p; cin >> a >> b >> c >> p;
        cout << (f(a, p) + f(b, p) + f(c, p) >= 2) << '\n';
    }
}
