#include <array>
#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto v = new array<int, 3>[n];
    auto res = new int[n]();
    for(int i = 0; i < n; i++) {
        for(auto &j : v[i]) cin >> j;
    }
    for(int i = 0; i < 3; i++) {
        map<int, int> m;
        for(int j = 0; j < n; j++) m[v[j][i]]++;
        for(int j = 0; j < n; j++) {
            res[j] += v[j][i] * (m[v[j][i]] == 1);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }
}