#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k, cnt{}; cin >> n >> k;
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            cnt += (a[i] + a[j] == k);
        }
    } cout << cnt;
}