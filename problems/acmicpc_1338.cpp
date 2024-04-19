#include <iostream>
using namespace std;
using ll = long long;
static constexpr char no_str[] = "Unknwon Number";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, x, y; cin >> a >> b >> x >> y;
    if(!x) { cout << no_str; return 0; }
    if(x < 0) x = -x;
    if(y >= x || y < 0) { cout << no_str; return 0; }
    if(a > b) swap(a, b);
    bool const fa = ((a % x + x) % x == y);
    bool const fb = ((b % x + x) % x == y);
    if(fa && fb) {
        if(a == b) cout << a;
        else cout << no_str;
    }
    else if(fa) {
        if((b - a) / x == 0) cout << a;
        else cout << no_str;
    }
    else if(fb) {
        if((b - a) / x == 0) cout << b;
        else cout << no_str;
    }
    else {
        auto val = a / x * x + y;
        while(val - x >= a) val -= x;
        while(val < a) val += x;
        if(val > b || val + x <= b) cout << no_str;
        else cout << val;
    }
}