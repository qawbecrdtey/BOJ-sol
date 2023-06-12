#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 2; i < n; i++) if(a[i] - a[i - 1] != a[1] - a[0]) { cout << "NO"; return 0; }
    cout << "YES\n"; for(int i = 0; i < n; i++) cout << "0 "; cout << '\n'; for(int i = 0; i < n; i++) cout << a[i] << ' ';
}