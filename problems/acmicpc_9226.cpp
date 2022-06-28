#include <iostream>
#include <string>
using namespace std;
inline bool is_vowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; while(cin >> s) {
        if(s == "#") return 0;
        int i = 0;
        while(i < s.size()) {
            if(is_vowel(s[i])) break;
            i++;
        }
        if(i == s.size()) cout << s << "ay\n";
        else cout << s.substr(i) << s.substr(0, i) << "ay\n";
    }
}