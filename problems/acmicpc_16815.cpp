#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; cin >> s;
    int res = 0;
    for(char c : s) {
        if(c == '*') { cout << res; return 0; }
        if(c == '(') res++;
        else res--;
    }
}
