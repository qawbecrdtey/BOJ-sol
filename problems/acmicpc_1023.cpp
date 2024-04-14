#include <array>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;
static constexpr array<ll, 26> catalan = []() {
    array<ll, 26> catalan{};
    catalan[0] = 1;
    catalan[1] = 1;
    for(int i = 2; i < 26; i++) {
        catalan[i] = 0;
        for(int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    return catalan;
}();
// dp[i][j]
// length i
// #')' - #'(' = j -> #')' = (i + j) / 2, #'(' = (i - j) / 2
static constexpr array<array<ll, 51>, 51> dp = []() {
    array<array<ll, 51>, 51> dp{};
    for(int i = 0; i <= 50; i++) {
        for(int j = 0; j <= 50; j++) {
            dp[i][j] = 0;
            if(i < j) continue;
            if((i ^ j) & 1) continue;
            if(i == j) {
                dp[i][j] = 1;
                continue;
            }
            for(int k = 0; k <= j; k++) { // k = #')' at the beginning
                for(int l = 1; l * 2 <= i - k; l++) { // correct sequence of length 2 * l
                    dp[i][j] += catalan[l - 1] * dp[i - k - l * 2][j - k];
                }
            }
        }
    }
    return dp;
}();
void g(ll n, ll k, string &res) {
    for(ll j = n - 1; j >= 0; j--) res += (((k >> j) & 1) ? ')' : '(');
}
void f(ll n, ll k, ll c, string &res) {
    if(!k || c < 0) {
        g(n, k, res);
        return;
    }
    if(k < (1LL << (n - 1)) - dp[n - 1][c + 1]) {
        res += '(';
        f(n - 1, k, c + 1, res);
        return;
    }
    // k > (1LL << (n - 1)) dp[n - 1][c + 1]
    res += ')';
    f(n - 1, k - (1LL << (n - 1)) + dp[n - 1][c + 1], c - 1, res);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; cin >> n >> k;
    if(n & 1) {
        for(ll j = n - 1; j >= 0; j--) cout << (((k >> j) & 1) ? ')' : '(');
        return 0;
    }
    if(k >= (1LL << n) - catalan[n >> 1]) {
        cout << -1;
        return 0;
    }
    string res;
    f(n, k, 0, res);
    cout << res;
}