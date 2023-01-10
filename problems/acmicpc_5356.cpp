#include <iostream>
using namespace std;
inline void next(char &c) { c -= 'A'; c++; c %= 26; c += 'A'; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; char c; cin >> n >> c;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                cout << c;
            } next(c); cout << '\n';
        } cout << '\n';
    }
}