#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new string[n];
    auto label = new int*[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        label[i] = new int[m];
        fill(label[i], label[i] + m, -1);
    }
    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '-') {
                if(!j || a[i][j - 1] == '|') {
                    label[i][j] = ++idx;
                }
                else label[i][j] = label[i][j - 1];
            }
            else {
                if(!i || a[i - 1][j] == '-') {
                    label[i][j] = ++idx;
                }
                else label[i][j] = label[i - 1][j];
            }
        }
    }
    cout << idx;
}
