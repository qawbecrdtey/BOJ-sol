#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n; auto a = new int[n];
        cout << "Denominations:";
        for(int i = 0; i < n; i++) {
            cin >> a[i]; cout << ' ' << a[i];
        } cout << '\n';
        bool bad = false;
        for(int i = 1; i < n; i++) {
            if(a[i - 1] * 2 > a[i]) {
                bad = true; break;
            }
        } cout << (bad ? "Bad" : "Good");
        delete[] a;
        cout << " coin denominations!\n\n";
    }
}