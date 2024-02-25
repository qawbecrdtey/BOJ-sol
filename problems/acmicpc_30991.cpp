#include <array>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const a = new array<ll, 3>[n + 1];
    a[0][0] = 1; a[0][1] = 0; a[0][2] = 0;
    for(int i = 1; i <= n; i++) {
        a[i][0] = a[i - 1][0] - 2 * a[i - 1][1] + 2 * a[i - 1][2];
        a[i][1] = a[i - 1][0] + a[i - 1][1];
        a[i][2] = -a[i - 1][0] + a[i - 1][2];
    }
    cout << a[n][0] + a[n][1] + a[n][2];
    delete[] a;
}