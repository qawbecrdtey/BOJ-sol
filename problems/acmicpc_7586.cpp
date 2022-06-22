#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[4]; while(true) {
        for(int &i : a) cin >> i;
        if(!a[0] && !a[1] && !a[2] && !a[3]) return 0;
        switch((!a[0]) | ((!a[1]) << 1) | ((!a[2]) << 2) | ((!a[3]) << 3)) {
            case 1: a[0] = a[3] / a[2] / a[1]; break;
            case 2: a[1] = a[3] / a[2] / a[0]; break;
            case 4: a[2] = a[3] / a[1] / a[0]; break;
            case 8: a[3] = a[0] * a[1] * a[2]; break;
            default: __builtin_unreachable();
        } for(int const &i : a) cout << i << ' '; cout << '\n';
    }
}