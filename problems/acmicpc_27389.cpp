#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; cout << (n >> 2);
    switch(n & 3) {
        case 0: break;
        case 1: cout << ".25"; break;
        case 2: cout << ".5"; break;
        case 3: cout << ".75"; break;
        default: __builtin_unreachable();
    }
}