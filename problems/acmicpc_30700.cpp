#include <iostream>
#include <string>
using namespace std;
static constexpr char str[] = "KOREA";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int idx = 0;
    for(char c : s) {
        if(c == str[idx % 5]) idx++;
    } cout << idx;
}