#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    bool a[26]{}; string s; cin >> s;
    for(char c : s) a[c - 'A'] = true;
    cout << ((a['M' - 'A'] && a['O' - 'A'] && a['B' - 'A'] && a['I' - 'A'] && a['S' - 'A']) ? "YES" : "NO");
}