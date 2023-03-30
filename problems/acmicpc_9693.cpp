#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int t = 1;; t++) {
        int n; cin >> n; if(!n) return 0;
        cout << "Case #" << t << ": ";
        int res = 0;
        while(n / 5) {
            res += n / 5;
            n /= 5;
        } cout << res << '\n';
    }
}