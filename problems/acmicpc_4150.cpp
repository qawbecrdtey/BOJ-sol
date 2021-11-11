#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string add(string const &a, string const &b) {
    string res;
    int c = 0, i;
    for(i = 0; i < a.size() && i < b.size(); i++) {
        int x = (a[i] - '0') + (b[i] - '0') + c;
        c = x / 10;
        res.push_back((char)(x - c * 10 + '0'));
    }
    while(i < a.size()) {
        int x = (a[i] - '0') + c;
        c = x / 10;
        res.push_back((char)(x - c * 10 + '0'));
        i++;
    }
    while(i < b.size()) {
        int x = (b[i] - '0') + c;
        c = x / 10;
        res.push_back((char)(x - c * 10 + '0'));
        i++;
    }
    if(c) res.push_back('1');
    return res;
}
int main() {
    int n; cin >> n;
    string a, b, c;
    a = "0", b = "1", c = "1";
    for(int i = 1; i < n; i++) {
        c = add(a, b);
        a = b; b = c;
    }
    reverse(c.begin(), c.end());
    cout << c;
}