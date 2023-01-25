#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, t, m, x, y; cin >> n >> t >> m >> x >> y;
    ll num = m * y + (n - m) * x;
    ll den = x * y;
    ll const g = gcd(num, den);
    num /= g; den /= g;
    ll const res = (num + (den * 60 - 1)) / (den * 60);
    if(res > t) cout << res - t;
    else cout << 0;
}