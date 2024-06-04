#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        string res = s;
        for(int i = 0; i < s.size(); i++) {
            s = s.substr(1) + s.substr(0, 1);
            if(res > s) res = s;
        }
        cout << res << '\n';
    }
}
