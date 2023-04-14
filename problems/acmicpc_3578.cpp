#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    if(n == 0) {
        cout << 1;
        return 0;
    }
    if(n == 1) {
        cout << 0;
        return 0;
    }
    if(n == 2) {
        cout << 8;
        return 0;
    }
    if(n & 1) {
        cout << 4;
        n--;
    }
    while(n) {
        cout << 8;
        n -= 2;
    }
}