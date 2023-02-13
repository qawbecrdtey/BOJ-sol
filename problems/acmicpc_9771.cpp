#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s; string t; int res = 0; while(getline(cin, t)) {
        for(int i = 0; i < static_cast<int>(t.size()) - static_cast<int>(s.size()) + 1; i++) {
            int j;
            for(j = 0; j < s.size(); j++) {
                if(s[j] != t[i + j]) break;
            } res += (j == s.size());
        }
    } cout << res;
}