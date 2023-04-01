#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, t; while(cin >> s >> t) {
        int i = 0;
        for(char c : t) {
            if(i == s.size()) break;
            if(c == s[i]) i++;
        } if(i == s.size()) cout << "Yes\n"; else cout << "No\n";
    }
}