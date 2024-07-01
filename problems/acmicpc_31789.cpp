#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, x, s; cin >> n >> x >> s;
    while(n--) {
        int a, b; cin >> a >> b;
        if(a > x || s >= b) continue;
        cout << "YES";
        return 0;
    }
    cout << "NO";
}
