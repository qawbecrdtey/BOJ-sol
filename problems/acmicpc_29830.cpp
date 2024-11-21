#include <iostream>
#include <string>
using namespace std;
using ll = long long;
ll movement(string s) {
    if(s[0] == '0') return 0;
    ll const v = stoi(s.substr(1));
    if(s[0] == '-') return -v;
    return v;
}
char get_c(ll x, ll y) {
    if(x == y) return 'M';
    if(x > y) return 'T';
    return 'V';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new ll[n + 1];
    for(int i = 0; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) a[i] -= a[0]; a[0] = 0;
    ll cur = 0;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        cur += movement(s);
        cout << get_c(a[i], cur);
    }
}
