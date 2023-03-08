#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n + 1];
    for(int i = 1; i <= n; i++) a[i] = i;
    while(m--) {
        int x, y; cin >> x >> y;
        reverse(a + x, a + y + 1);
    } for(int i = 1; i <= n; i++) cout << a[i] << ' ';
}