#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; while(getline(cin, s)) {
        for(char c : s) {
            switch(c) {
                case 'e': cout << 'i'; break;
                case 'i': cout << 'e'; break;
                case 'E': cout << 'I'; break;
                case 'I': cout << 'E'; break;
                default: cout << c; break;
            }
        } cout << '\n';
    }
}