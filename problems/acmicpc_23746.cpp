#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; map<char, string> m;
    for(int i = 0; i < n; i++) {
        string s; char c[2]; cin >> s >> c;
        m[*c] = move(s);
    } string s, t; cin >> s;
    for(char c : s) t += m[c];
    int start, end; cin >> start >> end;
    for(int i = start - 1; i < end; i++) cout << t[i];
}