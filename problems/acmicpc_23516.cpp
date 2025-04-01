#include <iostream>
#include <string>
using namespace std;
static bool divisor(string const &s, string const &t) {
    if(s.size() % t.size()) return false;
    for(int i = static_cast<int>(t.size()); i < s.size(); i++) {
        if(s[i] != t[i % t.size()]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, t; cin >> s >> t;
    for(int i = 0; i < s.size() && i < t.size(); i++) {
        if(s[i] != t[i]) { cout << "No solution"; return 0; }
        string const ss = s.substr(0, i + 1);
        if(divisor(s, ss) && divisor(t, ss)) {
            cout << ss;
            return 0;
        }
    }
    cout << "No solution";
    return 0;
}
