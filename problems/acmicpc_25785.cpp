#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    auto const is_vowel = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
    for(int i = 1; i < s.size(); i++) {
        if(is_vowel(s[i]) == is_vowel(s[i - 1])) {
            cout << 0;
            return 0;
        }
    } cout << 1;
}