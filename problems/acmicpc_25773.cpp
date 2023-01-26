#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s; sort(s.begin(), s.end(), [](char a, char b) { return a > b; });
    cout << s;
}