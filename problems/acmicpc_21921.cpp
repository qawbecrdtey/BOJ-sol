#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, x; cin >> n >> x;
    int sum = 0, res = 0, cnt = 0;
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < x; i++) {
        sum += a[i];
    } res = sum; cnt = 1;
    for(int i = x; i < n; i++) {
        int xx = sum + a[i] - a[i - x];
        if(res < xx) {
            res = xx;
            cnt = 1;
        }
        else if(res == xx) {
            cnt++;
        }
        sum = xx;
    } if(!res) {
        cout << "SAD";
    } else cout << res << '\n' << cnt;
}