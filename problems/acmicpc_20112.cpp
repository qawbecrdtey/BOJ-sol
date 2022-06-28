#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto s = new string[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(s[i][j] != s[j][i]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}