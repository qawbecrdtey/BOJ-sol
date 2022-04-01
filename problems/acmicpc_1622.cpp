#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, t;
    while(getline(cin, s) && getline(cin, t)) {
        int a[26]{}, b[26]{};
        for(char c : s) a[c - 'a']++;
        for(char c : t) b[c - 'a']++;
        for(int i = 0; i < 26; i++) {
            while(a[i] && b[i]) {
                cout << (char)('a' + i);
                a[i]--; b[i]--;
            }
        } cout << '\n';
    }
}