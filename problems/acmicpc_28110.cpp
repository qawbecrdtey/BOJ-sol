#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i]; sort(a, a + n);
    int res = -1, resx = -1;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i - 1] == 1) continue;
        int x = (a[i] + a[i - 1]) / 2;
        if(min(a[i] - x, x - a[i - 1]) == min(a[i] - x + 1, x - 1 - a[i - 1])) x--;
        int v = min(a[i] - x, x - a[i - 1]);
        if(v > res) res = v, resx = x;
    } cout << resx;
}