#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    ll *a[3];
    a[0] = new ll[n + 2];
    a[1] = new ll[n + 2];
    a[2] = new ll[n + 2];
    a[0][0] = 1, a[0][1] = 0, a[0][2] = 0;
    for(int i = 1; i <= n; i++) {
        a[0][i] = (a[1][i - 1] + a[2][i - 1]) % M;
        a[1][i] = (a[2][i - 1] + a[0][i - 1]) % M;
        a[2][i] = (a[0][i - 1] + a[1][i - 1]) % M;
    }
    if(a[0][n] & 1) a[0][n] = (a[0][n] + M) / 2;
    else a[0][n] /= 2;
    cout << a[0][n];
}