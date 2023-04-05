#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a1, a0, c, n0; cin >> a1 >> a0 >> c >> n0;
    if(a1 <= c) cout << (c * n0 >= a1 * n0 + a0);
    else cout << 0;
}