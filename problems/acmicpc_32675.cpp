#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n + 2]();
    a[0] = 1 % m;
    int res = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            res += (a[j] == 0);
        }
        for(int j = i + 1; j > 0; j--) {
            a[j] = (a[j] + a[j - 1]) % m;
        }
    }
    cout << res;
}
