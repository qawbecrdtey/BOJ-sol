#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, b; cin >> n >> b;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll sum = 0;

    for(int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if(sum >= b) {
            cout << n - i;
            return 0;
        }
    }
}