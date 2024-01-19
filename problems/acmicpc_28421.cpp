#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    auto a = new int[n + 1];
    int mp[100001]{};
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if(n == 1) {
        while(q--) {
            int x, y; cin >> x >> y;
            if(x == 1) cout << "0\n";
        }
        return 0;
    }
    while(q--) {
        int x, y; cin >> x >> y;
        switch(x) {
            case 1: {
                if(!y) {
                    cout << (mp[0] != 0) << '\n';
                    goto END;
                }
                else {
                    for(int i = max(y / 10000, 1); i * i <= y; i++) {
                        if(y % i) continue;
                        if(!mp[i] || !mp[y / i]) continue;
                        if(i * i == y && mp[i] < 2) continue;
                        cout << "1\n";
                        goto END;
                    }
                }
                cout << "0\n";
                END:
                break;
            }
            case 2: {
                mp[a[y]]--;
                mp[0]++;
                a[y] = 0;
            } break;
            default: __builtin_unreachable();
        }
    }
}