#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, w, d, W; while(cin >> n >> w >> d >> W) {
        ll ww = w * (n * (n - 1) / 2);
        if(ww == W) cout << n << '\n';
        else cout << (ww - W) / d << '\n';
    }
}