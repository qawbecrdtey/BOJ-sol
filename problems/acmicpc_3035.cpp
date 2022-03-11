#include <iostream>
#include <string>
using namespace std;
inline void print(string const &s, int zr, int zc) {
    for (int i = 0; i < zr; i++) {
        for(auto c : s) {
            for (int j = 0; j < zc; j++) cout << c;
        }
        if (i != zr - 1) cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    for(int i = 0; i < r; i++) {
        string s; cin >> s;
        print(s, zr, zc);
        if(i != r - 1) cout << '\n';
    }
}