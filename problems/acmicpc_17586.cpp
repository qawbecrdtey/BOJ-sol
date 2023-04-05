#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
inline ll cut(ll a, ll b) {
    return ((a & 1) && (b & 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b; cin >> a >> b;
    ll const g = gcd(a, b);
    cout << cut(a / g, b / g) * g;
}