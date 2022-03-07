#include <iostream>
#include <string>
using namespace std;
using ll = unsigned long long;
inline bool is_palindrome(string const &s, ll start, ll end) {
    for(ll i = start; i <= (start + end) / 2; i++) {
        if(s[i] != s[start + end - i - 1]) return false;
    }
    return true;
}
ll f(string const &s, ll *dp, ll n) {
    if(dp[n] != -1) return dp[n];
    ll res = n;
    for(int i = 0; i < n; i++) {
        if(is_palindrome(s, i, n)) {
            ll const x = f(s, dp, i);
            if(x + 1 < res) res = x + 1;
        }
    }
    return dp[n] = res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    auto dp = new ll[s.size() + 1];
    dp[0] = 0;
    fill(dp + 1, dp + s.size() + 1, -1);
    cout << f(s, dp, s.size());
}