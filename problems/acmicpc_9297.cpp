#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        int a, b; cin >> a >> b;
        if(a / b) cout << a / b << ' ';
        if(a % b) cout << a % b << '/' << b;
        if(a == 0) cout << '0';
        cout << '\n';
    }
}