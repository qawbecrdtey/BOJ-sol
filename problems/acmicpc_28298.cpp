#include <algorithm>
#include <array>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    auto a = new array<int, 26>*[k];
    for(int i = 0; i < k; i++) {
        a[i] = new array<int, 26>[k];
        for(int j = 0; j < k; j++) {
            fill(a[i][j].begin(), a[i][j].end(), 0);
        }
    }
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            a[i % k][j % k][s[j] - 'A']++;
        }
    }
    int res = n * m;
    auto resarr = new char*[k];
    for(int i = 0; i < k; i++) {
        resarr[i] = new char[k];
        for(int j = 0; j < k; j++) {
            auto const p = max_element(a[i][j].begin(), a[i][j].end());
            resarr[i][j] = (char)(p - a[i][j].begin() + 'A');
            res -= *p;
        }
    }
    cout << res;
    for(int i = 0; i < n; i++) {
        cout << '\n';
        for(int j = 0; j < m; j++) {
            cout << resarr[i % k][j % k];
        }
    }
}