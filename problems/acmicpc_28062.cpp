#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, res = 0, m = 1001; bool odd = false; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x & 1) m = min(m, x), odd = !odd; res += x;
    } cout << (odd ? (res - m) : res);
}