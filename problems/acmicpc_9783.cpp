#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; getline(cin, s);
    for(char c : s) {
        if(c >= 'a' && c <= 'z') printf("%02d", 1 + c - 'a');
        else if(c >= 'A' && c <= 'Z') printf("%d", 27 + c - 'A');
        else if(c >= '0' && c <= '9') printf("#%c", c);
        else printf("%c", c);
    }
}