#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c = s[0];
    for(int i = 1; i < n; i++) {
        cin >> s;
        if(s[0] != c) {
            printf("0");
            return 0;
        }
    }
    printf("1");
}