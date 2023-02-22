#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new pair<int, int>[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first < a[i].second) swap(a[i].first, a[i].second);
    }
    sort(a, a + m);
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(*lower_bound(a, a + m, make_pair(i, j)) == make_pair(i, j)) continue;
            for(int k = 1; k < j; k++) {
                if(*lower_bound(a, a + m, make_pair(i, k)) == make_pair(i, k)) continue;
                if(*lower_bound(a, a + m, make_pair(j, k)) == make_pair(j, k)) continue;
                res++;
            }
        }
    } cout << res;
}