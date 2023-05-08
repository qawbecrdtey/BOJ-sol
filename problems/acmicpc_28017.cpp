#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto dp = new int[m]();
    auto in = new int[m]();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> in[j];
        auto arr = new int[m]();
        int minidx = 0, min2idx = -1;
        for(int j = 1; j < m; j++) {
            if(dp[j] <= dp[minidx]) minidx = j;
        }
        for(int j = 0; j < m; j++) {
            if(j != minidx && (min2idx == -1 || dp[j] <= dp[min2idx])) min2idx = j;
        }
        for(int j = 0; j < m; j++) {
            if(j == minidx) arr[j] = dp[min2idx] + in[j];
            else arr[j] = dp[minidx] + in[j];
        }
        swap(dp, arr);
        delete[] arr;
    } cout << *min_element(dp, dp + m);
}