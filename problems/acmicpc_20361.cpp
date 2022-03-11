#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, k; cin >> n >> x >> k;
    auto a = new bool[n + 1](); a[x] = true;
    while(k--) {
        int c, d; cin >> c >> d;
        swap(a[c], a[d]);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i]) cout << i;
    }
}