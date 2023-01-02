#include <iostream>
#include <string>
using namespace std;
inline bool is_palindrome(string const &s) {
    for(int i = 0; (i << 1) <= s.size(); i++) {
        if(s[i] != s[s.size() - i - 1]) return false;
    } return true;
}
inline bool has_distinct_characters(string const &s) {
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[0]) return true;
    } return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    if(!is_palindrome(s)) {
        cout << s.size();
    } else if(has_distinct_characters(s)) {
        cout << s.size() - 1;
    } else cout << -1;
}