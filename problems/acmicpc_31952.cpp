#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto b = new int[m];
    for(int j = 0; j < m; j++) cin >> b[j];
    for(int i = 0; i < n; i++) {
        if(a[i] == b[0]) {
            auto c = new int[n];
            copy(a + i, a + n, c);
            copy(a, a + i, c + n - i);
            copy(c, c + n, a);
            delete[] c;
            goto NEXT1;
        }
    }
    cout << 0;
    return 0;
NEXT1:
    for(int i = 0; i < m; i++) {
        if(a[i] != b[i]) {
            goto NEXT2;
        }
    }
    cout << 1;
    return 0;
NEXT2:
    reverse(a + 1, a + n);
    for(int i = 0; i < m; i++) {
        if(a[i] != b[i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
