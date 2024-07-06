#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int m; cin >> m;
    int res = 0;
    for(int i = 0; i < m; i++) {
        int x; cin >> x; res ^= x;
    }
    cout << (res ? "koosaga" : "cubelover");
}