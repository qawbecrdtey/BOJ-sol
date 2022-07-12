#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int l = 0, r = 0;
    int n; cin >> n; while(n--) {
        int x, y; cin >> x >> y;
        if(x > y) l += x + y;
        else if(x < y) r += x + y;
        else l += x, r += y;
    } cout << l << '\n' << r;
}