#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    if(n < 4) {
        cout << 1;
        return 0;
    }
    ll a[2] {1, 0};
    for(int i = 3; i <= n; i++) {
        ll b[2];
        b[0] = (a[0] + a[1]) % M;
        b[1] = a[0];
        a[0] = b[0];
        a[1] = b[1];
    }
    cout << (a[0] + a[1]) % M;
}