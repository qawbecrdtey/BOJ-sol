#include <iostream>
#include <string>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    ll xhi = M, xlo = -M;
    ll yhi = M, ylo = -M;
    while(n--) {
        ll a, b; string s; cin >> a >> b >> s;
        switch(s[0]) {
            case 'L': xhi = min(xhi, a - 1); break;
            case 'R': xlo = max(xlo, a + 1); break;
            case 'U': ylo = max(ylo, b + 1); break;
            case 'D': yhi = min(yhi, b - 1); break;
            default: __builtin_unreachable();
        }
    }
    if(xhi < xlo || yhi < ylo) cout << 0;
    else if(xhi == M || yhi == M || xlo == -M || ylo == -M) cout << "Infinity";
    else cout << (xhi - xlo + 1) * (yhi - ylo + 1);
}