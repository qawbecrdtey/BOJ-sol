#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if((x <= 1 && y <= 2) || (x <= 2 && y <= 1)) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
}