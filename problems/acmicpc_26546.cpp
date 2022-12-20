#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; int st, en; cin >> s >> st >> en;
        for(int i = 0; i < s.size(); i++) {
            if(st <= i && i < en) continue;
            cout << s[i];
        } cout << '\n';
    }
}