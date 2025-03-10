#include <iostream>
using namespace std;
bool all_zero(int const *const a, int const n) {
    for(int i = 0; i < n; i++) {
        if(a[i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    while(!all_zero(a, n)) {
        for(int i = 0; i < n; i++) {
            if(a[i] & 1) { a[i] ^= 1; cnt++; }
        }
        if(all_zero(a, n)) goto E;
        for(int i = 0; i < n; i++) {
            a[i] >>= 1;
        }
        cnt++;
    }
E:  cout << cnt;
}
