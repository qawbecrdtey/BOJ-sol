#include <iostream>
using namespace std;
struct uf {
    int const n;
    int *const root;
    uf(int n) : n(n), root(new int[n + 1]) {
        for(int i = 1; i <= n; i++) {
            root[i] = i;
        }
    }
    ~uf() { delete[] root; }
    int find(int a) {
        if(a == root[a]) return a;
        return root[a] = find(root[a]);
    }
    bool merge(int a, int b) {
        int x = find(a);
        int y = find(b);
        if(x == y) return false;
        root[x] = y;
        return true;
    }
    bool check(int a, int b) {
        return find(a) == find(b);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    uf u(n);
    int cnt = 0;
    int res = 0;
    while(m--) {
        int a, b; cin >> a >> b;
        if(!u.merge(a, b)) { res++; continue; }
        else cnt++;
    }
    cout << res + (n - 1 - cnt);
}
