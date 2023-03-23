#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int res[4] = {0, 10000, 0, 10000};
    int t; cin >> t; while(t--) {
        int a[4]; for(int &i : a) cin >> i;
        res[0] = max(res[0], a[0]);
        res[1] = min(res[1], a[1]);
        res[2] = max(res[2], a[2]);
        res[3] = min(res[3], a[3]);
    }
    if(res[1] <= res[0] || res[3] <= res[2]) cout << 0;
    else cout << (res[1] - res[0]) * (res[3] - res[2]);
}