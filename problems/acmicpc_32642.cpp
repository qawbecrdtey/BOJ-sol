#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; long long s = 0, cur = 0; while(n--) {
        int x; cin >> x; cur += (x << 1) - 1; s += cur;
    } cout << s;
}
