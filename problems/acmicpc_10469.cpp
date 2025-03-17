#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    char a[8][9]; for(auto &i : a) cin >> i;
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(a[i][j] != '*') continue;
            cnt++;
            for(int k = 0; k < 8; k++) {
                if(k != j && a[i][k] == '*') goto NO;
                if(k != i && a[k][j] == '*') goto NO;
                if(k != j && i + j - k >= 0 && i + j - k < 8 && a[i + j - k][k] == '*') goto NO;
                if(k != j && i - j + k >= 0 && i - j + k < 8 && a[i - j + k][k] == '*') goto NO;
            }
        }
    }
    if(cnt != 8) goto NO;
    cout << "valid";
    return 0;
NO: cout << "invalid";
}
