#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    if(n == 1) { cout << 0; return 0; }
    auto a = new string*[n];
    map<string, pair<int, int>> mp;
    for(int i = 0; i < n; i++) {
        a[i] = new string[n];
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            mp[a[i][j]] = {i, j};
        }
    }
    auto row = new int[n](); row[n / 2] = 1;
    auto col = new int[n](); col[n / 2] = 1;
    int diagu = 1, diagd = 1;
    for(int i = 1; i <= m; i++) {
        string s; cin >> s;
        if(auto const it = mp.find(s); it != mp.end()) {
            if(it->second.first == n / 2 && it->second.second == n / 2) continue;
            if(++row[it->second.first] == n) { cout << i; return 0; }
            if(++col[it->second.second] == n) { cout << i; return 0; }
            if(it->second.first == it->second.second) {
                if(++diagd == n) { cout << i; return 0; }
            }
            if(it->second.first == n - 1 - it->second.second) {
                if(++diagu == n) { cout << i; return 0; }
            }
        }
    }
    cout << ":-(";
}
