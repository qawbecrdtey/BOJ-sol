#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            if(t[i] == 'R') {
                cout << 'P';
                continue;
            }
            if(t[i] == 'P') {
                cout << 'P';
                continue;
            }
            cout << 'R';
            continue;
        }
        if(s[i] == 'P') {
            if(t[i] == 'R') {
                cout << 'P';
                continue;
            }
            if(t[i] == 'P') {
                cout << 'S';
                continue;
            }
            cout << 'S';
            continue;
        }
        if(t[i] == 'R') {
            cout << 'R';
            continue;
        }
        if(t[i] == 'P') {
            cout << 'S';
            continue;
        }
        cout << 'R';
    }
}