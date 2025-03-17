#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x1, x2, a, b, c, d, e; cin >> x1 >> x2 >> a >> b >> c >> d >> e;
    a /= 3; b /= 2; d /= 2; b -= d; c -= e;
    auto const f = [a, b, c](ll const x) {
        return a * x * x * x + b * x * x + c * x;
    };
    cout << f(x2) - f(x1);
}
