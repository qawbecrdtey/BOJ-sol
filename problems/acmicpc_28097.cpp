#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, x{}; cin >> n; for(int i = 0; i < n; i++) {
        int y; cin >> y; x += y;
    } x = x + (n - 1) * 8; cout << x / 24 << ' ' << x % 24;
}