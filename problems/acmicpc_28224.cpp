#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, s{}; cin >> n; while(n--) { int x; cin >> x; s += x; } cout << s;
}