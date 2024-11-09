#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; string s; cin >> n >> s;
        while(true) {
            bool flag = false;
            for(int i = 0; i < n - 2; i++) {
                if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'B') {
                    s[i] = 'B';
                    s[i + 1] = 'A';
                    for(int j = i + 2; j < n - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    n--; s.pop_back();
                    flag = true;
                    break;
                }
            }
            if(!flag) break;
        }
        cout << s << '\n';
    }
}
