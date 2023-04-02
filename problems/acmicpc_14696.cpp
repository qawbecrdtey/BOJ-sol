#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a[5]{}, b[5]{};
        int n; cin >> n; while(n--) { int x; cin >> x; a[x]++; }
        cin >> n; while(n--) { int x; cin >> x; b[x]++; }
        if(a[4] == b[4] && a[3] == b[3] && a[2] == b[2] && a[1] == b[1]) cout << "D\n";
        else if(a[4] > b[4] || (a[4] == b[4] && (a[3] > b[3] || (a[3] == b[3] && (a[2] > b[2] || (a[2] == b[2] && (a[1] > b[1]))))))) cout << "A\n";
        else cout << "B\n";
    }
}