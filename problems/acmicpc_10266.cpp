#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n << 1];
    auto b = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n); sort(b, b + n);
    for(int i = n; i < (n << 1); i++) a[i] = 360000 + a[i - n];
    auto da = new int[(n << 1) - 1];
    auto db = new int[n - 1];
    for(int i = 1; i < (n << 1); i++) da[i - 1] = a[i] - a[i - 1];
    for(int i = 1; i < n; i++) db[i - 1] = b[i] - b[i - 1];
    delete[] a; delete[] b;
    auto pi = new int[n - 1]();
    for(int i = 1, j = 0; i < n - 1; i++) {
        while(j && db[i] != db[j]) j = pi[j - 1];
        if(db[i] == db[j]) pi[i] = ++j;
    }
    for(int i = 0, j = 0; i < (n << 1) - 1; i++) {
        while(j && da[i] != db[j]) j = pi[j - 1];
        if(da[i] == db[j]) {
            if(j == n - 2) {
                cout << "possible";
                return 0;
            }
            j++;
        }
    }
    cout << "impossible";
}