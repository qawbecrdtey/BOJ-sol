#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    uint64_t x, y; cin >> x >> y;
    uint64_t res = 0;
    for(int i = 0; i < 32; i++) {
        res <<= 2;
        res |= (((x >> (31 - i)) & 1) << 1);
        res |= ((y >> (31 - i)) & 1);
    } cout << res;
}