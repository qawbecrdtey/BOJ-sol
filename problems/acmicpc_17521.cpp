#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, w; cin >> n >> w;
    auto a = new int[n + 2];
    a[0] = 51; a[n + 1] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll coin = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] < a[i - 1] && a[i] <= a[i + 1]) {
            coin += w / a[i];
            w %= a[i];
        }
        if(a[i] >= a[i - 1] && a[i] > a[i + 1]) {
            w += a[i] * coin;
            coin = 0;
        }
    } cout << w;
}