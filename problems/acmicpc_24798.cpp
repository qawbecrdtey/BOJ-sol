#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int l, w; cin >> l >> w;
    if(w < l || l * 26 < w) { cout << "impossible"; return 0; }
    while(l) {
        int const x = w / l;
        cout << static_cast<char>('a' - 1 + x);
        w -= x;
        l--;
    }
}
