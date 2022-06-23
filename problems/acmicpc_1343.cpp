#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int i = 0;
    while(i < s.size()) {
        if(s[i] == '.') { i++; continue; }
        if(i < s.size() - 3 && s[i] == 'X' && s[i + 1] == 'X' && s[i + 2] == 'X' && s[i + 3] == 'X') {
            s[i] = s[i + 1] = s[i + 2] = s[i + 3] = 'A';
            i += 4;
            continue;
        }
        if(i < s.size() - 1 && s[i] == 'X' && s[i + 1] == 'X') {
            s[i] = s[i + 1] = 'B';
            i += 2;
            continue;
        }
        cout << "-1";
        return 0;
    } cout << s;
}