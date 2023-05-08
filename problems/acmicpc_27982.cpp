#include <algorithm>
#include <iostream>
using namespace std;
struct info {
    int x, y, z;
    bool operator<(info const &i) const { return x < i.x || (x == i.x && (y < i.y || (y == i.y && z < i.z))); }
};
inline bool find(info const *a, int m, int x, int y, int z) {
    return binary_search(a, a + m, info{x, y, z});
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new info[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    } sort(a, a + m);
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt += (find(a, m, a[i].x + 1, a[i].y, a[i].z) && find(a, m, a[i].x - 1, a[i].y, a[i].z) && find(a, m, a[i].x, a[i].y + 1, a[i].z) && find(a, m, a[i].x, a[i].y - 1, a[i].z) && find(a, m, a[i].x, a[i].y, a[i].z + 1) && find(a, m, a[i].x, a[i].y, a[i].z - 1));
    } cout << cnt;
}