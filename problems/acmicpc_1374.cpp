#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        int x; cin >> x >> a[i].first >> a[i].second;
    } sort(a, a + n);
    priority_queue<int> q;
    for(int i = 0; i < n; i++) {
        if(q.empty() || -q.top() > a[i].first) {
            q.push(-a[i].second);
            continue;
        } q.pop(); q.push(-a[i].second);
    } cout << q.size();
}