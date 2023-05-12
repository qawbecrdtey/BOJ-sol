#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m; auto a = new pair<int, int>[m]();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >> x; a[j].first -= x;
        }
    }
    for(int i = 0; i < m; i++) a[i].second = i + 1;
    sort(a, a + m);
    for(int i = 0; i < m; i++) cout << a[i].second << ' ';
}