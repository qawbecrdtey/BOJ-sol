#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int q; cin >> q;
    int cur = 0;
    while(q--) {
        int a, x; cin >> a >> x;
        if(a == 1) cur += x;
        else cur -= x;
        if(cur < 0) {
            cout << "Adios";
            return 0;
        }
    }
    cout << "See you next month";
}
