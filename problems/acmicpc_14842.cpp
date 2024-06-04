#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll w, h, n;
    cin >> w >> h >> n;
    cout.precision(18);
    cout << fixed << 2 * h * (n - 1 - n / 2) / static_cast<long double>(n) * static_cast<long double>(n / 2);
}
