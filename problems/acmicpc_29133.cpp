#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, c, d; cin >> a >> b >> c >> d;
    int res = 0;
    if(a + b + c == d) { res = 1; }
    if(a * a + b * b + c * c == d) {
        if(res == 0) { res = 2; }
        else res = -1;
    }
    if(a * a * a + b * b * b + c * c * c == d) {
        if(res == 0) { res = 3; }
        else res = -1;
    }
    if(res == 0) res = -1;
    cout << res;
}
