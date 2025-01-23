#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, h, w; cin >> n >> h >> w;
    auto a = new char*[h];
    for(int i = 0; i < h; i++) {
        a[i] = new char[w * n + 1];
        cin >> a[i];
    }
    auto res = new char[n + 1];
    fill(res, res + n, '?');
    res[n] = '\0';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < h; j++) {
            for(int k = 0; k < w; k++) {
                if(a[j][i * w + k] != '?') {
                    res[i] = a[j][i * w + k];
                    goto NXT;
                }
            }
        }
NXT:    continue;
    }
    cout << res;
}
