#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    ll res = 0;
    while(n >= 5) {
        res += n / 5;
        n /= 5;
    }
    cout << res;
}
