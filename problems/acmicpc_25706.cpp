#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto res = new int[n];
    for(int i = n - 1; i >= 0; i--) {
        if(i + + 1 + a[i] >= n) {
            res[i] = 1;
            continue;
        }
        res[i] = res[i + 1 + a[i]] + 1;
    }
    for(int i = 0; i < n; i++) cout << res[i] << ' ';
}
