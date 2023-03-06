#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b; cin >> n >> a >> b;
    if(a + b > n + 1) {
        cout << -1;
        return 0;
    }
    if(a == 1) {
        cout << b;
        for(int i = 1; i < n - b + 1; i++) cout << " 1";
        for(int i = n - b + 1; i < n; i++) cout << ' ' << n - i;
        return 0;
    }
    for(int i = 0; i < n - (a + b - 1); i++) cout << "1 ";
    for(int i = n - (a + b - 1); i < n - b; i++) cout << i - n + a + b << ' ';
    cout << max(a, b) << ' ';
    for(int i = n - b + 1; i < n; i++) cout << n - i << ' ';
}