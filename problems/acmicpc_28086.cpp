#include <iostream>
#include <string>
using namespace std;
using ll = long long;
inline ll to_ll(string const &s) {
    int idx = 0; bool neg = false;
    ll val = 0;
    if(s[0] == '+') idx = 1;
    else if(s[0] == '-') idx = 1, neg = true;
    while(idx < s.size()) {
        val = (val << 3) | (s[idx++] - '0');
    }
    if(neg) val = -val;
    return val;
}
inline ll add_(ll a, ll b) { return a + b; }
inline ll sub_(ll a, ll b) { return a - b; }
inline ll mul_(ll a, ll b) { return a * b; }
inline ll div_(ll a, ll b) {
    if(b == 0) {
        cout << "invalid";
        exit(0);
    }
    bool neg = false;
    if(a < 0) neg = true, a = -a;
    if(b < 0) neg = !neg, b = -b;
    ll res = a / b;
    if(neg && a % b) res = -res - 1;
    else if(neg) res = -res;
    return res;
}
inline void print(ll n) {
    if(n < 0) cout << '-', n = -n;
    cout << oct << n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*') {
            print(mul_(to_ll(s.substr(0, i)), to_ll(s.substr(i + 1))));
            return 0;
        }
        else if(s[i] == '/') {
            print(div_(to_ll(s.substr(0, i)), to_ll(s.substr(i + 1))));
            return 0;
        }
    }
    for(int i = 0; i < s.size(); i++) {
        if(!i && (s[i] == '-' || s[i] == '+')) continue;
        if(s[i] == '+') {
            print(add_(to_ll(s.substr(0, i)), to_ll(s.substr(i + 1))));
            return 0;
        }
        else if(s[i] == '-') {
            print(sub_(to_ll(s.substr(0, i)), to_ll(s.substr(i + 1))));
            return 0;
        }
    }
    cout << "invalid";
}