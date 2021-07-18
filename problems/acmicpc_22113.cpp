#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    auto a = new int[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    auto b = new int*[n + 1];
    for(int i = 1; i <= n; i++) {
        b[i] = new int[n + 1];
        for(int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    long long res = 0;
    for(int i = 1; i < m; i++) {
        res += b[a[i - 1]][a[i]];
    }
    cout << res;
    for(int i = 1; i <= n; i++) {
        delete[] b[i];
    } delete[] b;
    delete[] a;
}