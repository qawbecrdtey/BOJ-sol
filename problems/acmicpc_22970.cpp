#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1;
    for(int i = 0; i < n; i++) {
        int len = 1;
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(a[j] >= a[j + 1]) {
                len += i - j - 1;
                break;
            }
        } if(j == -1) len += i;
        for(j = i; j < n - 1; j++) {
            if(a[j] <= a[j + 1]) {
                len += j - i;
                break;
            }
        } if(j == n - 1) len += j - i;
        res = max(res, len);
    } cout << res;
}