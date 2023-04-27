#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    int t; cin >> t; while(t--) {
        bool flag = true;
        int m; cin >> m; while(m--) {
            int x; cin >> x;
            for(int i = 0; i < n; i++) {
                if(x == a[i]) flag = false;
            }
        }
        cnt += flag;
    } cout << cnt;
}