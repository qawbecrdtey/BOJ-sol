#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(n == 0) return 0;
        auto a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int res = 0;
        for(int i = 2; i < n; i++) {
            int const x = a[i] + a[i - 1] + a[i - 2];
            if(res < x) res = x;
        }
        cout << res << '\n';
        delete[] a;
    }
}
