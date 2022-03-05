#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, t; cin >> s >> t;
    auto a = new int*[s.size() + 1];
    for(int i = 0; i <= s.size(); i++) a[i] = new int[t.size() + 1]();
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j <= t.size(); j++) {
            a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            if(s[i - 1] == t[j - 1]) {
                a[i][j] = max(a[i][j], a[i - 1][j - 1] + 1);
            }
        }
    }
    cout << a[s.size()][t.size()];
}