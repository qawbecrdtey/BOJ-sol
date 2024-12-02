#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool flag = true;
            for(int k = i - 1; k >= 0; k--) {
                if(a[i][j] <= a[k][j]) { flag = false; break; }
            }
            cnt += flag;
            flag = true;
            for(int k = i + 1; k < n; k++) {
                if(a[i][j] <= a[k][j]) { flag = false; break; }
            }
            cnt += flag;
            flag = true;
            for(int k = j - 1; k >= 0; k--) {
                if(a[i][j] <= a[i][k]) { flag = false; break; }
            }
            cnt += flag;
            flag = true;
            for(int k = j + 1; k < m; k++) {
                if(a[i][j] <= a[i][k]) { flag = false; break; }
            }
            cnt += flag;
        }
    }
    cout << cnt;
}
