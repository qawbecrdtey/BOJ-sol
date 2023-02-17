#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s; cout << [&s](){ for(int i = 0; i < s.size() / 2; i++) if(s[i] != s[s.size() - i - 1]) return "NO"; return "YES"; }();
}