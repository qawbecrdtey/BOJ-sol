#include <iostream>
using namespace std;
inline bool has_zero(int n) {
    while(n) {
        if(n % 10 == 0) return true;
        n /= 10;
    } return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        do {
            n++;
        } while(has_zero(n));
        cout << n << '\n';
    }
}