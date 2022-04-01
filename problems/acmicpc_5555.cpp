#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; int n; cin >> s >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        string t; cin >> t; t += t;
        for(int j = 0; j < t.size() - s.size() + 1; j++) {
            bool flag = true;
            for(int k = 0; k < s.size(); k++) {
                if(t[j + k] != s[k]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cnt++; break;
            }
        }
    } cout << cnt;
}