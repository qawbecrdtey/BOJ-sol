#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; cin >> s;
    bool sign = (s[0] == '-');
    int idx = sign, start = sign;
    while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9') idx++;
    string t = s.substr(start, idx - start);
    if(t.empty()) t = "1";
    int coef = stoi(t);
    if(sign) coef = -coef;
    if(idx < s.size() && s[idx] == 'x') cout << coef;
    else cout << 0;
}