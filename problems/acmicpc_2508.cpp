#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        auto s = new string[n];
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 2; j < m; j++) {
                if(s[i][j - 2] == '>' && s[i][j - 1] == 'o' && s[i][j] == '<') {
                    cnt++;
                }
            }
        }
        for(int i = 2; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i - 2][j] == 'v' && s[i - 1][j] == 'o' && s[i][j] == '^') {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        delete[] s;
    }
}
