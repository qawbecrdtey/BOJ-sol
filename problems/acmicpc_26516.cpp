#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; while(cin >> s) {
        if(s == "0") return 0;
        int res = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[res] < s[i]) res = i;
        } if((s[res] - '0') & 1) s[res] = '0'; else s[res] = static_cast<char>((s[res] - '0' + 4) % 10 + '0');
        while(s.size() > 1 && s[0] == '0') s = s.substr(1);
        cout << s << '\n';
    }
}