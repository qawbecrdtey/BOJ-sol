#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int64_t x; while(cin >> x) {
        if(x == -1) return 0;
        uint32_t n = 0;
        for(int i = 0; i < 32; i++) {
            if((uint32_t)(x) & (1 << i)) {
                n |= 1 << (31 - i);
            }
        } cout << n << '\n';
    }
}