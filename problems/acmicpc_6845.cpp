#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a, b, c; cin >> a >> b >> c;
        if(a > 1989 || (a == 1989 && (b > 2 || (b == 2 && c > 27)))) cout << "No\n";
        else cout << "Yes\n";
    }
}
