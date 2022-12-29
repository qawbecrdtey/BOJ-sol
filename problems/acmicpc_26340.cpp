#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a[2], n; cin >> a[0] >> a[1] >> n;
        cout << "Data set: " << a[0] << ' ' << a[1] << ' ' << n << '\n';
        while(n--) {
            if(a[0] > a[1]) a[0] >>= 1;
            else a[1] >>= 1;
        } sort(a, a + 2);
        cout << a[1] << ' ' << a[0] << '\n' << '\n';
    }
}