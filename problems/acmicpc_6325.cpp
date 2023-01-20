#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, t = 1; while(cin >> n) {
        if(!n) return 0;
        cout << "Program #" << t++ << '\n';
        bool a[26]{}; a[0] = true;
        for(int i = 0; i < n; i++) {
            char x[2], y[2], z[2]; cin >> x >> y >> z;
            a[*x - 'a'] = a[*z - 'a'];
        } bool flag = false; for(int i = 0; i < 26; i++) {
            if(a[i]) flag = true, cout << static_cast<char>(i + 'a') << ' ';
        } if(!flag) cout << "none";
        cout << "\n\n";
    }
}