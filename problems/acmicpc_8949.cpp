#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string add(string const &s, string const &t) {
    string res;
    int i = 0;
    while(i < s.size() && i < t.size()) {
        int const x = s[i] - '0';
        int const y = t[i] - '0';
        res.push_back((char)((x + y) % 10 + '0'));
        if(x + y > 9) res.push_back('1');
        i++;
    }
    while(i < s.size()) res.push_back(s[i++]);
    while(i < t.size()) res.push_back(t[i++]);
    return res;
}
int main() {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    auto res = add(s, t);
    reverse(res.begin(), res.end());
    cout << res;
}