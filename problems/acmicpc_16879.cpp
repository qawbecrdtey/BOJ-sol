#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int res = 0;
    while(n--) { int x, y; cin >> x >> y; res ^= ((x / 3) ^ (y / 3)) * 3 + (x + y) % 3; }
    cout << (res ? "koosaga" : "cubelover");
}