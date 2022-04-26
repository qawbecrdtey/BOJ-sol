#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int key = s[0] ^ 'C';
    for(char c : s) {
        cout << (char)(c ^ key);
    }
}