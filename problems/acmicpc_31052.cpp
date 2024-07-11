#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    auto a = new int[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    while(q--) {
        int x, y, z; cin >> x >> y >> z; switch(x) {
            case 1: {
                a[y] = z;
            } break;
            case 2: {
                cout << abs(a[y] - a[z]) << '\n';
            } break;
            default: __builtin_unreachable();
        }
    }
}