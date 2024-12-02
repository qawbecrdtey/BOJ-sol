#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[10], b[10]; for(int &i : a) cin >> i; for(int i = 0; i < 10; i++) b[a[i]] = i;
    string s, t; cin >> s >> t;
    for(char &c : s) c = '0' + b[c - '0'];
    for(char &c : t) c = '0' + b[c - '0'];
    unsigned long long val = stoull(s) + stoull(t);
    string res;
    while(val) {
        res += static_cast<char>('0' + a[val % 10]);
        val /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}
