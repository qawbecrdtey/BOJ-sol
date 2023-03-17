#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, c, d; cin >> a >> b >> c >> d;
    cout << (c + d) / (a - b);
}