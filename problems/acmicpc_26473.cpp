#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        auto a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int res = 1, cur = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] == a[i - 1] + 1) cur++;
            else {
                res = max(res, cur);
                cur = 1;
            }
        } res = max(res, cur);
        cout << res << '\n';
        delete[] a;
    }
}