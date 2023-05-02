#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int g, c, e; cin >> g >> c >> e;
        if(e < c) cout << "0\n";
        else cout << (e - c) * (g * 2 - 1) << '\n';
    }
}