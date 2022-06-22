#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, s; cin >> n >> s;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i] - s);
    }
    ll g = a[0];
    for(int i = 1; i < n; i++) g = gcd(g, a[i]);
    cout << g;
}