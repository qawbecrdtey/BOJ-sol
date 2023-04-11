#include <array>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new array<bool, 26>[n]{{}}; bool b[26]{};
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b[s[0] - 'A'] = true;
        for (char c: s) a[i][c - 'A'] = true;
    }
    for(int i = 0; i < n; i++) {
        bool flag = false;
        for(int j = 0; j < 26; j++) {
            if(a[i][j] && !b[j]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << 'Y';
            return 0;
        }
    } cout << 'N';
}