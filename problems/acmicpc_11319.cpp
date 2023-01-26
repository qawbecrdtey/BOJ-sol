#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; getline(cin, s); if(s.empty()) { t++; continue; }
        int vo{}, co{};
        for(char c : s) {
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vo++;
            else if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) co++;
        } cout << co << ' ' << vo << '\n';
    }
}