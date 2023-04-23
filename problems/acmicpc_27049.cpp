#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int res = 0;
    int prob;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '?' && s[i] != 'X') res += (10 - i) * (s[i] - '0');
        else if(s[i] == 'X') {
            if(i != s.size() - 1) {
                cout << -1;
                return 0;
            }
            res += (10 - i) * 10;
        }
        else prob = i;
    }
    for(int i = 0; i < 10; i++) {
        if((10 - prob) * i % 11 == ((11 - res) % 11 + 11) % 11) {
            cout << i;
            return 0;
        }
    }
    if(prob == s.size() - 1) {
        if(10 == ((11 - res) % 11 + 11) % 11) {
            cout << 'X';
            return 0;
        }
    }
    cout << -1;
}