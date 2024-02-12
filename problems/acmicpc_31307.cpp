#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, h; cin >> n >> h;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0, sum = 0;
    for(res = 0; res < n; res++) {
        if(sum + a[res] > h * 5) break;
        sum += a[res];
    }
    cout << res;
}