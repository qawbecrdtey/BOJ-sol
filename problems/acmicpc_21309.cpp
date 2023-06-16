#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int first{}, second{};
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            first += (a[i][j] && a[i - 1][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            first += (a[i][j] && a[i][j - 1]);
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            second += (a[i][j] && a[i - 1][j - 1]);
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            second += (a[i][j] && a[i - 1][j + 1]);
        }
    } cout << first << ' ' << first + second;
}