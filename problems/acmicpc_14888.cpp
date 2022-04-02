#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int op[4];
    for(int &i : op) cin >> i;
    int min = 1000000000, max = -1000000000;
    for(int i = 0; i < (1 << ((n - 1) << 1)); i++) {
        int cp[4]{};
        for(int j = 1; j < n; j++) cp[(i >> ((n - j - 1) << 1)) & 3]++;
        bool flag = true;
        for(int j = 0; j < 4; j++) {
            if(op[j] != cp[j]) {
                flag = false;
                break;
            }
        } if(!flag) continue;
        int res = a[0];
        for(int j = 1; j < n; j++) {
            switch((i >> ((n - j - 1) << 1)) & 3) {
                case 0: res += a[j]; break;
                case 1: res -= a[j]; break;
                case 2: res *= a[j]; break;
                case 3: res /= a[j]; break;
                default: __builtin_unreachable();
            }
        }
        if(max < res) max = res;
        if(min > res) min = res;
    } cout << max << '\n' << min;
}