#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int x = 0;
    for(int i = 0; i < 26; i++) {
        x += 'A' + i;
    } for(char c : s) {
        x -= c;
    } cout << static_cast<char>(x);
}