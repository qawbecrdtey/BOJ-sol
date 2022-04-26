#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while(true) {
        cin >> n;
        if(n == -1) return 0;
        int res = 0, before = 0;
        while(n--) {
            int x, y; cin >> x >> y;
            res += x * (y - before);
            before = y;
        } cout << res << " miles\n";
    }
}