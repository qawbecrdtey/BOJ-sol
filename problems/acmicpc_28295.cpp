#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int res = 0;
    for(int i = 0; i < 10; i++) { int x; cin >> x; res += x; }
    switch(res % 4) {
        case 0: cout << 'N'; break;
        case 1: cout << 'E'; break;
        case 2: cout << 'S'; break;
        case 3: cout << 'W'; break;
    }
}