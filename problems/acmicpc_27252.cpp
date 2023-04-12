#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int height = 0, h = 0;
    for(char c : s) {
        h += (c == '(');
        h -= (c == ')');
        height = max(height, h);
    }
    auto a = new char*[height];
    for(int i = 0; i < height; i++) {
        a[i] = new char[s.size() + 1];
        fill(a[i], a[i] + s.size(), '.');
        a[i][s.size()] = '\0';
    }
    h = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            a[h][i] = '/';
            h++;
        }
        else {
            h--;
            a[h][i] = '\\';
        }
    }
    for(int i = height - 1; i >= 0; i--) {
        cout << a[i] << '\n';
    }
}