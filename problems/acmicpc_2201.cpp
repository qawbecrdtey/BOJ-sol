#include <iostream>
#include <string>
using namespace std;
using ll = long long;
void str(ll n, ll len, ll a, ll b, string &res) {
    if(!len) return;
    res += '1';
    len--;
    n -= b;
    a -= b;
    swap(a, b);
    while(len && n < b) {
        res += '0';
        len--;
        a -= b;
        swap(a, b);
    }
    str(n, len, a, b, res);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    if(n == 1) { cout << 1; return 0; }
    ll len = 1;
    ll a = 2, b = 1;
    while(a <= n) {
        b += a;
        swap(a, b);
        len++;
    }
    string res;
    str(n, len, a, b, res);
    cout << res << flush;
}