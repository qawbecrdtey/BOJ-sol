#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    sort(a, a + n);
    auto dp = new int[n];
    fill(dp, dp + n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(((a[j].first <= a[i].first && a[j].second <= a[i].second) || (a[j].second <= a[i].first && a[j].first <= a[i].second)) && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
    } cout << *max_element(dp, dp + n);
}