#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    if(n & 1) {
        cout << (n + 1) / 2 << '\n';
        for(int i = 0; i < n / 2; i++) {
            cout << 'o';
            for(int j = 0; j < n / 2; j++) cout << '.';
            cout << '\n';
        }
        for(int i = 0; i <= n / 2; i++) cout << 'o';
        return 0;
    }
    if(n == 2) {
        cout << -1;
        return 0;
    }
    cout << n / 2 << '\n';
    for(int i = 2; i < n / 2; i++) {
        cout << 'o';
        for(int j = 1; j < n / 2; j++) cout << '.';
        cout << '\n';
    }
    cout << "oo";
    for(int i = 2; i < n / 2; i++) cout << '.';
    cout << '\n';
    for(int i = 0; i < n / 2; i++) cout << 'o';
}
