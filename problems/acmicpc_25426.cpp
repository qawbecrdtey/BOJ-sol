#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, s{}; cin >> n;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) {
        int x; cin >> a[i] >> x;
        s += x;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) s += a[i] * (i + 1);
    cout << s;
}