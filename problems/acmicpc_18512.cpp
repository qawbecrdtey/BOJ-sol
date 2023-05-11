#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int x, y, n, m; cin >> x >> y >> n >> m;
    bool a[50000]{};
    for(int i = 0; i <= 100; i++) {
        a[n + x * i] = true;
    }
    for(int i = 0; i <= 100; i++) {
        if(a[m + y * i]) { cout << m + y * i; return 0; }
    } cout << -1;
}