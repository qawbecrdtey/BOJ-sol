#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t, x, n; cin >> t >> x >> n;
    for(int i = 0; i < n; i++) {
        int m; cin >> m;
        bool flag = false;
        while(m--) {
            int y; cin >> y; if(y == x) flag = true;
        }
        if(!flag) { cout << "NO"; return 0; }
    }
    cout << "YES";
}
