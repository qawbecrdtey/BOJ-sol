#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll g = gcd(a, b); a /= g; b /= g;
        g = gcd(c, d); c /= g; d /= g;
        ll num = a * d - b * c, den = b * d;
        g = gcd(num, den); num /= g; den /= g;
        if(den < 0) den = -den, num = -num;
        if(num == -1 || num == 1) {
            cout << "1/" << den << '\n';
        } else cout << "NOT NEIGHBORS\n";
    }
}