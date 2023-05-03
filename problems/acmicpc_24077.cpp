#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    auto b = new int[m]; for(int i = 0; i < m; i++) cin >> b[i];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cnt += (a[i] <= b[j]);
        }
    } cout << cnt;
}