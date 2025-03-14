#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        auto a = new int[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int res = a[n - 1] - a[0];
        for(int i = 1; i < n; i++) {
            res = min(res, a[i] - a[i - 1]);
        }
        cout << res << '\n';
        delete[] a;
    }
}
