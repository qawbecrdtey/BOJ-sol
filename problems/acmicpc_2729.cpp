#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int u; cin >> u; while(u--) {
        string s, t; cin >> s >> t;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int c = 0;
        string res;
        int i = 0;
        for(; i < s.size() && i < t.size(); i++) {
            int val = (int)s[i] + t[i] + c - '0' * 2;
            c = (val >> 1);
            res.push_back((char)('0' + (val & 1)));
        }
        for(; i < s.size(); i++) {
            int val = (int)s[i] + c - '0';
            c = (val >> 1);
            res.push_back((char)('0' + (val & 1)));
        }
        for(; i < t.size(); i++) {
            int val = (int)t[i] + c - '0';
            c = (val >> 1);
            res.push_back((char)('0' + (val & 1)));
        }
        if(c) res.push_back('1');
        while(!res.empty() && res.back() == '0') res.pop_back();
        if(res.empty()) res = "0";
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
}