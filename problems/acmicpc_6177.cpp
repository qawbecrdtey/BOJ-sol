#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new long double[n];
    long double sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; sum += a[i];
    } sort(a, a + n);
    cout.precision(12);
    cout << fixed << sum / n << '\n';
    if(n & 1) cout << fixed << a[n / 2];
    else cout << fixed << (a[n / 2 - 1] + a[n / 2]) / 2;
}