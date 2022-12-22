#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
inline int change(char c) {
    if(c == 'A') return 1;
    if(c >= '2' && c <= '9') return c - '0';
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    __builtin_unreachable();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s[5]; int choose[14]{};
        for(auto &st : s) {
            cin >> st; choose[change(st[0])]++;
        } cout << *max_element(choose + 1, choose + 14) << '\n';
    }
}