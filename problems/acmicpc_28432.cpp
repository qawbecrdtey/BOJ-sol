#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new string[n];
    set<string> s;
    int idx;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == "?") idx = i;
        s.insert(a[i]);
    }
    int m; cin >> m;
    auto b = new string[m];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if(n == 1) {
        for(int i = 0; i < m; i++) {
            if(auto it = s.find(b[i]); it != s.end()) continue;
            cout << b[i];
            return 0;
        }
    }
    if(!idx) {
        for(int i = 0; i < m; i++) {
            if(b[i][b[i].size() - 1] != a[1][0]) continue;
            if(auto it = s.find(b[i]); it != s.end()) continue;
            cout << b[i];
            return 0;
        }
    }
    if(idx == n - 1) {
        for(int i = 0; i < m; i++) {
            if(b[i][0] != a[n - 2][a[n - 2].size() - 1]) continue;
            if(auto it = s.find(b[i]); it != s.end()) continue;
            cout << b[i];
            return 0;
        }
    }
    for(int i = 0; i < m; i++) {
        if(b[i][0] != a[idx - 1][a[idx - 1].size() - 1] || b[i][b[i].size() - 1] != a[idx + 1][0]) continue;
        if(auto it = s.find(b[i]); it != s.end()) continue;
        cout << b[i];
        return 0;
    }
}
