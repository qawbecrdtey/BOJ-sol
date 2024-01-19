#pragma GCC optimize("O3")
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
struct uf {
    int *const root;
    int const n;
    explicit uf(int x) : n(x), root(new int[x]) {
        for(int i = 0; i < n; i++) root[i] = i;
    }
    ~uf() { delete[] root; }
    [[nodiscard]] int find(int a) {
        if(root[a] == a) return a;
        return root[a] = find(root[a]);
    }
    bool merge(int a, int b) {
        int x = find(a);
        int y = find(b);
        if(x == y) return false;
        root[y] = x;
        return true;
    }
    [[nodiscard]] bool check(int a, int b) {
        return find(a) == find(b);
    }
    [[nodiscard]] bool is_root(int a) {
        return a == find(a);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    auto a = new int[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    uf u(n + 1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        u.merge(x, y);
    }
    auto mc = new int[n + 1]();
    auto mp = new long long[n + 1]();
    for(int i = 1; i <= n; i++) {
        auto const idx = u.find(i);
        mp[idx] += a[i];
        mc[idx]++;
    }
    auto prev = new long long[k];
    auto now = new long long[k];
    prev[0] = 0;
    fill(prev + 1, prev + k, -1LL);
    for(int key = 1; key <= n; key++) {
        if(!mc[key]) continue;
        copy(prev, prev + k, now);
        for(int i = mc[key]; i < k; i++) {
            if(prev[i - mc[key]] != -1 && now[i] < prev[i - mc[key]] + mp[key]) now[i] = prev[i - mc[key]] + mp[key];
        }
        swap(prev, now);
    }
    cout << *max_element(prev, prev + k);
}