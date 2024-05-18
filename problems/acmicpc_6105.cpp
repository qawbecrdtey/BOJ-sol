#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    priority_queue<pair<int, int>> pq;
    auto res = new int[n]();
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        while(!pq.empty() && -pq.top().first < x) {
            res[pq.top().second] = i + 1;
            pq.pop();
        }
        pq.push({-x, i});
    }
    for(int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }
}
