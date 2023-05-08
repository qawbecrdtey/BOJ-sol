#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int e, n; cin >> e >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x; cnt += (x > e);
        } cout << cnt << '\n';
    }
}