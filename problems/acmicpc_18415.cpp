#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    for(int i = 0; i < n - 2; i++) {
        if(s[i] == 'j' && s[i + 1] == 'o' && s[i + 2] == 'i') s[i] = 'J', s[i + 1] = 'O', s[i + 2] = 'I';
    } cout << s;
}