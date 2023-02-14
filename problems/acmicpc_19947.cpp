#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll h, n; cin >> h >> n;
    auto a = new ll[n + 1](); a[0] = h;
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] * 21 / 20;
        if(i >= 3) a[i] = max(a[i], a[i - 3] * 6 / 5);
        if(i >= 5) a[i] = max(a[i], a[i - 5] * 27 / 20);
    } cout << a[n];
}