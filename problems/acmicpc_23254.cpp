#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    auto a = new int[m];
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
        int x; cin >> x; pq.emplace(min(x, 100 - a[i]), a[i]);
    }
    delete[] a;
    n *= 24;
    int hundred = 0;
    long long res = 0;
    while(!pq.empty() && n) {
        auto [up, cur] = pq.top(); pq.pop();
        if(up == 0) {
            res += cur;
            continue;
        }
        int const elapsed = min((100 - cur) / up, n);
        cur += elapsed * up;
        n -= elapsed;
        if(cur == 100) {
            hundred++;
            continue;
        }
        pq.emplace(100 - cur, cur);
    }
    res += hundred * 100;
    while(!pq.empty()) {
        auto const [up, cur] = pq.top(); pq.pop();
        res += cur;
    }
    cout << res;
}