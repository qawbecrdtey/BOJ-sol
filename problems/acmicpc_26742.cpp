#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int B{}, C{};
    for(char c : s) {
        B += (c == 'B');
        C += (c == 'C');
    } cout << B / 2 + C / 2;
}