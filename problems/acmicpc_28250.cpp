#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    long long a[3]{};
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x < 2) a[x]++;
        else a[2]++;
    }
    cout << 2 * a[0] * a[1] + a[0] * (a[0] - 1) / 2 + a[0] * a[2];
}