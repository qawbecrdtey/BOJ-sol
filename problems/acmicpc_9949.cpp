#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    char c1[2], c2[2]; int tt = 1; while(cin >> c1 >> c2) {
        if(*c1 == '#' && *c2 == '#') return 0;
        cout << "Case " << tt++ << '\n';
        int n; cin >> n;
        while(n--) {
            string s; getline(cin, s); if(s.empty()) { n++; continue; }
            for(char c : s) {
                if(c != *c1 && c != *c2 && c != 'A' + *c1 - 'a' && c != 'A' + *c2 - 'a') cout << c;
                else cout << '_';
            } cout << '\n';
        } cout << '\n';
    }
}