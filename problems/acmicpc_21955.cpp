#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    cout << s.substr(0, s.size() / 2) << ' ' << s.substr(s.size() / 2);
}