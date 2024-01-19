#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<queue<int>> qs(k);
    for(int i = 0; i < n; i++) {
        qs[a[i] % k].push(a[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(qs[i % k].empty() || qs[i % k].front() > i) {
            cout << 0;
            return 0;
        }
        qs[i % k].pop();
    }
    cout << 1;
}