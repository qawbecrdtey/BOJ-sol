#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int x; cin >> x;
        if(x > 4500) cout << "Round 1\n";
        else if(x > 1000) cout << "Round 2\n";
        else if(x > 25) cout << "Round 3\n";
        else cout << "World Finals\n";
    }
}