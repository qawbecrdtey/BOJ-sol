#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int a[1001]{};
    for(int i = 0; i < n; i++) {
        int x; cin >> x; a[x]++;
    }
    int res = 0;
    for(int i = 1; i <= 1000; i++) {
        res += min(a[i], 2);
    } cout << res;
}