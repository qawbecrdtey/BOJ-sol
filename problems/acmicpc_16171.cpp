#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, t; cin >> s >> t;
    string S;
    for(char c : s) {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) S.push_back(c);
    }
    for(int i = 0; i <= (int)S.size() - (int)t.size(); i++) {
        for(int j = 0; j < t.size(); j++) {
            if(S[i + j] != t[j]) goto CON;
        }
        cout << 1;
        return 0;
    CON:continue;
    } cout << 0;
}