#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n];
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; i++) {
        if(sum == a[i] * 2) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                cout << a[j] << ' ';
            }
            cout << a[i];
            return 0;
        }
    }
}
