#include <iostream>
#include <string>
#include <type_traits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s[2]; cin >> s[0] >> s[1];
    auto const len = min(s[0].size(), s[1].size());
    for(remove_const_t<decltype(len)> i = 0; i < len; i++) {
        cout << s[i & 1][i];
    }
}