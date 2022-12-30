#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; cout << "Gnomes:"; while(t--) {
        int a, b, c; cin >> a >> b >> c;
        if((a < b && b < c) || (a > b && b > c)) cout << "\nOrdered";
        else cout << "\nUnordered";
    }
}