#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int k, n; cin >> n >> k;
    auto a = new int[n << 1];
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i + n] = a[i];
    }
    int res = 0, sum = 0;
    for(int i = 0; i < k; i++) {
        sum += a[i];
    } res = sum;
    for(int i = k; i < n + k; i++) {
        sum += a[i] - a[i - k];
        if(res < sum) res = sum;
    } cout << res;
}