#include <iostream>
#include <map>
#include <string>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if(!n) return 0;
    map<ll, ll> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        string s;
        cin >> x >> s >> y;
        if (s[0] == 'L') m[x] = x - y;
        else m[x] = x + y;
    }
    ll x; cin >> x;
    while(m.find(x) != m.end()) x = m[x];
    cout << x;
}