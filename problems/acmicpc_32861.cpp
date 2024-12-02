#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int*[n];
    auto sum = new int[n]();
    for(int i = 0; i < n; i++) {
        a[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
        sum[i] = n - (sum[i] + n - 1) / 2;
    }
    for(int i = 0; i < n; i++) {
        if(a[i][i] != 0) goto NO;
        for(int j = i + 1; j < n; j++) {
            if(a[i][j] == 0 || a[i][j] != -a[j][i]) goto NO;
        }
    }
    for(int i = 0; i < n; i++) {
        if(sum[i] > n || sum[i] <= 0) goto NO;
        for(int j = i + 1; j < n; j++) {
            if(sum[i] == sum[j]) goto NO;
        }
    }
    for(int i = 0; i < n; i++) cout << sum[i] << ' ';
    return 0;
NO: cout << -1;
}
