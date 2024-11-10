#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; int s = n; while(n--) {
        int x; cin >> x; s += x;
    } cout << s / 2 << '.' << ((s & 1) ? '5' : '0');
}
