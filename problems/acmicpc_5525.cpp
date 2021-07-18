#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, l;
    string s;
    cin >> n >> l >> s;
    int cnt = 0;
    int res = 0;
    for(int i = 0; i < l - 1;) {
        if(cnt < n) {
            if(s[i] == 'I' && s[i + 1] == 'O') {
                cnt++; i += 2;
                continue;
            }
            cnt = 0;
            i++;
            continue;
        }
        if(s[i] == 'I') {
            res++;
            if(s[i + 1] == 'O') {
                i += 2;
                continue;
            }
            cnt = 0;
            i++;
            continue;
        }
        cnt = 0;
        i++;
    }
    printf("%d", res);
}