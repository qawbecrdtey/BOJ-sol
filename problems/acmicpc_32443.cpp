#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int a[32] {};
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 0; j < 32; j++) a[j] += ((x >> j) & 1);
    }
    for(int i = 0; i < n; i++) {
        int res = 0;
        for(int j = 0; j < 32; j++) {
            if(a[j]) { res |= (1 << j); a[j]--; }
        }
        cout << res << ' ';
    }
}
