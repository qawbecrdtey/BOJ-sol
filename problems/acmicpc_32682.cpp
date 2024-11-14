#include <iostream>
using namespace std;
bool is_odd(int n) noexcept { return n & 1; }
bool is_square(int n) {
    for(int i = 0; i * i <= n; i++) {
        if(i * i == n) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        bool const o = is_odd(n);
        bool const s = is_square(n);
        if(o && s) cout << "OS\n";
        else if(o) cout << "O\n";
        else if(s) cout << "S\n";
        else cout << "EMPTY\n";
    }
}
