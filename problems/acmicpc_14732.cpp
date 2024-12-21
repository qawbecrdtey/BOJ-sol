#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    bool arr[500][500]{};
    while(n--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        for(int i = a; i < c; i++) {
            fill(arr[i] + b, arr[i] + d, true);
        }
    }
    int cnt = 0;
    for(auto const &a : arr) {
        for(auto const b : a) {
            cnt += b;
        }
    }
    cout << cnt;
}
