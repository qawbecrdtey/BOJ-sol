#include <iostream>
using namespace std;
inline char c(bool b) {
    if(b) return '.'; return '*';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new bool[m];
    for(int i = 0; i < m; i++) {
        a[i] = (i & 1);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << c((i & 1) ^ a[j]);
        } cout << '\n';
    }
}