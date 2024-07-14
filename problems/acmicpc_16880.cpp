#include <iostream>
using namespace std;
inline int king(int x, int y) noexcept {
    if(x > y) swap(x, y);
    if((x >> 1) == (y >> 1)) return (x & 1) + (y & 1);
    switch((x & 1) + ((y & 1) << 1)) {
        case 0: return 0;
        case 1: return 3;
        case 2: return 1;
        case 3: return 2;
        default: __builtin_unreachable();
    }
}
inline int night(int x, int y) noexcept {
    if(x > y) swap(x, y);
    y -= x / 3 * 3;
    x %= 3;
    if(y > 3) return x;
    if(y > 1) return x > 0;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int res = 0;
    while(n--) {
        int x, y; char c[2]; cin >> x >> y >> c;
        switch(*c) {
            case 'B': res ^= min(x, y); break;
            case 'K': res ^= king(x, y); break;
            case 'N': res ^= night(x, y); break;
            case 'P': res ^= ((x / 3) ^ (y / 3)) * 3 + (x + y) % 3; break;
            case 'R': res ^= x ^ y; break;
            default: __builtin_unreachable();
        }
    }
    cout << (res ? "koosaga" : "cubelover");
}