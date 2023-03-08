#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << "? 1" << endl;
        char c[2]; cin >> c;
        if(*c == 'Y') {
            cout << "! 1" << endl;
            return 0;
        }
    } __builtin_unreachable();
}