#include <iostream>
#include <vector>
using namespace std;
long long sum(vector<int> const *v, int now, int prev, int depth) {
    bool flag = false;
    long long res = 0;
    for(int next : v[now]) {
        if(prev == next) continue;
        res += sum(v, next, now, depth + 1);
        flag = true;
    }
    if(!flag) return depth;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto v = new vector<int>[n + 1];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << ((sum(v, 1, -1, 0) & 1) ? "Yes" : "No");
}