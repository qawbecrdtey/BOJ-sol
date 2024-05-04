#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new bool*[n];
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = new bool[n];
        for(int j = 0; j < n; j++) {
            a[i][j] = (s[j] == 'H');
        }
    }
    int result = n * n;
    for(int i = 0; i < (1 << n); i++) {
        int res = 0;
        auto b = new bool*[n];
        for(int j = 0; j < n; j++) {
            b[j] = new bool[n];
            copy(a[j], a[j] + n, b[j]);
        }
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                for(int k = 0; k < n; k++) {
                    b[j][k] = !b[j][k];
                }
            }
        }
        for(int j = 0; j < n; j++) {
            int sum = 0;
            for(int k = 0; k < n; k++) {
                sum += b[k][j];
            }
            if(sum < (n >> 1)) res += sum;
            else res += (n - sum);
        }
        if(result > res) result = res;
        for(int j = 0; j < n; j++) {
            delete[] b[j];
        }
        delete[] b;
    }
    cout << result;
}
