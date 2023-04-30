#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        int n, cnt{}; cin >> n; while(n--) {
            string s; cin >> s; cnt += (s == "sheep");
        } cout << "Case " << tt << ": This list contains " << cnt << " sheep.\n\n";
    }
}