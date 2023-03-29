#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int cnt[4]{};
    int res = 0;
    for(char c : s) {
        switch(c) {
            case 'q':
                cnt[0]++;
                res = max(res, cnt[0]);
                break;
            case 'u':
                if(cnt[0] <= cnt[1]) {
                    cout << -1;
                    return 0;
                }
                cnt[1]++;
                res = max(res, cnt[1]);
                break;
            case 'a':
                if(cnt[1] <= cnt[2]) {
                    cout << -1;
                    return 0;
                }
                cnt[2]++;
                res = max(res, cnt[2]);
                break;
            case 'c':
                if(cnt[2] <= cnt[3]) {
                    cout << -1;
                    return 0;
                }
                cnt[3]++;
                res = max(res, cnt[3]);
                break;
            case 'k':
                if(!cnt[3]) {
                    cout << -1;
                    return 0;
                }
                cnt[0]--;
                cnt[1]--;
                cnt[2]--;
                cnt[3]--;
                break;
            default: __builtin_unreachable();
        }
        if(cnt[0] < cnt[1] || cnt[1] < cnt[2] || cnt[2] < cnt[3]) {
            cout << -1;
            return 0;
        }
    }
    if(cnt[0] || cnt[1] || cnt[2] || cnt[3]) {
        cout << -1;
        return 0;
    }
    cout << res;
}