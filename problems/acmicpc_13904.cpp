#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct comp {
    bool operator()(pair<int, int> const &a, pair<int, int> const &b) const {
        return a.second > b.second;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    int res{};
    for(int i = 0; i < n; i++) {
        if(pq.size() >= a[i].first) {
            if(a[i].second > pq.top().second) {
                res -= pq.top().second; pq.pop();
                res += a[i].second; pq.push(a[i]);
            } continue;
        } res += a[i].second; pq.push(a[i]);
    } cout << res;
}