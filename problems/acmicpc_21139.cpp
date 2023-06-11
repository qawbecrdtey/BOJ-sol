#include <iostream>
#include <string>
using namespace std;
inline int f(string &&s) {
    int res = 0;
    for(char c : s) res = (res << 1) | (c == 'T');
    return res;
}
int bitcount(int n) {
    int cnt = 0;
    for(int i = 1; i != (1 << 16); i <<= 1) {
        cnt += !!(i & n);
    } return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = f(std::move(s));
    }
    int res = 0;
    for(int i = 0; i < (1 << k); i++) {
        int val = k;
        for(int j = 0; j < n; j++) {
            val = min(val, bitcount(a[j] ^ i));
        } res = max(res, val);
    } cout << res;
}