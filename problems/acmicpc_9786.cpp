#include <iostream>
#include <numeric>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        long long a, b; cin >> a >> b;
        auto g = gcd(a, b);
        cout << a / g << ' ' << b / g << '\n';
    }
}