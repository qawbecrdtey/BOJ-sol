#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, res; cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            res.push_back('(');
            continue;
        }
        if(s[i] == ')') {
            if(s[i - 1] == '(') {
                res.push_back('1');
            }
            res.push_back(')');
            if(i != s.size() - 1 && s[i + 1] == '(') {
                res.push_back('+');
            }
        }
    }
    cout << res;
}