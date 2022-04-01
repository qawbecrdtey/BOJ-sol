#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        cout << n << ' ';
        int a[2]{ 1, 1 };
        int cnt = 1;
        while(a[0] != 0 || a[1] != 1) {
            int tmp = a[0];
            a[0] = a[1];
            a[1] = (tmp + a[1]) % m;
            cnt++;
        } cout << cnt << '\n';
    }
}