#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s; auto res = s.size();
    for(char c : s) {
        res += (c == ':');
        res += (c == '_') * 5;
    } cout << res;
}