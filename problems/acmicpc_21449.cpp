#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        while(m % (x + 1) == 0) x++, res++;
    }
    cout << res;
}
