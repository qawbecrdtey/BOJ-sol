#include <iostream>
#include <string>
using namespace std;
string *unshuffle(int const *a, string const *str, int n) {
    auto res = new string[n + 1];
    for(int i = 1; i <= n; i++) {
        res[i] = str[a[i]];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    auto inv = new int[n + 1];
    for(int i = 1; i <= n; i++) inv[a[i]] = i;
    auto res = new string[n + 1];
    for(int i = 1; i <= n; i++) cin >> res[i];
    for(int i = 0; i < 3; i++) {
        auto tmp = unshuffle(a, res, n);
        delete[] res;
        res = tmp;
    }
    for(int i = 1; i <= n; i++) {
        cout << res[i] << '\n';
    }
}
