#include <iostream>
using namespace std;
inline void remove_mat(int **a, int n) {
    for(int i = 0; i < n; i++) delete[] a[i];
    delete[] a;
}
inline int **mul(int **a, int **b, int n, int m) {
    auto res = new int*[n];
    for(int i = 0; i < n; i++) {
        res[i] = new int[n]();
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % m) % m;
            }
        }
    } return res;
}
int **power(int **a, int n, int m, int p) {
    if(!p) {
        auto res = new int*[n];
        for(int i = 0; i < n; i++) {
            res[i] = new int[n]();
            res[i][i] = 1;
        } return res;
    }
    if(p == 1) {
        auto res = new int*[n];
        for(int i = 0; i < n; i++) {
            res[i] = new int[n];
            copy(a[i], a[i] + n, res[i]);
        } return res;
    }
    auto r = power(a, n, m, p >> 1);
    auto mat = mul(r, r, n, m);
    remove_mat(r, n);
    if(p & 1) {
        auto tmp = mul(mat, a, n, m);
        remove_mat(mat, n);
        mat = tmp;
    }
    return mat;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, p; // n * n, mod m, power
    while(cin >> n >> m >> p) {
        if(!n && !m && !p) return 0;
        auto a = new int*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new int[n];
            for(int j = 0; j < n; j++) {
                cin >> a[i][j]; a[i][j] = (a[i][j] % m + m) % m;
            }
        }
        auto res = power(a, n, m, p);
        remove_mat(a, n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << res[i][j] << ' ';
            } cout << '\n';
        } cout << '\n';
        remove_mat(res, n);
    }
}