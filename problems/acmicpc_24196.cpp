#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int idx = 0;
    while(idx < s.size()) {
        cout << s[idx];
        idx += s[idx] - 'A' + 1;
    }
}