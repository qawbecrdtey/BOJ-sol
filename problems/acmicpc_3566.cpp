#include <iostream>
inline int max(int a, int b) { return a > b ? a : b; }
using namespace std;
int main() {
    int a, b, c, d, n, min = 100000000;
    cin >> a >> b >> c >> d >> n;
    while(n--) {
        int v, w, x, y, z;
        cin >> v >> w >> x >> y >> z;
        int res = max((a - 1) / v + 1, (c - 1) / x + 1) * max((b - 1) / w + 1, (d - 1) / y + 1);
        int const val = max((a - 1) / w + 1, (c - 1) / y + 1) * max((b - 1) / v + 1, (d - 1) / x + 1);
        if(res > val) res = val;
        if(min > res * z) min = res * z;
    }
    cout << min;
}