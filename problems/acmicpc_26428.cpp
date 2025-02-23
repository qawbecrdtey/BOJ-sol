#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct info {
    string color;
    int durability;
    int uid;
};
bool cmp1(info const &lhs, info const &rhs) {
    return lhs.color < rhs.color || (lhs.color == rhs.color && lhs.uid < rhs.uid);
}
bool cmp2(info const &lhs, info const &rhs) {
    return lhs.durability < rhs.durability || (lhs.durability == rhs.durability && lhs.uid < rhs.uid);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n; cin >> n;
        auto a = new info[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i].color >> a[i].durability >> a[i].uid;
        }
        auto b = new info[n];
        copy(a, a + n, b);
        sort(a, a + n, cmp1);
        sort(b, b + n, cmp2);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += a[i].uid == b[i].uid;
        }
        cout << cnt << '\n';
        delete[] a;
        delete[] b;
    }
}
