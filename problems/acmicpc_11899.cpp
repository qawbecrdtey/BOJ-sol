#include <cassert>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int cur = 0, res = 0;
    for(char c : s) {
        if(c == ')') cur--;
        else cur++;
        if(cur < 0) res++, cur++;
        assert(cur >= 0);
    }
    cout << res + cur;
}