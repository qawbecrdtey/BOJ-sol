#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int c = 0, i; string res;
    for(i = 0; i < s.size() && i < t.size(); i++) {
        int const x = (s[i] - '0') + (t[i] - '0') + c;
        res.push_back((x % 10) + '0');
        c = x / 10;
    }
    for(; i < s.size(); i++) {
        int const x = s[i] - '0' + c;
        res.push_back((x % 10) + '0');
        c = x / 10;
    }
    for(; i < t.size(); i++) {
        int const x = t[i] - '0' + c;
        res.push_back(x % 10 + '0');
        c = x / 10;
    }
    if(c) res.push_back('1');
    reverse(res.begin(), res.end());
    cout << res;
}