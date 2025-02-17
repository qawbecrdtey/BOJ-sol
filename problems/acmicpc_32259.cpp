#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int lo = 1, hi = n + 1;
    while(hi - lo > 1) {
        char c[2];
        if(hi - lo == 2) {
            cout << "? " << lo << " 0 " << lo + 1 << " 0\n" << flush;
            cin >> c;
            if(*c == '<') { cout << "! " << lo; return 0; }
            else { cout << "! " << lo + 1; return 0; }
        }
        int const x = (hi - lo + 1) / 3;
        cout << "? ";
        for(int i = 0; i < x; i++) {
            cout << lo + i << ' ';
        }
        cout << "0 ";
        for(int i = 0; i < x; i++) {
            cout << lo + x + i << ' ';
        }
        cout << "0\n" << flush;
        cin >> c;
        if(*c == '<') hi = lo + x;
        else if(*c == '>') { hi = lo + (x << 1); lo += x; }
        else lo += (x << 1);
    }
    if(hi - lo == 1) {
        cout << "! " << lo;
        return 0;
    }
}
