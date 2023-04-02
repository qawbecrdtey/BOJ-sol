#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s; int a[26]{};
        bool flag = true;
        for(int i = 0; i < s.size(); i++) {
            a[s[i] - 'A']++;
            if(a[s[i] - 'A'] % 4 == 3) {
                if(i == s.size() - 1 || s[i + 1] != s[i]) {
                    cout << "FAKE\n";
                    flag = false;
                    break;
                }
            }
        } if(flag) cout << "OK\n";
    }
}