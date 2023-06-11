#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    auto b = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    if(n == 1) {
        cout << (a[0] == b[0]);
        return 0;
    }
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) { flag = false; break; }
    } if(flag) { cout << 1; return 0; }
    for(int i = n; i > 1; i--) {
        auto p = max_element(a, a + i);
        if(p != a + i - 1) swap(*p, a[i - 1]);
        flag = true;
        for(int j = 0; j < n; j++) {
            if(a[j] != b[j]) { flag = false; break; }
        } if(flag) { cout << 1; return 0; }
    } cout << 0;
}