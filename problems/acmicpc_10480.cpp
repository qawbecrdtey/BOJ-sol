#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int x; cin >> x; cout << x << " is " << (x % 2 ? "odd\n" : "even\n");
    }
}