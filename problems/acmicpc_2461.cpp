#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
using namespace std;
struct comp { bool operator()(int const *a, int const *b) const { return *a > *b; } };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    set<int*> s;
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        for(int j = 0; j < m; j++) cin >> a[i][j];
        sort(a[i], a[i] + m);
        s.insert(a[i] + m);
    }
    int max_val = 0;
    priority_queue<int*, vector<int*>, comp> min_pq;
    for(int i = 0; i < n; i++) {
        max_val = max(max_val, a[i][0]);
        min_pq.push(a[i]);
    }
    int res = numeric_limits<int>::max();
    while(true) {
        res = min(res, max_val - *min_pq.top());
        if(s.find(min_pq.top() + 1) != s.end()) break;
        auto p = min_pq.top(); min_pq.pop();
        min_pq.push(p + 1);
        max_val = max(max_val, *(p + 1));
    }
    cout << res;
}