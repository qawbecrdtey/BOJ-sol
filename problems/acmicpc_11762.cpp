#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int a[6], l, r; for(auto &i : a) cin >> i; cin >> l >> r;
    sort(a, a + 6);
    do {
        if(a[0] > a[1] && a[1] > a[2] && a[3] > a[4] && a[4] > a[5] && a[0] + a[1] + a[2] == l && a[3] + a[4] + a[5] == r) {
            cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << ' ' << a[4] << ' ' << a[5];
            return 0;
        }
    } while(next_permutation(a, a + 6));
}
