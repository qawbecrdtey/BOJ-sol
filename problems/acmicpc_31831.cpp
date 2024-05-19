#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int a = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a += x;
        if(a < 0) a = 0;
        res += (a >= m);
    } cout << res;
}
