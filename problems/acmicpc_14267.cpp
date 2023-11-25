#include <iostream>
#include <vector>
using namespace std;
void update(vector<int> const *v, int *const praise, int const now, int const val) {
    praise[now] += val;
    for(auto next : v[now]) {
        update(v, praise, next, praise[now]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto v = new vector<int>[n + 1];
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(i == 1) continue;
        v[x].push_back(i);
    }
    auto praise = new int[n + 1]();
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        praise[x] += y;
    }
    update(v, praise, 1, 0);
    for(int i = 1; i <= n; i++) {
        cout << praise[i] << ' ';
    }
}