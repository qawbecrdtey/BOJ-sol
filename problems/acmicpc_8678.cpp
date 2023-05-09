#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 2; i < n; i++) {
        if(a[i] != a[i - 1] && a[i - 1] != a[i - 2] && a[i - 2] != a[i]) {
            cout << "TAK";
            return 0;
        }
    } cout << "NIE";
}