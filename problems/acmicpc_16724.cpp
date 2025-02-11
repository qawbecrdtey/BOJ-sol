#include <iostream>
#include <set>
using namespace std;
struct uf {
    int const n;
    int *const root;
    uf(int n) : n(n), root(new int[n]) {
        for(int i = 0; i < n; i++) root[i] = i;
    }
    ~uf() { delete[] root; }
    int find(int a) {
        if(root[a] == a) return a;
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
    auto a = new char*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new char[m + 1];
        cin >> a[i];
    }
    uf u(n * m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int const val = i * m + j;
            switch(a[i][j]) {
                case 'U': u.merge(val, (i - 1) * m + j); break;
                case 'D': u.merge(val, (i + 1) * m + j); break;
                case 'L': u.merge(val, i * m + (j - 1)); break;
                case 'R': u.merge(val, i * m + (j + 1)); break;
                default: __builtin_unreachable();
            }
        }
    }
    set<int> s;
    for(int i = 0; i < n * m; i++) {
        s.insert(u.find(i));
    }
    cout << s.size();
}
