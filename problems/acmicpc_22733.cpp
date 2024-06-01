#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        for(int i = 1, d = 3; i <= n; d += 2) {
            cout << i << '\n';
            i += d;
        }
        cout << '\n';
    }
}
