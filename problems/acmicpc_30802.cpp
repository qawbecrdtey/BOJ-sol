#include <iostream>
using namespace std;
static int f(int n, int p) { return (n + p - 1) / p; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a[6], t, p; cin >> n >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> t >> p;
    cout << f(a[0], t) + f(a[1], t) + f(a[2], t) + f(a[3], t) + f(a[4], t) + f(a[5], t) << '\n' << n / p << ' ' << n % p;
}
