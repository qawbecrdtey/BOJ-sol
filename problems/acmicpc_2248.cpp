#include <cassert>
#include <iostream>
using namespace std;
using ll = long long;
ll c(ll n, ll k) {
    static ll table[32][32] {};
    assert(0 <= n && n < 32);
    assert(0 <= k && k <= n);
    if(k < 0 || n < k) return 0;
    if(table[n][k]) return table[n][k];
    if(!k || n == k) return table[n][k] = 1;
    return table[n][k] = c(n - 1, k - 1) + c(n - 1, k);
}
ll cs(ll n, ll k) {
    static ll sum_table[32][32] {};
    assert(0 <= n && n < 32);
    assert(0 <= k && k <= n);
    if(sum_table[n][k]) return sum_table[n][k];
    if(!k) return sum_table[n][k] = 1;
    return sum_table[n][k] = c(n, k) + cs(n, k - 1);
}
ll find_number(ll n, ll l, ll i) {
    if(l >= n) return i;
    ll const val = cs(n - 1, l);
    cout << n << ' ' << l << ' ' << i << ' ' << val << endl;
    if(val > i) return find_number(n - 1, l, i);
    return (1 << (n - 1)) | find_number(n - 1, l - 1, i - val);
}
void print_binary(ll n, ll b) {
    ll const val = n & (1 << (b - 1));
    cout << (val >> (b - 1));
    if(b == 1) return;
    print_binary(n, b - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, l, i; cin >> n >> l >> i;
    print_binary(find_number(n, l, i - 1), n);
}
