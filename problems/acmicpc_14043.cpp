#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, t; cin >> s >> t;
    char a[26]{};
    for(char c : s) a[c - 'a']++;
    for(char c : t) {
        if(c == '*') continue;
        if(--a[c - 'a'] < 0) {
            cout << 'N';
            return 0;
        }
    }
    cout << 'A';
}
