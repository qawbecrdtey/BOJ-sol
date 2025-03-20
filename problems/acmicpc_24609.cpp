#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; int m = 0, cur = 0; while(n--) {
        int x; cin >> x; cur += x; m = min(m, cur);
    }
    cout << (m < 0 ? -m : 0);
}
