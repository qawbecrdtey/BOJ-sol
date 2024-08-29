#include <iostream>
#include <string>
using namespace std;
static constexpr int M = 10007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int cnt = 0;
    auto a = new int*[s.size() + 1];
    for(int l = 1; l <= s.size(); l++) {
        a[l] = new int[s.size() - l + 1];
        if(l == 1) {
            fill(a[1], a[1] + s.size(), 1);
            continue;
        }
        if(l == 2) {
            for(int i = 0; i <= s.size() - 2; i++) {
                a[2][i] = 2 + (s[i] == s[i + 1]);
            }
            continue;
        }
        for(int i = 0; i <= s.size() - l; i++) {
            a[l][i] = (M + a[l - 1][i] + a[l - 1][i + 1] - (s[i] != s[i + l - 1]) * a[l - 2][i + 1] + (s[i] == s[i + l - 1])) % M;
        }
    }
    cout << a[s.size()][0];
}
