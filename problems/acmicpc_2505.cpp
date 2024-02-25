#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int const *flipped_iterate(int const *a, int fl, int fr, int idx) {
    if(fl <= idx && idx <= fr) return a + (fr + fl - idx);
    return a + idx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const a = new int[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    while(l <= n && a[l] == l) l++;
    while(l <= r && a[r] == r) r--;
    if(r < l) {
        cout << "1 1\n1 1";
        return 0;
    }
    for(int i = l; i <= r; i++) {
        if(a[i] != l) continue;
        reverse(a + l, a + i + 1);
        for(int j = l; j <= r; j++) {
            int k;
            for(k = l; k <= r; k++) {
                if(*flipped_iterate(a, j, r, k) != k) break;
            }
            if(k == r + 1) {
                cout << l << ' ' << i << '\n' << j << ' ' << r;
                return 0;
            }
            for(k = l; k <= r; k++) {
                if(*flipped_iterate(a, l, j, k) != k) break;
            }
            if(k == r + 1) {
                cout << l << ' ' << i << '\n' << l << ' ' << j;
                return 0;
            }
        }
        reverse(a + l, a + i + 1);
        break;
    }
    for(int i = r; i >= l; i--) {
        if(a[i] != r) continue;
        reverse(a + i, a + r + 1);
        for(int j = l; j <= r; j++) {
            int k;
            for(k = l; k <= r; k++) {
                if(*flipped_iterate(a, j, r, k) != k) break;
            }
            if(k == r + 1) {
                cout << i << ' ' << r << '\n' << j << ' ' << r;
                return 0;
            }
            for(k = l; k <= r; k++) {
                if(*flipped_iterate(a, l, j, k) != k) break;
            }
            if(k == r + 1) {
                cout << i << ' ' << r << '\n' << l << ' ' << j;
                return 0;
            }
        }
        reverse(a + i, a + r + 1);
        break;
    }
    reverse(a + l, a + r + 1);
    for(int i = l; i <= r; i++) {
        if(a[i] <= i) continue;
        for(int j = l; j <= r; j++) {
            if(*flipped_iterate(a, i, a[i], j) != j) continue;
        }
        cout << l << ' ' << r << '\n' << i << ' ' << a[i];
        return 0;
    }
    __builtin_unreachable();
}