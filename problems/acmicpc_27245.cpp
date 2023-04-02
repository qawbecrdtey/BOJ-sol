#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int w, l, h; cin >> w >> l >> h;
    cout << ((min(w, l) >= 2 * h && max(w, l) <= 2 * min(w, l)) ? "good" : "bad");
}