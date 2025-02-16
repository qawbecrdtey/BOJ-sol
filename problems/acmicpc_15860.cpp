#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << "1\n" << flush;
    while(true) {
        int x; cin >> x;
        if(x == 99) return 0;
        if(x % 3) cout << (x = (x + 3) / 3 * 3) << '\n' << flush;
        else cout << (x = (x + rand() % 2 + 1)) << '\n' << flush;
        if(x == 99) return 0;
    }
}
