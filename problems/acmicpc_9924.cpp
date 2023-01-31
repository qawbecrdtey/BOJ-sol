#include <iostream>
using namespace std;
int ecd(int a, int b) {
    if(a == b) return 0;
    return 1 + ecd(max(a, b) - min(a, b), min(a, b));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b; cin >> a >> b;
    cout << ecd(a, b);
}